#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mid ((lo + hi) >> 1)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a) for(int i = 0; i < a; ++i)
using namespace std;

typedef long long llint;
typedef pair<int, int> point;

const int MAXN = 100005;

llint sol;
vector<int> E[MAXN];

int dp[MAXN];

int main() {
   ios_base::sync_with_stdio(false);

   int n, m; cin >> n >> m;
   for(int i = 0; i < m; ++i) {
           int x, y; cin >> x >> y; --x; --y;
           E[x].push_back(y);
           E[y].push_back(x);
   }
   for(int i = 0; i < n; ++i) {
           dp[i] = 1;
           if(!i) {
                  dp[i] = 1;
           }else {
                 for(int j = 0; j < E[i].size(); ++j) {
                         int y = E[i][j];
                         if(y > i)
                              continue;
                         dp[i] = max(dp[i], dp[y] + 1);
                 }
           }
   }
   for(int i = 0; i < n; ++i)
           sol = max(sol, (llint)dp[i] * (llint)E[i].size());
   cout << sol;
   return 0;
}