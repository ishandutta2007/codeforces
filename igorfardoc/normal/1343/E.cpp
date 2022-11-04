#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m, a, b, c;
vvi g;
vi p;

vi bfs(int start) {
	vi dst(n, INF);
	dst[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int u : g[v]) {
			if(dst[u] != INF) continue;
			dst[u] = dst[v] + 1;
			q.push(u);
		}
	}
	return dst;
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
    	cin >> n >> m >> a >> b >> c;
    	--a;
    	--b;
    	--c;
    	g.assign(n, vi(0));
    	p.resize(m);
    	for(int i = 0; i < m; i++) {
    		cin >> p[i];
    	}
    	sort(p.begin(), p.end());
    	for(int i = 0; i < m; i++) {
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		g[v].push_back(u);
    		g[u].push_back(v);
    	}
    	vector<ll> pref(m + 1, 0);
    	for(int i = 1; i <= m; i++) {
    		pref[i] = pref[i - 1] + p[i - 1];
    	}
    	auto dsta = bfs(a);
    	auto dstb = bfs(b);
    	auto dstc = bfs(c);
    	ll ans = (ll)INF * INF;
    	for(int i = 0; i < n; i++) {
    		ll anshere = 0;
    		int am1 = dstb[i];
    		anshere += 2 * pref[am1];
    		int am2 = dsta[i] + dstc[i];
    		if(am1 + am2 > m) {
    			continue;
    		}
    		anshere += pref[am1 + am2] - pref[am1];
    		ans = min(ans, anshere);
    		//cout << i << ' ' << anshere << ' ' << am1 << ' ' << am2 << endl;
    	}
    	cout << ans << '\n';

    }
}