#include<bits/stdc++.h>
using namespace std;
int n, t, sz, ok;
set<int> vis;
vector<int> top, p;
vector<vector<int>> bw;
void dfs(int v) {
	vis.erase(v);
	while(true) {
		auto it = vis.lower_bound(v);
		if(it == vis.end() || *it >= p[v])
			break;
		dfs(*it);
	}
	for(auto i : bw[v])
		if(vis.count(i))
			dfs(i);
	top[v] = sz++;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(cin>>t;t--;) {
		cin >> n;sz=ok=1;
		p = top = vector<int>(n);
		bw = vector<vector<int>>(n+1);
		for(auto &i : p) cin >> i, i--;
		for(int i = n;i--;) {
			vis.insert(i);
			if(p[i] >= 0)
				bw[p[i]].push_back(i);
		}
		while(!vis.empty())
			dfs(*vis.begin());
		p.clear();
		vector<int> st{n};
		for(int i = n; i--;) {
			while(st.size()>1 && top[st.back()] < top[i])
				st.pop_back();
			ok &= st.back()==p[i]||p[i]==-2;
			st.push_back(i);
		}
		if(!ok) top = {-1};
		for(auto i : top) cout << i << " "; cout << '\n';
	};
}