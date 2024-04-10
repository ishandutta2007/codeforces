#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int T;
ll h, c, t;
long double ans1;
ll ans2;

inline long double cal(ll x){
	return fabs(((long double)1.0 * h * x + (long double)1.0 * c * (x - 1)) / (long double)(2 * x - 1) - t);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld%lld", &h, &c, &t);
		ans1 = fabs((long double)(h + c) / 2.0 - t), ans2 = 2;
		ll l = 1, r = 1e12, mid;
		while(l < r){
			mid = l + r >> 1;
			if(h * mid + c * (mid - 1) <= t * (2 * mid - 1)) r = mid;
			else l = mid + 1;
		}
		//printf("%lld--\n", abs(h * l + c * (l - 1) - t * (2 * l - 1)) * 2);
		if(l == 1 || abs(h * l + c * (l - 1) - t * (2 * l - 1)) * (2 * l - 3) < abs(h * (l - 1) + c * (l - 2) - t * (2 * l - 3)) * (2 * l - 1)){
			if(abs(h * l + c * (l - 1) - t * (2 * l - 1)) * 2 < abs(h + c - t * 2) * (2 * l - 1)){
				printf("%lld\n", l * 2 - 1); 
			}else{
				puts("2");
			} 
		}else{
			if(abs(h * (l - 1) + c * (l - 2) - t * (2 * l - 3)) * 2 < abs(h + c - t * 2) * (2 * l - 3)){
				printf("%lld\n", l * 2 - 3); 
			}else{
				puts("2");
			} 
		}
		//if(cal(l) < ans1) ans1 = cal(l), ans2 = l * 2 - 1;
		//if(l) if(cal(l - 1) < ans1) ans1 = cal(l - 1), ans2 = (l - 1) * 2 - 1;
		/*long double lans = 0, rans = 0;
		while(l < r){
			ll lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
			lans = cal(lmid), rans = cal(rmid);
			if(lans < ans1) ans1 = lans, ans2 = lmid * 2 - 1;
			if(rans < ans1) ans1 = rans, ans2 = rmid * 2 - 1;
			if(lans <= rans) r = rmid - 1;
			else l = lmid + 1;
		}*/
		//printf("%lld\n", ans2);
	}
}