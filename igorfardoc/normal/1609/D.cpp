#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
vector<bool> used;

int dfs(int v) {
	used[v] = true;
	int res = 1;
	for(int u : g[v]) {
		if(used[u]) continue;
		res += dfs(u);
	}
	return res;
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
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> e(d);
    for(int i = 0; i < d; i++) {
    	cin >> e[i].first >> e[i].second;
    	--e[i].first;
    	--e[i].second;
    }
    for(int i = 0; i < d; i++) {
    	g.assign(n, vi(0));
    	for(int j = 0; j <= i; j++) {
    		g[e[j].first].push_back(e[j].second);
    		g[e[j].second].push_back(e[j].first);
    	}
    	used.assign(n, false);
    	int amcomponents = 0;
    	vi szs;
    	for(int j = 0; j < n; j++) {
    		if(used[j]) continue;
    		++amcomponents;
    		szs.push_back(dfs(j));
    	}
    	int needrebr = n - amcomponents;
    	int notused = i + 1 - needrebr;
    	sort(szs.begin(), szs.end());
    	reverse(szs.begin(), szs.end());
    	int ans = 0;
    	for(int i = 0; i < notused + 1; i++) {
    		ans += szs[i];
    	}
    	cout << ans - 1 << '\n';
    }

}