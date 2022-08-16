#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<int> mate(2 * n, -1);
		vector<pii> edges;
		for(int i = 0; i < k; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			mate[u] = v;
			mate[v] = u;
			edges.push_back({u, v});
		}
		int ans = ((n - k) * (n - k - 1)) / 2;
		for(int i = 0; i < k; i++){
			int u = edges[i].first, v = edges[i].second;
			if(u > v) swap(u, v);
			int x = 0;
			for(int i = u; i <= v; i++) if(mate[i] == -1) x++;
			int y = 2 * (n - k) - x;
			ans += min(x, y);
			for(int j = 0; j < i; j++){
				int _u = edges[j].first, _v = edges[j].second;
				// if(_u > _v) swap(_u, _v);
				if((_u > u && _u < v) ^ (_v > u && _v < v)){
					// trace(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}