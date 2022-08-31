#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif
const int D = 100000;
const int INF = 1 << 20;
signed main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, m;
	cin >> n >> m;
	vector<ll> t(n + 1), x(n + 1), y(n + 1);
	vector<int> when(m + 1, INF);	
	for(int i = 1; i <= n; i++) cin >> t[i] >> x[i] >> y[i];
	set<pair<int, int>> st;

	when[0] = 0;
	for(int i = 0; i <= m; i++) st.insert({when[i], i});
	while(!st.empty()){
		auto it = st.begin();
		int u = it->second, v = it->first;
		st.erase(it);
		for(int i = v + 1; i <= n; i++){
			ll k = u;
			for(int r = 1; r <= y[i]; r++){
				if(t[i] == 1){
					k = (k * 1LL * D + x[i] + D - 1) / D;
				} else{
					k = (k * 1LL * x[i] + D - 1) / D;
				}
				if(k > m) break;
				if(when[k] < i) break;
				st.erase({when[k], k});
				when[k] = i;
				st.insert({when[k], k});
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << (when[i] == INF ? -1 : when[i]) << " ";
	}
	cout << endl;
}