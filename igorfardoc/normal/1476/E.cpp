#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m, k;
vector<string> temp;
vector<string> a;
map<string, int> templates;
vi val;
bool ok = true;

vvi g;
vi order;
vector<bool> used;
vi c;
void dfs1(int v) {
	c[v] = 0;
	for(int u : g[v]) {
		if(c[u] == 0) ok = false;
		if(c[u] == -1) {
			dfs1(u);
		}
	}
	c[v] = 1;
}

void dfs(int v) {
	used[v] = true;
	for(int u : g[v]) {
		if(used[u]) continue;
		dfs(u);
	}
	order.push_back(v);
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
    temp.resize(n);
    for(int i = 0; i < n; i++) {
    	cin >> temp[i];
    	templates[temp[i]] = i;
    }
    val.resize(m);
    a.resize(m);
    g.resize(n);
    for(int i = 0; i < m; i++) {
    	cin >> a[i] >> val[i];
    	--val[i];
    }
    vi ans(n, -1);
    for(int i = 0; i < m; i++) {
    	vi ids;
    	bool ok = false;
    	for(int mask = 0; mask < (1 << k); mask++) {
			string s1 = "";
			for(int j = 0; j < k; j++) {
				if((mask >> j) & 1) {
					s1 += a[i][j];
				} else {
					s1 += '_';
				}
			}
			auto it = templates.find(s1);
			if(it == templates.end()) {
				continue;
			}
			int tempId = it->second;
			ids.push_back(tempId);
			if(tempId == val[i]) ok = true;
		}
		if(!ok) {
			cout << "NO";
			return 0;
		}
		for(const auto& el : ids) {
			if(el == val[i]) continue;
			g[val[i]].push_back(el);
		}
	}
	c.assign(n, -1);
	for(int i = 0; i < n; i++) {
		if(c[i] == -1) {
			dfs1(i);
		}
	}
	if(!ok) {
		cout << "NO";
		return 0;
	}
	used.assign(n, false);
	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());
	cout << "YES\n";
	for(const auto& el : order) {
		cout << el + 1 << ' ';
	}
}