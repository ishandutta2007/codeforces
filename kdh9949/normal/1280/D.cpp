#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define x first
#define y second

const int N = 3005;
const ll INF = ll(1e18);

int m, n, sz[N];
vector<int> e[N];
ll c[N];
pll d[N][N], nd[N];

void f(int x, int y){
  sz[x] = 1;
  d[x][0] = pll(0, c[x]);
  for(int i = 1; i < n; i++) d[x][i] = pll(-INF, -INF);
  for(int xx : e[x]){
    if(xx == y) continue;
    f(xx, x);
    for(int i = 0; i < sz[x]+sz[xx]; i++) nd[i] = pll(-INF, -INF);
    for(int i = 0; i < sz[x]; i++) for(int j = 0; j < sz[xx]; j++){
      pll A = d[x][i], B = d[xx][j];
      nd[i+j] = max(nd[i+j], pll(A.x+B.x, A.y+B.y));
      nd[i+j+1] = max(nd[i+j+1], pll(A.x+B.x+(B.y>0), A.y));
    }
    for(int i = 0; i < sz[x]+sz[xx]; i++) d[x][i] = nd[i];
    sz[x] += sz[xx];
  }
}

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> c[i];
  for(int i = 1, x; i <= n; i++){
    cin >> x;
    c[i] = x - c[i];
  }
  for(int i = 0, x, y; i < n-1; i++){
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  f(1, 0);
  /*
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < n; j++)
      cout << "d[" << i << "][" << j << "] = (" << d[i][j].x << "," << d[i][j].y << ")\n";
    cout << "-----\n";
  }
  */
  cout << (d[1][m-1].x + (d[1][m-1].y > 0)) << '\n';
  for(int i = 1; i <= n; i++) e[i].clear();
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--) solve();
}