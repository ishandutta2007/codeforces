#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll MOD;
	cin >> MOD;
	vector<ll> init(2, 1), p(2, 1);
	for(int i = 0; i < 2; i ++){
		ll h, a, x, y;
		cin >> h >> a >> x >> y;
		for(; init[i] <= MOD; init[i] ++){
			h = (x * h + y) % MOD;
			if(h == a){
				break;
			}
			if(init[i] == MOD){
				cout << -1;
				return 0;
			}
		}
		ll temp = a;
		for(; p[i] <= MOD; p[i] ++){
			temp = (x * temp + y) % MOD;
			if(temp == a){
				break;
			}
			if(p[i] == MOD){
				p[i] = 0;
				break;
			}
		}
	}
	if(!p[0] || !p[1]){
		if(p[0] && init[0] <= init[1] && (init[1] - init[0]) % p[0] == 0){
			cout << init[1];
		}
		else if(p[1] && init[0] >= init[1] && (init[0] - init[1]) % p[1] == 0){
			cout << init[0];
		}
		else{
			cout << -1;
		}
		return 0;
	}
	function<ll(ll, ll, ll &, ll &)> gcd = [&](ll a, ll b, ll &x, ll &y){
		if(!b){
			x = 1, y = 0;
			return a;
		}
		else{
			ll tx, ty;
			ll res = gcd(b, a % b, tx, ty);
			x = ty, y = tx - a / b * ty;
			return res;
		}
	};
	ll x, y, g = gcd(p[1], p[0], x, y);
	if((init[0] - init[1]) % g){
		cout << -1;
		return 0;
	}
	x *= (init[0] - init[1]) / g, y *= (init[0] - init[1]) / g;
	ll cx = p[0] / g, cy = p[1] / g;
	while(x < 0){
		x += cx;
		y -= cy;
	}
	while(x >= cx && y + cy <= 0){
		x -= cx;
		y += cy;
	}
	cout << init[1] + x * p[1];
	return 0;
}