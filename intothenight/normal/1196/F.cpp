#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void dijkstra(const vector<vector<pair<int, T>>> &adj, int s, vector<T> &d, const T& MAX){
	int n = adj.size();
	d.resize(n, MAX), d[s] = 0;
	vector<bool> visited(n);
	set<pair<int, T>> q{{0, s}};
	while(!q.empty()){
		int u = q.begin()->second;
		q.erase(q.begin());
		visited[u] = true;
		for(auto cur: adj[u]){
			int v = cur.first;
			T w = cur.second;
			if(!visited[v] && d[v] > d[u] + w){
				q.erase({d[v], v});
				d[v] = d[u] + w;
				q.insert({d[v], v});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<tuple<ll, int, int>> edge(m);
	for(auto &e: edge){
		cin >> get<1>(e) >> get<2>(e) >> get<0>(e);
	}
	sort(edge.begin(), edge.end());
	edge.resize(min(m, k));
	vector<vector<pair<int, ll>>> adj(n);
	for(auto e: edge){
		adj[get<1>(e) - 1].push_back({get<2>(e) - 1, get<0>(e)});
		adj[get<2>(e) - 1].push_back({get<1>(e) - 1, get<0>(e)});
	}
	multiset<ll, function<bool(ll, ll)>> res(greater<ll>{});
	for(int i = n - 1; i >= 0; i --){
		if(adj[i].size()){
			vector<ll> d;
			dijkstra(adj, i, d, (ll)1e18);
			for(int j = 0; j < i; j ++){
				if(d[j] != (ll)1e18){
					if(res.size() < k){
						res.insert(d[j]);
					}
					else if(d[j] < *res.begin()){
						res.erase(res.begin());
						res.insert(d[j]);
					}
				}
			}
		}
	}
	cout << *res.begin();
	return 0;
}