#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

#define x first
#define y second
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

void no(){cout << "No" << endl; exit(0);}

int main(){
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  REP(i,n) REP(j,m) cin >> v[i][j];
  REP(i,n) REP(j,m){int tmp; cin >> tmp; v[i][j] ^= tmp;}

  REP(i,n) REP(j,m) if (v[i][j]){
    if (i == n-1 || j == m-1) no();
    REP(ii,2) REP(jj,2) v[i+ii][j+jj] = !v[i+ii][j+jj];
  }

  cout << "Yes" << endl;

  return 0;
}