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
		int n; cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		map<int, set<int>> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			a[i]--;
			mp[a[i]].insert(i);
		}
		while(!mp.empty()){
			vector<int> R, V;
			for(auto &it: mp){
				auto& st = it.second;
				int u = *st.begin();
				V.push_back(u);
				if(sz(st) == 1) R.push_back(it.first);
			}
			int k = V.size();
			// trace(V);
			for(int i = 0; i < k; i++) b[V[(i + 1) % k]] = a[V[i]];
			for(int x: V) mp[a[x]].erase(x);
			for(int x: R)mp.erase(x);
		}
		for(int i = 0; i < n; i++) cout << b[i] + 1 << " ";
		cout << endl;
	}
}