#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n;
int a[maxn];
ll k, sum;
int b[maxn];

inline ll cal(int i, int x){
	return a[i] - 1ll * 3 * x * x + 3 * x - 1;
}

inline ll B(int i, ll val){
	int l = 0, r = a[i], mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(cal(i, mid) < val) r = mid - 1;
		else l = mid;
	}
	return l;
}

inline ll check(ll val){
	sum = 0;
	for(int i = 1;i <= n;i++) sum += b[i] = B(i, val);
	return sum;
}

int main(){
	scanf("%d%lld", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	ll l = -4e18, r = 4e18, mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(check(mid) >= k) l = mid;
		else r = mid - 1;
	}
	check(l);
	for(int i = 1;i <= n && sum > k;i++) if(cal(i, b[i]) == l) --sum, --b[i];
	for(int i = 1;i <= n;i++) printf("%d ", b[i]);
}