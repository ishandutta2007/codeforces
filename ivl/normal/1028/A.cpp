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

int n, m;
string mat[200];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,n) cin >> mat[i];
  int minx, miny; minx = miny = 1e9;
  int maxx, maxy; maxx = maxy = -1;

  REP(i,n) REP(j,m) if (mat[i][j] == 'B'){
    minx = min(minx, i);
    miny = min(miny, j);    
    maxx = max(maxx, i);
    maxy = max(maxy, j);    
  }

  cout << 1+(minx+maxx)/2 << " " << 1+(miny+maxy)/2 << endl;

  return 0;
}