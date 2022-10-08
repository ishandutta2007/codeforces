//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 1007;
bool tab[MAXN][MAXN];
int n, m, res;

void go(int id) {
  res = max(res, 2*id);
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(tab[i][j]) continue;
      for(int dx=-3; dx<=3; dx++) {
        for(int dy=-3; dy<=3; dy++) {
          if(abs(dx) + abs(dy) != 3) continue;
          int k = i+dx, l = j+dy;
          if(0 <= k and k < n and 0 <= l and l < m) {
            if(tab[k][l]) continue;
            tab[i][j] = true;
            tab[k][l] = true;
            go(id+1);
            tab[i][j] = false;
            tab[k][l] = false;
          }
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  // go(0);
  if(m > n) swap(n, m);
  if(m == 1) cout << n/6*6 + 2*(n%6 == 4) + 4*(n%6 ==5) << "\n";
  else if(m == 2 and n <= 2) cout << 0 << "\n";
  else if(m == 2) cout << 1LL*n*m - ((n % 4 == 3 and n <= 8) ? 2 : 0) << "\n";
  else cout << (1LL*n*m - ((n % 2 and m % 2) ? 1 : 0)) << "\n";
  // cout << res << "\n";
  return 0;
}