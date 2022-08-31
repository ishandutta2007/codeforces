#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		ll v = LLONG_MAX;
		ll v_max = -1;
		int k = -1;
		for(int i = 0; i < n; i++){
			vector<ll> b(m);
			ll u = 0;
			for(int j = 0; j < m; j++){
				cin >> b[j];
				u += j * b[j];
			}
			if(u < v){
				v = u;
			}
			if(u > v_max){
				v_max = u;
				k = i + 1;
			}
		}
		cout << k << " " << v_max - v << endl;
	}
}