#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
#define _ << " " <<
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

const int MAXN = 2e5 + 5;

vector<int> e[MAXN];

int c[MAXN];

void dfs(int u, int v) {
   int cookie = 1;
   for(auto w : e[v]) {
      if(w == u) continue;
      if(cookie == c[v] || cookie == c[u])
         cookie ++;
      if(cookie == c[v] || cookie == c[u])
         cookie ++;
      c[w] = cookie;
      cookie ++;
   }
   for(auto w : e[v])
      if(w != u)
         dfs(v, w);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	REP(i, n - 1) {
      int x, y; cin >> x >> y;
      x -= 1; y -= 1;
      e[x].push_back(y);
      e[y].push_back(x);
	}
	int mx = 0;
	REP(i, n) {
      if(e[i].size() > mx) {
         mx = e[i].size();
      }
	}
	mx ++;

   c[0] = 1;
   dfs(0, 0);

   cout << mx << endl;
	REP(i, n) cout << c[i] << " ";
}