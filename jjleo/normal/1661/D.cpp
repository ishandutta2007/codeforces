#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

struct BIT{
	ll a[maxn];
	
	inline void add(int x, ll y){
		for(;x < maxn;x += x & -x) a[x] += y;
	}
	
	inline void add(int l, int r, ll x){
		add(l, x), add(r + 1, -x);
	}
	
	inline ll query(int x){
		ll sum = 0;
		for(;x;x -= x & -x) sum += a[x];
		return sum;
	}
}b[2];

int n, k;
ll a[maxn];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	ll ans = 0;
	for(int i = n;i > k;i--){
		ll x = -b[0].query(i) + i * b[1].query(i);
		ll cnt = max(0ll, (a[i] - x + k - 1) / k);
		ans += cnt;
		b[0].add(i - k + 1, i, cnt * (i - k));
		b[1].add(i - k + 1, i, cnt);
	}
	ll sum = 0;
	for(int i = 1;i <= k;i++){
		ll x = -b[0].query(i) + i * b[1].query(i);
		sum = max(sum, max(0ll, (a[i] - x + i - 1) / i));
	}
	ans += sum;
	printf("%lld", ans);
}