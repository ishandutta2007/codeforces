#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
string s;
int a[105];

int nn[3];
vector<int> vv[3];
int dist[77][77][77][3];

ll dp(int x, int y, int z, int last){
  static ll memo[105][105][105][3];
  static bool bio[105][105][105][3];
  ll &r = memo[x][y][z][last];
  if (bio[x][y][z][last]++) return r;
  if (x == nn[0] && y == nn[1] && z == nn[2]) return r = 0;
  r = 1e18;
  if (x != nn[0])
    r = min(r, dp(x+1, y, z, 0) + dist[x][y][z][0]);
  if (y != nn[1] && last != 0)
    r = min(r, dp(x, y+1, z, 1) + dist[x][y][z][1]);
  if (z != nn[2])
    r = min(r, dp(x, y, z+1, 2) + dist[x][y][z][2]);
  return r;
}

// void rek(int x, int y, int z, int last){
//   ll r = dp(x, y, z, last);
//   if (x == nn[0] && y == nn[1] && z == nn[2]) return;
//   if (x != nn[0])
//     if (r == dp(x+1, y, z, 0) + dist[x][y][z][0]){
//       cout << 0 << "(" << dist[x][y][z][0] << ")"; rek(x+1, y, z, 0); return;
//     }
//   if (y != nn[1] && last != 0)
//     if (r == dp(x, y+1, z, 1) + dist[x][y][z][1]){
//       cout << 1 << "(" << dist[x][y][z][1] << ")"; rek(x, y+1, z, 1); return;
//     }
//   if (z != nn[2])
//     if (r == dp(x, y, z+1, 2) + dist[x][y][z][2]){
//       cout << 2 << "(" << dist[x][y][z][2] << ")"; rek(x, y, z+1, 2); return;
//     }
//   assert(false);
// }

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> s;
  REP(i,n)
    if (s[i] == 'V') a[i] = 0;
    else if (s[i] == 'K') a[i] = 1;
    else a[i] = 2;

  REP(i,n) ++nn[a[i]], vv[a[i]].pb(i);

  REP(x,nn[0]+1) REP(y,nn[1]+1) REP(z,nn[2]+1){

    if (x < nn[0]){
      int tmp = vv[0][x];
      int loc = vv[0][x];
      REP(xx,x) if (vv[0][xx] < loc) --tmp;
      REP(yy,y) if (vv[1][yy] < loc) --tmp;
      REP(zz,z) if (vv[2][zz] < loc) --tmp;
      dist[x][y][z][0] = tmp;
      // TRACE(x _ y _ z _ tmp);
    }

    if (y < nn[1]){
      int tmp = vv[1][y];
      int loc = vv[1][y];
      REP(xx,x) if (vv[0][xx] < loc) --tmp;
      REP(yy,y) if (vv[1][yy] < loc) --tmp;
      REP(zz,z) if (vv[2][zz] < loc) --tmp;
      dist[x][y][z][1] = tmp;
    }

    if (z < nn[2]){
      int tmp = vv[2][z];
      int loc = vv[2][z];
      REP(xx,x) if (vv[0][xx] < loc) --tmp;
      REP(yy,y) if (vv[1][yy] < loc) --tmp;
      REP(zz,z) if (vv[2][zz] < loc) --tmp;
      dist[x][y][z][2] = tmp;
    }
    
  }

  // TRACE(dist[2][1][1][1]);
  
  cout << dp(0, 0, 0, 2) << endl;
  // rek(0, 0, 0, 2); cout << endl;
  
  return 0;
}