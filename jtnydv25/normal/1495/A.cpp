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
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> x, y;
		for(int i = 0; i < 2 * n; i++){
			int u, v; cin >> u >> v;
			if(u == 0) y.push_back(abs(v));
			else x.push_back(abs(u));
		}
		sort(all(x));
		sort(all(y));
		double ans = 0;
		for(int i = 0; i < n; i++){
			ans += sqrt(x[i] * 1LL * x[i] + y[i] * 1LL * y[i]);
		}
		cout << setprecision(15) << ans << endl;
	}
}