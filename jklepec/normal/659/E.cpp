#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5;

vector<int> e[MAXN];

bool bio[MAXN];
unordered_map<ll, bool> uzet;

int uk, ukv;

void dfs(int x) {

   uk ++;
   bio[x] = true;

   for(auto y : e[x]) {
      int X = min(x, y), Y = max(x, y);
      if(!uzet[(ll)X * MAXN + Y]) ukv ++;
      uzet[(ll)X * MAXN + Y] = true;
      if(!bio[y]) dfs(y);
   }
}

int sol;

void solve(int x) {
   if(bio[x]) return;
   uk = ukv = 0;

   dfs(x);

   if(uk == ukv + 1) sol ++;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int n, m; cin >> n >> m;

   rep(i, m) {
      int x, y; cin >> x >> y;
      x--; y--;

      e[x].push_back(y);
      e[y].push_back(x);
   }

   rep(i, n) solve(i);

   cout << sol;

}