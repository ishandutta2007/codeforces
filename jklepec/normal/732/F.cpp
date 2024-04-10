#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;
int add(int x, int y) {
	x += y;
	if(x >= mod) return x - mod;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if(x < 0) return x + mod;
	return x;
}
int mul(int x, int y) {
	return (ll) x * y % mod;
}

const int MAXN = 4e5 + 5;

int n, m;
unordered_map<ll, int> smjer;
unordered_map<ll, bool> bridge;
vector<point> edges, bridges;

vector<int> e[MAXN];
vector<point> e2[MAXN];

int cnt, component, uk;

int com[MAXN];
int dis[MAXN];
int low[MAXN];
bool bio[MAXN];

void dfs(int u, int v) {
   dis[v] = ++cnt;
   low[v] = dis[v];

   for(auto w : e[v]) {
      if(w == u) continue;
      if(dis[w]) {
         low[v] = min(low[v], dis[w]);
      }
      else {
         dfs(v, w);
         low[v] = min(low[v], low[w]);
         if(low[w] == dis[w]) {
            bridge[(ll) w * MAXN + v] = bridge[(ll) v * MAXN + w] = true;
            bridges.emplace_back(v, w);
         }
      }
   }
}

void obidi(int x) {
   uk ++;
   bio[x] = true;
   com[x] = component;
   for(auto y : e[x]) {
      if(bridge[(ll) x * MAXN + y]) continue;
      smjer[(ll) x * MAXN + y] = 1;
      smjer[(ll) y * MAXN + x] = -1;
      if(!bio[y])
         obidi(y);
   }
}

void izgradi(int u, int v) {
   for(auto p : e2[v]) {
      int w = p.first, i = p.second;
      if(w == u) continue;

      int x = bridges[i].first, y = bridges[i].second;

      if(com[x] == v) {
         smjer[(ll) x * MAXN + y] = -1;
         smjer[(ll) y * MAXN + x] = 1;
      }
      else {
         smjer[(ll) x * MAXN + y] = 1;
         smjer[(ll) y * MAXN + x] = -1;
      }

      izgradi(v, w);
   }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);

   cin >> n >> m;
   rep(i, m) {
      int x, y; cin >> x >> y;
      edges.emplace_back(--x, --y);
      e[x].push_back(y);
      e[y].push_back(x);
   }

   dfs(0, 0);

   int mx = 0, ind;

   rep(i, n) {
      if(bio[i]) continue;
      uk = 0;
      obidi(i);
      if(uk > mx) {
         ind = component;
         mx = uk;
      }
      component ++;
   }


   rep(i, bridges.size()) {
      int u = bridges[i].first, v = bridges[i].second;
      e2[com[u]].emplace_back(com[v], i);
      e2[com[v]].emplace_back(com[u], i);
   }

   izgradi(ind, ind);

   cout << mx << endl;
   rep(i, m) {
      int x = edges[i].first, y = edges[i].second;
      if(smjer[(ll) x * MAXN + y] != -1) {
         cout << x + 1 << " " << y + 1 << endl;
      }
      else {
         cout << y + 1 << " " << x + 1 << endl;
      }
   }
}