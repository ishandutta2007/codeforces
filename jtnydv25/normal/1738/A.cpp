#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
		int n; cin >> n;
		vector<vector<int>> b(2);
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		ll ans = 0;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			b[a[i]].push_back(x);
			ans += x;
		}
		sort(all(b[0])); sort(all(b[1]));
		reverse(all(b[0])); reverse(all(b[1]));
		int x = sz(b[0]), y = sz(b[1]);
		for(int i = 0; i < min(x, y); i++) ans += b[0][i] + b[1][i];
		if(x == y) ans -= min(b[0][x - 1], b[1][x - 1]);
		cout << ans << endl;
	}
}