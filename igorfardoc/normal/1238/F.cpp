#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
int ans;

int dfs(int v, int p) {
	int adding = 0;
	if(p != -1) {
		adding = 1;
	}
	vi here;
	for(int u : g[v]) {
		if(u == p) continue;
		here.push_back(dfs(u, v));
		//cout << u << ' ' << v << ' ' << here[here.size() - 1] << endl;
	}
	sort(here.begin(), here.end());
	if(here.empty()) {
		ans = max(ans, 1 + adding);
		return 1;
	}
	if(here.size() == 1) {
		ans = max(ans, here[0] + 1 + adding);
		return here[0] + 1;
	}
	int anshere = here[here.size() - 1] + here[here.size() - 2];
	anshere += here.size() - 1 + adding;
	ans = max(ans, anshere);
	return here[here.size() - 1] + here.size();
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
    	int n;
    	cin >> n;
    	g.assign(n, vi(0));
    	ans = 0;
    	for(int i = 0; i < n - 1; i++) {
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		g[v].push_back(u);
    		g[u].push_back(v);
    	}
    	dfs(0, -1);
    	cout << ans << '\n';
    }

}