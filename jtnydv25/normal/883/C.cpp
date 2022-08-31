#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

ll getCeil(ll a, ll b){
	if(a <= 0) return 0;
	return (a - 1) / b + 1;
}
int main(){
	ll f, T, a1, a2, t0, t1, t2, p1, p2;
	cin >> f >> T >> t0;
	cin >> a1 >> t1 >> p1;
	cin >> a2 >> t2 >> p2;

	ll x_max = getCeil(f, a1);

	ll a1t1 = a1 * t1;
	ll a2t2 = a2 * t2;
	ll y_max = getCeil(f, a2);
	ll y2 = f / a2;
	long long ans = 1e18;
	for(ll x = 0; x <= x_max; x++){
		ll rem = T - a1t1 * x;
		ll data = f - a1 * x;
		
		// use nonzero regular tarrif
		// choose min y s.t -> a2t2 * y + (data - a2 * y) * t0 <= rem
		// (a2t0 - a2t2) * y >= data * t0 - rem

		if(rem < 0) break;

		if(data > 0){
			if(t0 <= t2){
				if(data * t0 <= rem)
					ans = min(ans, p1 * x);
			}
			else{
				ll z = data * t0 - rem;

				ll y = getCeil(z, a2 * (t0 - t2));

				if(y <= data / a2 && a2 * t2 * y + a1 * t1 * x + (f - a1 * x - a2 * y) * t0 <= T && f - a1 * x - a2 * y > 0){
					ans = min(ans, p1 * x + p2 * y);
				}	
			}	
		}
		if(data >= 0){
			ll y = getCeil(data, a2);
			if(a1t1 * x + data * t2 <= T){
				ans = min(ans, x * p1 + y * p2);
			}
		}
	}

	for(ll y = 0; y <= y_max; y++){
		ll data = f - a2 * y;
		if(data >= 0){
			ll x = getCeil(data, a1);
			if(t1 * data + a2t2 * y <= T) ans = min(ans, x * p1 + y * p2);
		}
	}

	if(f * t1 <= T) ans = min(ans, x_max * p1);
	if(f * t2 <= T) ans = min(ans, y_max * p2);
	if(ans > 1e17) ans = -1;
	cout << ans << endl;
}