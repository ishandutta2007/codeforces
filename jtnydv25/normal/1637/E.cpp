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
		map<int, int> freq;
		set<int> st;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			freq[x]++;
			st.insert(x);
		}
		vector<set<int>> vals(n + 1);
		vector<int> mx(n + 1, INT_MIN);
		for(auto it: freq){
			vals[it.second].insert(it.first);
			mx[it.second] = max(mx[it.second], it.first);
		}
		vector<int> non_empty;
		for(int i = 1; i <= n; i++) if(!vals[i].empty()) non_empty.push_back(i);
		map<int, vector<int>> bad;
		for(int i = 0; i < m; i++){
			int u, v; cin >> u >> v;
			bad[u].push_back(v);
		}
		ll ans = -1;
		for(int x: st){
			for(int r: bad[x]){
				auto it = freq.find(r);
				if(it != freq.end()){
					int f = it->second;
					vals[f].erase(r);
					mx[f] = vals[f].empty() ? INT_MIN : *vals[f].rbegin();
				}
			}
			int cntx = freq[x];
			for(int cnty: non_empty){
				int mxy = mx[cnty];
				if(mxy > x){
					ans = max(ans, (x + mxy) * 1LL * (cntx + cnty));
				}
			}

			for(int r: bad[x]){
				auto it = freq.find(r);
				if(it != freq.end()){
					int f = it->second;
					vals[f].insert(r);
					mx[f] = *vals[f].rbegin();
				}
			}
		}
		cout << ans << endl;
	}
}