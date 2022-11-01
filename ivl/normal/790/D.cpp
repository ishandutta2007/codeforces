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
int t[2][300005];

ll pref[4][300005]; // suma [0, x)
int nxt[4][300005];
int low[4][300005];

int slow(int x){
  static int memo[300005];
  static bool bio[300005];
  int &r = memo[x];
  if (bio[x]++) return r;
  r = 0;
  if (x == n) return r;
  if (nxt[3][x] != -1) r = max(r, 1+slow(nxt[3][x]));
  r = max(r, slow(x+1));

  int a = x, b = x, cnt = 0;
  while (true){
    if (low[1][a] == -1 && low[2][b] == -1) break;
    else if (low[1][a] == -1) b = low[2][b];
    else if (low[2][b] == -1) a = low[1][a];
    else if (low[1][a] < low[2][b]) a = low[1][a];
    else b = low[2][b];
    ++cnt;
    r = max(r, cnt+slow(max(a, b)));
    if (a != x && b != x && cnt+slow(min(a, b)) <= r) break;
  }

  return r;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,2) REP(j,n) cin >> t[i][j];
  
  REP(i,2) REP(j,n) pref[i+1][j+1] = t[i][j], pref[3][j+1] += t[i][j];
  REP(i,4) REP(j,n) pref[i][j+1] += pref[i][j];

  memset(nxt, -1, sizeof nxt);
  memset(low, -1, sizeof low);
  
  FOR(i,1,4){
    map<ll, int> M;
    M[pref[i][n]] = n;
    for (int j = n-1; j >= 0; --j){
      if (M.count(pref[i][j])) nxt[i][j] = M[pref[i][j]];
      M[pref[i][j]] = j;
    }
  }

  // FOR(i,1,4){REP(j,n) cout << nxt[i][j] << " "; cout << endl;}

  FOR(i,1,4){
    for (int j = n-1; j >= 0; --j){
      if (low[i][j+1] == -1){low[i][j] = nxt[i][j]; continue;}
      if (nxt[i][j] == -1){low[i][j] = low[i][j+1]; continue;}
      low[i][j] = min(low[i][j+1], nxt[i][j]);
    }
  }

  cout << slow(0) << endl;
  
  return 0;
}