#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
#define _ << " " <<
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e5 + 5;

int k;

ll dp[MAXN], dpd[MAXN], ch[MAXN][6], chd[MAXN][6];
vector<int> e[MAXN];

void dfs2(int u, int v) {
   if(v != u) {
      FOR(i, 0, k) {
         chd[v][i] += chd[u][(i - 1 + k) % k];
         chd[v][i] += ch[u][(i - 1 + k) % k] - ch[v][(i - 2 + k) % k];
      }
      dpd[v] += dpd[u] + chd[u][0];
      dpd[v] += dp[u] - dp[v] - ch[v][0] + ch[u][0] - ch[v][k - 1];
   }
   for(auto w: e[v]) {
      if(u != w) {
         dfs2(v, w);
      }
   }
}

void dfs(int u, int v) {
   for(auto w: e[v]) {
      if(u != w) {
         dfs(v, w);

         FOR(i, 1, k) {
            ch[v][i] += ch[w][i - 1];
         }
         ch[v][0] += ch[w][k - 1];
         dp[v] += dp[w];
         dp[v] += ch[w][0];
      }
   }

   ch[v][0] ++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int n; cin >> n >> k; //k++;
   REP(i, n - 1) {
      int x, y; cin >> x >> y;

      e[x - 1].push_back(y - 1);
      e[y - 1].push_back(x - 1);
   }

   dfs(0, 0);

   dfs2(0, 0);


   ll sol = 0;
   REP(i, n) {
      sol += dpd[i] + dp[i];
   }

   cout << sol / 2;
}