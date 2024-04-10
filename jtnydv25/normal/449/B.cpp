#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10;
vector<pii> con[N];
vector<pii> road[N];
ll dist[N];
const ll INF = 1e18;

set<pair<ll, int> > st;
bool done[N];
int main(){
	int n, m, k, x, y, u, v, s;
	sd(n); sd(m); sd(k);
	for(int i = 1; i <= m; i++){
		sd(u); sd(v); sd(x);
		con[u].pb({v, x});
		con[v].pb({u, x});
	}
	for(int i = 0; i < N; i++) road[i] = con[i];

	for(int i = 1; i <= k; i++){
		sd(s); sd(y);
		con[1].pb({s, y});
		con[s].pb({1, y});
	}

	for(int i = 2;i <= n; i++){
		dist[i] = INF;
		st.insert({dist[i], i});
	}
	dist[1] = 0;
	st.insert({dist[1], 1});

	int roads = 0;
	while(!st.empty()){
		pair<long long, int> P = *st.begin();
		int u = P.S;
		done[u] = 1;
		st.erase(st.begin());
		for(auto it : road[u]){
			int v = it.F;
			if(done[v] && dist[v] + it.S == dist[u]){
				roads++;
				break;
			}
		}

		for(auto it : con[u]){
			int v = it.F;
			if((!done[v]) && (dist[u] + it.S < dist[v])){
				st.erase({dist[v], v});
				dist[v] = dist[u] + it.S;
				st.insert({dist[v], v});
			}
		}
	}

	int trains = n - 1 - roads;
	printf("%d\n", k - trains);
}