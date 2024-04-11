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

const int MAXN = 1007;
bool szach[MAXN][MAXN];
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int ax, ay;
  cin >> ax >> ay;
  for(int i=0; i<8; i++) {
    int nax = ax, nay = ay;
    while(1 <= nax and nax <= n and 1 <= nay and nay <= n) {
      szach[nax][nay] = true;
      nax += dx[i];
      nay += dy[i];
    }
  }
  int bx, by, cx, cy;
  cin >> bx >> by >> cx >> cy;
  queue <pair <int, int> > Q;
  Q.emplace(bx, by);
  szach[bx][by] = true;
  while(!Q.empty()) {
    int nx, ny;
    tie(nx, ny) = Q.front();
    Q.pop();
    if(nx == cx and ny == cy) {
      cout << "YES\n";
      return 0;
    }
    for(int i=0; i<8; i++) {
      int ex = nx + dx[i], ey = ny + dy[i];
      if(1 <= ex and ex <= n and 1 <= ey and ey <= n and !szach[ex][ey]) {
        Q.emplace(ex, ey);
        szach[ex][ey] = true;
      }
    }
  }
  puts("NO");
  return 0;
}