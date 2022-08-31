#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		ll x, y; cin >> x >> y;
		if(x > y){
			cout << x + y << endl;
			continue;
		}
		if(x == y){
			cout << x << endl;
			continue;
		}
		int k = 1, _k = (y/2) / (x/2), r = (y/2) % (x/2);
		ll n = x * _k + r;
		// cout << x * _k + 
		cout << n << endl;
		assert(n % x == y % n);
	}
}