#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

const int bit = log2(maxn);

struct BIT{
	ll a[maxn];
	
	inline void add(int x, int y){
		for(;x < maxn;x += x & -x) a[x] += y;
	}
	
	inline ll query(int x){
		ll sum = 0;
		for(;x;x -= x & -x) sum += a[x];
		return sum;
	}
	
	inline int kth(int k){
		int sum = 0, ans = 0;
		for(int i = 1 << bit;i;i >>= 1){
			if(ans + i < maxn && sum + a[ans + i] < k) ans += i, sum += a[ans];
		}
		return ans + 1;
	}
}a, b;

int n;
int p[maxn];
int x, y, z;
ll sum;

inline ll cal(int x){
	if(x <= 0) return 0;
	return 1ll * x * (x + 1) / 2;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &x), p[x] = i;
	for(int i = 1;i <= n;i++){
		a.add(p[i], 1), b.add(p[i], p[i]);
		sum += i - a.query(p[i]);
		x = a.kth((i + 1) / 2);
		y = a.query(x), z = i - a.query(x);
		//printf("%d %d %d %d %d--\n", i, x, y, z, sum);
		ll ans = 1ll * x * y - b.query(x) - cal(y - 1);
		ans += b.query(n) - b.query(x) - 1ll * x * z - cal(z);
		printf("%lld ", sum + ans);
	}
}