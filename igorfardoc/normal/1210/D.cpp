#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m;
vi st;
vvi g;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    st.assign(n, 0);
    g.resize(n);
    for(int i = 0; i < m; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	if(v > u) {
    		swap(v, u);
    	}
    	++st[v];
    	++st[u];
    	g[v].push_back(u);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
    	ans += (ll)(g[i].size()) * (st[i] - g[i].size());
    }
    cout << ans << '\n';
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
    	int v;
    	cin >> v;
    	--v;
    	ans -= (ll)(g[v].size()) * (st[v] - g[v].size());
    	for(const auto& el : g[v]) {
    		ans -= (ll)(g[el].size()) * (st[el] - g[el].size());
    		g[el].push_back(v);
    		ans += (ll)(g[el].size()) * (st[el] - g[el].size());
    	}
    	g[v].clear();
    	cout << ans << '\n';
    }
}