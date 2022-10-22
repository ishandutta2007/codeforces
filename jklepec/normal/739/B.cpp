#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 4e5 + 5, LOG = 22;
ll a[MAXN];
ll lanac[MAXN], sol[MAXN];
vector<point> e[MAXN];

ll par[MAXN][LOG];
ll len[MAXN][LOG];

void dfs(int x, int p, ll ud) {
   par[x][0] = p;
   len[x][0] = ud;

   for(int i = 1; i < LOG; ++i) {
      par[x][i] = par[par[x][i - 1]][i - 1];
      len[x][i] = len[par[x][i - 1]][i - 1] + len[x][i - 1];
   }

   for(point y : e[x]) dfs(y.first, x, y.second);

   ll v = x;
   ll tmp = 0;
   for(int i = LOG - 1; i >= 0; --i) if(len[v][i] <= a[x] - tmp) {
      tmp += len[v][i];
      v = par[v][i];
   }

   if(x != 0) lanac[par[x][0]] += 1;
   if(v != 0) lanac[par[v][0]] -= 1;
}

void calc(int x) {
   sol[x] = lanac[x];
   for(auto y : e[x]) {
      calc(y.first);
   }
   for(auto y : e[x]) {
      sol[x] += sol[y.first];
   }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n - 1) {
      ll x, y; cin >> x >> y;
      e[x - 1].push_back(point(i + 1, y));
	}

	dfs(0, 0, 0);
   calc(0);

   rep(i, n) cout << sol[i] << ' ';
}