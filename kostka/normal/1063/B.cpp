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

char tab[2007][2007];
bool vis[2007][2007];
int dist[2007][2007];

int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0}, dw[] = {0, 1, 0, 0};

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) dist[i][j] = 1e9;
  int r, c;
  cin >> r >> c;
  r--; c--;
  int x, y;
  cin >> x >> y;
  for(int i=0; i<n; i++) cin >> tab[i];
  auto on_board = [&](int p, int q) {
    return 0 <= p and p < n and 0 <= q and q < m;
  };
  priority_queue <pair <int, pii> > Q;
  Q.emplace(0, make_pair(r, c));
  dist[r][c] = 0;
  while(!Q.empty()) {
    int a, b;
    tie(a, b) = Q.top().second;
    // cerr << a << " " << b << "\n";
    Q.pop();
    if(vis[a][b]) continue;
    vis[a][b] = true;
    for(int i=0; i<4; i++) {
      int nx = a + dx[i], ny = b + dy[i];
      if(on_board(nx, ny) and tab[nx][ny] == '.') {
        if(dist[nx][ny] > dist[a][b] + dw[i]) {
          dist[nx][ny] = dist[a][b] + dw[i];
          Q.emplace(-dist[nx][ny], make_pair(nx, ny));
        }
      }
    }
  }
  int ret = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(dist[i][j] != 1e9 and dist[i][j] <= x and dist[i][j] + j <= y + c) ret++;
    }
  }
  cout << ret << "\n";
  return 0;
}