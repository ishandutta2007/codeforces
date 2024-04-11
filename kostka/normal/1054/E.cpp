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

#ifdef LOCAL
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<" = "<<h<<", "; _dbg(sdbg+1, a...);
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define cerr if(false) cout
#endif

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 307;
string tab[2][MAXN][MAXN];
int dod[2][MAXN][MAXN];

vector <tuple <int, int, int, int> > ret;

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> tab[0][i][j];
  for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> tab[1][i][j];
  for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
    for(int k=SZ(tab[0][i][j])-1; k>=0; k--) {
      int let = tab[0][i][j][k] - '0';
      if(let + 1 == i) {
        int gd = (j == 1 ? 2 : 1);
        ret.emplace_back(i, j, i, gd);
        dod[0][i][gd]++;
      } else {
        ret.emplace_back(i, j, let + 1, j);
        dod[0][let+1][j]++;
      }
    }
  }

  for(int i=1; i<=2; i++) for(int j=1; j<=m; j++) {
    if(i == j) continue;
    while(dod[0][i][j]--) ret.emplace_back(i, j, i, i);
  }

  for(int i=n; i>=3; i--) for(int j=m; j>=1; j--) {
    for(int k=SZ(tab[1][i][j])-1; k>=0; k--) {
      int let = tab[1][i][j][k] - '0';
      if(let+1 == i or let+1 == j) ret.emplace_back(let+1, let+1, i, j);
      else {
        ret.emplace_back(let+1, let+1, let+1, j);
        ret.emplace_back(let+1, j, i, j);
      }
    }
  }

  string R[3] = {"", "", ""};
  swap(tab[1][1][1], tab[1][1][2]);
  for(int i=1; i<=2; i++) for(int j=1; j<=m; j++) R[i] += tab[1][i][j];
  swap(tab[1][1][1], tab[1][1][2]);
  for(int i=1; i<=2; i++) {
    reverse(ALL(R[i]));
    for(auto r : R[i]) {
      int let = r - '0';
      ret.emplace_back(let+1, let+1, i, 3-i);
    }
  }
  for(int i=1; i<=2; i++) for(int j=m; j>=3; j--) {
    for(int k=0; k<SZ(tab[1][i][j]); k++) ret.emplace_back(i, 3-i, i, j);
  }
  for(int i=1; i<=2; i++) {
    for(int k=0; k<SZ(tab[1][i][i]); k++) ret.emplace_back(i, 3-i, i, i);
  }

  cout << SZ(ret) << "\n";
  for(auto r : ret) {
    cout << get<0>(r) << " " << get<1>(r) << " " << get<2>(r) << " " << get<3>(r) << "\n";
  }

  #ifdef LOCAL
    for(auto r : ret) {
      int x1, x2, y1, y2;
      tie(x1, y1, x2, y2) = r;
      assert(x1 == x2 or y1 == y2);
      assert(x1 != x2 or y1 != y2);
      assert(!tab[0][x1][y1].empty());
      char x = tab[0][x1][y1].back();
      tab[0][x1][y1].pop_back();
      tab[0][x2][y2] = x + tab[0][x2][y2];
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cerr << tab[0][i][j] << " " << tab[1][i][j] << "\n";
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) assert(tab[0][i][j] == tab[1][i][j]);
  #endif

  return 0;
}