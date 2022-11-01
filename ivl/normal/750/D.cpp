#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << setw(3) << setfill('0') << __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n;
int t[35];

bool bio[305][305][8][35];
bool mat[305][305];

void rek(int x, int y, int d, int c){
  if (c == n) return;
  if (d < 0) d += 8;
  if (d >= 8) d -= 8;
  if (c) x += dx[d], y += dy[d];
  if (bio[152+x][152+y][d][c]++) return;

  REP(i,t[c]) mat[152+x+i*dx[d]][152+y+i*dy[d]] = true;
  rek(x+(t[c]-1)*dx[d], y+(t[c]-1)*dy[d], d-1, c+1);
  rek(x+(t[c]-1)*dx[d], y+(t[c]-1)*dy[d], d+1, c+1);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> t[i];

  rek(0, 0, 0, 0);

  int sol = 0;
  REP(i,305) REP(j,305) if (mat[i][j]) ++sol;
  cout << sol << endl;

  return 0;
}