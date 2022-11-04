#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m;
vvi g, gr;
string a;
int ans1, ans2;
int convert(int x, int y) {
	return x * m + y;
}
vi c;
vi ans;
vi st;
vector<bool> used;
vector<bool> can0;

void dfs(int v) {
	c[v] = 1;
	st.push_back(v);
	for(int u : g[v]) {
		if(c[u] == 2) continue;
		if(c[u] == 1) {
			int now = st.size() - 1;
			while(st[now] != u) {
				ans.push_back(st[now]);
				--now;
			}
			ans.push_back(u);
			continue;
		}
		dfs(u);
	}
	c[v] = 2;
	st.pop_back();
}

void dfs1(int v, int d) {
	//cout << v << endl;
	used[v] = true;
	if(a[v] == '0') {
		can0[d % can0.size()] = true;
	}
	for(int u : gr[v]) {
		if(used[u]) continue;
		dfs1(u, d + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
    	cin >> n >> m;
    	g.assign(n * m, vi(0));
    	gr.assign(n * m, vi(0));
    	a = "";
    	for(int i = 0; i < n; i++) {
    		string t;
    		cin >> t;
    		a += t;
    	}
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			int x, y;
    			x = i;
    			y = j;
    			char c;
    			cin >> c;
    			int v = convert(i, j);
    			if(c == 'U') {
    				--x;
    			} else if(c == 'D') {
    				++x;
    			} else if(c == 'R') {
    				++y;
    			} else {
    				--y;
    			}
    			int u = convert(x, y);
    			//cout << v << ' ' << u << endl;
    			g[v].push_back(u);
    			gr[u].push_back(v);
    		}
    	}
    	ans1 = 0;
    	ans2 = 0;
    	c.assign(n * m, 0);
    	used.assign(n * m, false);
    	for(int i = 0; i < n * m; i++) {
    		if(c[i] != 0) continue;
    		st.clear();
    		ans.clear();
    		dfs(i);
    		if(ans.empty()) {
    			continue;
    		}
    		for(const auto& el : ans) {
    			used[el] = true;
    		}
    		can0.assign(ans.size(), false);
    		for(int i = 0; i < ans.size(); i++) {
    			dfs1(ans[i], i);
    		}
    		//cout << ans[0] << ' ' << ans[1] << endl;
    		ans1 += ans.size();
    		for(const auto& el : can0) {
    			ans2 += el;
    		}
    	}
    	cout << ans1 << ' ' << ans2 << '\n';
    }

}