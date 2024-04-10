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
		int n;
		cin >> n;
		vector<int> b(n + 1);
		vector<vector<int>> pos(n + 2);
		vector<int> occ(n + 2);
		for(int i = 1; i <= n; i++){
			cin >> b[i];
			pos[b[i]].push_back(i);
			occ[b[i]]++;
		}
		vector<int> cur = {0, n + 1};
		int type = (*max_element(all(b))) != n + 1;
		vector<int> sizes(2);
		vector<int> a;
		while(true){
			// find next set
			vector<int> old = cur;
			cur.clear();
			for(int v: old){
				for(int u: pos[v]) cur.push_back(u);
			}
			if(cur.empty()) break;
			sort(all(cur), [&](int i, int j){return occ[i] < occ[j];});
			// sets.push_back(cur);
			copy(all(cur), back_inserter(a));
			sizes[type] += cur.size();
			type ^= 1;
		}
		cout << sizes[0] << endl;
		for(auto it: a) cout << it << " ";
		cout << endl;
	}
}