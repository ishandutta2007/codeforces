#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

const int MAXN = 2e5 + 5, mod = 1e9 + 7, B = 1337;

typedef long long ll;
typedef pair<int, int> point;

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

vector<int> e[MAXN];

bool bio[MAXN];

int root;
int p[MAXN];
int cik;

void dfs(int x, int par) {
   if(p[x] == x) root = x;
   if(bio[x]) {
      root = x;
      cik = 1;
      bio[x] = true;
      return;
   }
   bio[x] = true;
   for(auto y : e[x])
      if(y != par)
         dfs(y, x);
}

vector<point> v;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int n; cin >> n;

   rep(i, n) {
      int x; cin >> x; p[i] = x - 1;
      if(i != x - 1) {
      e[i].push_back(x - 1);
      e[x - 1].push_back(i);
      }
   }

   int sol = 0;
   rep(i, n) {
      if(bio[i]) continue;
      cik = 0;
      root = i;
      dfs(i, i);
      sol ++;
      v.push_back({cik, root});
   }

   sort(v.begin(), v.end());

   for(int i = 1; i < v.size(); ++i) {
      p[v[i].second] = v[i - 1].second;
   }

   if(v[0].first == 1) {sol ++; p[v[0].second] = v[0].second;}

   cout << sol - 1 << endl;
   rep(i, n) cout << p[i] + 1 << ' ';
}