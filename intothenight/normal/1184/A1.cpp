#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll r;
	cin >> r;
	if(r < 5){
		cout<< "NO\n";
		return 0;
	}
	r --;
	vector<ll> factor;
	for(ll x = 1; x * x <= r; x ++){
		if(r % x == 0){
			factor.push_back(x);
			if((r / x - x) & 1 && r / x >= x + 3 ){
				cout << x << " " << (r / x - x - 1) / 2 << "\n";
				return 0;
			}
		}
	}
	for(auto it = factor.rbegin(); it != factor.rend(); it ++){
		ll x = *it;
		if((r / x - x) & 1 && r / x >= x + 3){
			cout << x << " " << (r / x - x - 1) / 2 << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}