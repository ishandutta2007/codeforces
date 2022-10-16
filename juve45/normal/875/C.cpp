#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, cap[N], m, x, use[N];

vector <int> g[N], v[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

void dfs(int k) {
	cap[k] = 1;
	use[k] = 1;
	for(auto i : g[k])
		if(!use[i])
			dfs(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		cin >> k;
		for(int j = 1; j <= k; j++)
			cin >> x, v[i].push_back(x);
	}

	for(int i = 1; i < n; i++) {
		int j = 0;
		
		while(j < v[i].size() && j < v[i + 1].size() && v[i][j] == v[i + 1][j]) j++;

		if(j == v[i].size()) continue;

		if(j == v[i + 1].size())
			return cout << "No\n", 0;
		
		if(v[i][j] < v[i + 1][j]) {
			g[v[i + 1][j]].push_back(v[i][j]);
		}
		else cap[v[i][j]] = 1;
	}


	for(int i = 1; i <= m; i++)
		if(!use[i] && cap[i])
			dfs(i);

	vector <int> ans;

	for(int i = 1; i <= m; i++)
		if(cap[i])
			ans.push_back(i);
	// dbg(ans);

	for(int i = 1; i < n; i++) {
		int j = 0;
		while(j < v[i].size() && j < v[i + 1].size() && v[i][j] == v[i + 1][j]) j++;
		if(j == v[i].size()) continue;
		
		if(v[i][j] > v[i + 1][j]) 
			if(cap[v[i][j]] <= cap[v[i + 1][j]])
				return cout << "No\n", 0;
	}
	cout << "Yes\n";
	cout << ans << '\n';
}