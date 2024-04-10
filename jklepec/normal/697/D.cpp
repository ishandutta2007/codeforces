#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5, mod = 1e9 + 7;

int n;

lf sol[MAXN];
int ts[MAXN];

vector<int> e[MAXN];

void dfs(int x) {
   ts[x] = 1;
   for(auto y : e[x]) {
      dfs(y);
      ts[x] += ts[y];
   }
}

void rijesi(int x) {
   if(e[x].size() == 0) return;
   int uk = e[x].size(), sum = 0;
   for(auto y : e[x]) {
      sum += ts[y];
   }
   if(e[x].size() == 1) {
      sol[e[x][0]] = sol[x] + 1;
   }
   else {
      for(auto y : e[x]) {
         sol[y] = sol[x] + ((lf) 1 / (lf) uk) * ((lf) (sum - ts[y]) / (lf) (uk - 1) * ((ll) uk * (ll) (uk - 1) / 2)) + 1;
      }
   }
   for(auto y : e[x]) {
      rijesi(y);
   }
}

void load() {
   cin >> n;
   rep(i, n - 1) {
      int x; cin >> x;
      e[--x].push_back(i + 1);
   }
}

void solve() {
   dfs(0);
   sol[0] = (lf) 1;
   rijesi(0);
   rep(i, n) cout << fixed << setprecision(8) << sol[i] << ' ';
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   load();
   solve();
}