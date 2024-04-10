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

const int MAXN = 1e3 + 5;

bool govern[MAXN];

int par[MAXN], sz[MAXN];
int f(int x) {
   if(par[x] == x) return x;
   return par[x] = f(par[x]);
}
void spoji(int x, int y) {
   x = f(x);
   y = f(y);
   if(x == y) return;
   sz[y] += sz[x];
   par[x] = y;
}

bool ok[MAXN];

int main() {
   rep(i, MAXN) par[i] = i;
   rep(i, MAXN) sz[i] = 1;
	ios_base::sync_with_stdio(false); cin.tie(0);
   int n, m, k; cin >> n >> m >> k;
   rep(i, k) {
      int x; cin >> x; --x;
      govern[x] = true;
   }
   for(int i = 0; i < m; ++i) {
      int x, y; cin >> x >> y;
      spoji(x - 1, y - 1);
   }
   for(int i = 0; i < n; ++i) {
      if(govern[i]) ok[f(i)] = true;
   }
   int uk = 0;
   for(int i = 0; i < n; ++i) {
      if(!ok[f(i)]) uk ++;
   }
   int mx = 0;
   for(int i = 0; i < n; ++i) {
      if(govern[i]) mx = max(mx, sz[f(i)]);
   }
   int sol = 0, taken = false;
   for(int i = 0; i < n; ++i) {
      if(govern[i]) {
         if(sz[f(i)] == mx && !taken) {
            taken = true;
            sol += (uk + sz[f(i)]) * (uk + sz[f(i)] - 1) / 2;
         }
         else {
            sol += (sz[f(i)]) * (sz[f(i)] - 1) / 2;
         }
      }
   }
   cout << sol - m;
}