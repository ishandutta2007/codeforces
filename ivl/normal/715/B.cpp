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
typedef pair < int, int > pii;

void no(){cout << "NO\n"; exit(0);}

const int oo = 1e9;
const ll ool = 1e18;

int n, m, l, s, t;
vector < int > E[1005];

ll mat[1005][1005];

vector < pii > ch;

ll d[1005];
set < pair < ll, int > > S;
ll dist(){
  REP(i,n) d[i] = ool;
  d[s] = 0;
  S.insert({d[s], s});
  while (!S.empty()){
    int curr = (int)S.begin()->y; S.erase(S.begin());
    for (auto p : E[curr]) if (d[p] > d[curr]+mat[curr][p]){
	S.erase({d[p], p});
	d[p] = d[curr]+mat[curr][p];
	S.insert({d[p], p});
      }
  } return d[t];
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> l >> s >> t;
  memset(mat, -1, sizeof mat);
  REP(i,m){int u, v, w; cin >> u >> v >> w; E[u].pb(v); E[v].pb(u); mat[u][v] = mat[v][u] = w;}

  REP(i,n) REP(j,i) if (mat[i][j] == 0) ch.pb({i, j});
  for (auto p : ch) mat[p.x][p.y] = mat[p.y][p.x] = 1;
  if (dist() > l) no();

  int lo = 0, hi = (int)ch.size(), mid;
  while (lo != hi){
    mid = (lo+hi+1)/2;
    REP(i,mid) mat[ch[i].x][ch[i].y] = mat[ch[i].y][ch[i].x] = oo+55;
    FOR(i,mid,ch.size()) mat[ch[i].x][ch[i].y] = mat[ch[i].y][ch[i].x] = 1;
    if (dist() <= l) lo = mid;
    else hi = mid-1;
  }

  REP(i,lo) mat[ch[i].x][ch[i].y] = mat[ch[i].y][ch[i].x] = oo+55;
  FOR(i,lo,ch.size()) mat[ch[i].x][ch[i].y] = mat[ch[i].y][ch[i].x] = 1;

  if (lo != (int)ch.size()){
    int a = ch[lo].x, b = ch[lo].y;
    mat[a][b] = mat[b][a] = l-dist()+1;
  }

  if (dist() != l) no();
  cout << "YES\n";
  REP(i,n) REP(j,i) if (mat[i][j] != -1) cout << i << " " << j << " " << mat[i][j] << endl;

  return 0;
}