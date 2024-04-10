#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
vi dst;
int n, a, b, da, db;
void bfs(int a) {
	dst.assign(n, INF);
	dst[a] = 0;
	queue<int> q;
	q.push(a);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int u : g[v]) {
			if(dst[u] == INF) {
				dst[u] = dst[v] + 1;
				q.push(u);
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
    int t;
    cin >> t;
    while(t--) {
    	cin >> n >> a >> b >> da >> db;
    	--a;
    	--b;
    	g.assign(n, vector<int>(0));
    	for(int i = 0; i < n - 1; i++) {
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		g[v].push_back(u);
    		g[u].push_back(v);
    	}
    	if(db <= 2 * da) {
    		cout << "Alice\n";
    		continue;
    	}
    	bfs(a);
    	if(dst[b] <= da) {
    		cout << "Alice\n";
    		continue;
    	}
    	int v = 0;
    	for(int i = 0; i < n; i++) {
    		if(dst[i] > dst[v]) {
    			v = i;
    		}
    	}
    	bfs(v);
    	int diam = 0;
    	for(int i = 0; i < n; i++) {
    		diam = max(diam, dst[i]);
    	}
    	if(2 * da >= diam) {
    		cout << "Alice\n";
    	} else {
    		cout << "Bob\n";
    	}
    }
}