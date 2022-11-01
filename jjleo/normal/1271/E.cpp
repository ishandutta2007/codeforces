#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll; 

ll n, k;
ll ans;

inline ll cal(ll x){
	ll sum = 1;
	if(!(x & 1)) sum = 0, x >>= 1;
	ll y = 0;
	while((x << 1) <= n) x <<= 1, y++, sum += min(1ll << y, n - x + 1);
	/*while(x <= n && y){
		sum += min(n - x + 1, (1ll << (y - 1)) - 1);
		x += 1ll << (y - 1);
		y--;
	}*/
	return sum;
}

int main(){
	scanf("%lld%lld", &n, &k);
	//for(int i = 1;i <= n;i++) printf("%d %d--\n", i, cal(i));
	ll l = 1, r = (n + 1) / 2, mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(cal(2 * mid - 1) >= k) l = mid;
		else r = mid - 1; 
	}
	ans = 2 * l - 1;
	l = 1, r = (n + 1) / 2;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(cal(2 * mid) >= k) l = mid;
		else r = mid - 1; 
	}
	if(cal(2 * l) >= k) ans = max(ans, 2 * l);
	printf("%lld", ans);
}