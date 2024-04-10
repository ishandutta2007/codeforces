#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(15);
	int n, m;
	cin >> n >> m;
	int S = 0, E = n - 1;
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	auto bfs = [&](int S, int E, vector<int> &sp, vector<ll> &cnt){
		vector<bool> visited(n);
		deque<pii> q{{S, 0}};
		sp[S] = 0;
		visited[S] = true;
		cnt[S] = 1;
		while(!q.empty()){
			int u = q.front().first, l = q.front().second;
			q.pop_front();
			if(u == E){
				break;
			}
			for(auto v: adj[u]){
				if(!visited[v] || sp[v] == sp[u] + 1){
					cnt[v] += cnt[u];
				}
				if(!visited[v]){
					visited[v] = true;
					q.push_back({v, l + 1});
					sp[v] = l + 1;
				}
			}
		}
	};
	vector<ll> cnt1(n), cnt2(n);
	vector<int> sp1(n), sp2(n);
	bfs(S, E, sp1, cnt1), bfs(E, S, sp2, cnt2);
	ll res = cnt1[E];
	for(int i = S + 1; i <= E - 1; i ++){
		if(sp1[i] + sp2[i] == sp1[E]){
			res = max(2 * cnt1[i] * cnt2[i], res);
		}
	}
	cout << (double) res / cnt1[E];
	return 0;
}