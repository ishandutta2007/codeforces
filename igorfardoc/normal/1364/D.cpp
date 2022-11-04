#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi c;
vi st;
vi cicle;
vvi g;
int n, m, k;
int ans = 1000000;
vi depth;
vi col;

bool dfs1(int v, int p) {
	c[v] = 1;
	bool res = false;
	for(int u : g[v]) {
		if(c[u] == 1 && u != p) {
			res = true;
			ans = min(ans, depth[v] - depth[u] + 1);
		} else if(c[u] == 0) {
			depth[u] = depth[v] + 1;
			res = res || dfs1(u, v);
		}
	}
	c[v] = 2;
	return res;
}

void dfs2(int v) {
	for(int u : g[v]) {
		if(col[u] == 0) {
			col[u] = 3 - col[v];
			dfs2(u);
		}
	}
}
void dfs3(int v, int p) {
	st.push_back(v);
	c[v] = 1;
	for(int u : g[v]) {
		if(c[u] == 1 && u != p) {
			if(depth[v] - depth[u] + 1 == ans && cicle.empty()) {
				int now = st.size() - 1;
				while(st[now] != u) {
					cicle.push_back(st[now--]);
				}
				cicle.push_back(u);
			}
		} else if(c[u] == 0) {
			depth[u] = depth[v] + 1;
			dfs3(u, v);
		}
	}
	c[v] = 2;
	st.pop_back();
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
    cin >> n >> m >> k;
    g.resize(n);
    c.assign(n, 0);
    depth.resize(n);
    for(int i = 0; i < m; i++) {
    	int v, u;
    	cin >> v >> u;
    	v--;
    	u--;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    depth[0] = 0;
    bool there = dfs1(0, -1);
    if(!there) {
    	col.assign(n, 0);
    	col[0] = 1;
    	dfs2(0);
    	int am1 = 0;
    	for(int i = 0; i < n; i++) {
    		if(col[i] == 1) {
    			++am1;
    		}
    	}
    	cout << "1\n";
    	int need = 1;
    	if(am1 < (k - 1) / 2 + 1) {
    		need = 2;
    	}
    	int can = (k - 1) / 2 + 1;
    	for(int i = 0; i < n && can > 0; i++) {
    		if(col[i] == need) {
    			cout << i + 1 << ' ';
    			--can;
    		}
    	}
    	cout << '\n';
    	return 0;
    }
    c.assign(n, 0);
    depth.resize(n);
    depth[0] = 0;
    dfs3(0, -1);
    if(cicle.size() <= k) {
    	cout << "2\n";
    	cout << cicle.size() << '\n';
    	for(int i = 0; i < cicle.size(); i++) {
    		cout << cicle[i] + 1 << ' ';
    	}
    	return 0;
    }
    cout << "1\n";
    int need = (k - 1) / 2 + 1;
    for(int i = 0; i < cicle.size() && need > 0; i+=2) {
    	cout << cicle[i] + 1 << ' ';
    	--need;
    }
}