#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll l, r;

ll cal(ll n){
	ll ans = 0;
	ll l = 0, r = 1e9, mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(mid * mid <= n) l = mid;
		else r = mid - 1;
	}
	ans += l;
	l = 0, r = 1e9, mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(mid * mid + mid <= n) l = mid;
		else r = mid - 1;
	}
	ans += l;
	l = 0, r = 1e9, mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(mid * mid + mid * 2 <= n) l = mid;
		else r = mid - 1;
	}
	ans += l;
	return ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", cal(r) - cal(l - 1));
	}
}