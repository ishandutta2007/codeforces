#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m, k;
vector<vector<pair<int, int>>> g;
vvi dst;

void dijkstra(int start) {
	set<pair<int, int>> s;
	s.insert({0, start});
	dst[start][start] = 0;
	while(!s.empty()) {
		auto p = *(s.begin());
		s.erase(s.begin());
		int v = p.second;
		int dist = p.first;
		for(auto& u1 : g[v]) {
			int u = u1.first;
			int w = u1.second;
			if(dst[start][u] > dist + w) {
				auto it = s.find({dst[start][u], u});
				if(it != s.end()) {
					s.erase(it);
				}
				dst[start][u] = dist + w;
				s.insert({dst[start][u], u});
			}
		}
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
    cin >> n >> m >> k;
    g.resize(n);
    dst.assign(n, vi(n, INF));
    for(int i = 0; i < m; i++) {
    	int v, u, w;
    	cin >> v >> u >> w;
    	--v;
    	--u;
    	g[v].push_back({u, w});
    	g[u].push_back({v, w});
    }
    for(int i = 0; i < n; i++) {
    	dijkstra(i);
    }
    vector<pair<int, int>> q(k);
    for(int i = 0; i < k; i++) {
    	cin >> q[i].first >> q[i].second;
    	--q[i].first;
    	--q[i].second;
    }
    ll ans = (ll)INF * INF;
    for(int i = 0; i < n; i++) {
    	for(auto& u1 : g[i]) {
    		int u = u1.first;
    		ll anshere = 0;
    		for(auto& p : q) {
    			anshere += min(dst[p.first][p.second], min(dst[p.first][i] + dst[u][p.second], dst[p.first][u] + dst[i][p.second]));
    		}
    		ans = min(ans, anshere);
    	}
    }
    cout << ans;
}