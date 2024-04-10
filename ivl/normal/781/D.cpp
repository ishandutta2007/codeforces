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

const int D = 500;
const int oo = 1e9;
const ll ool = (ll)oo * oo;

int n, m;
bool mat[D][D][2];

typedef bitset<D> matrix[D];

void mul(const matrix &a, const matrix &bb, matrix &c){
  static matrix b;
  REP(i,D) REP(j,D) b[i][j] = bb[j][i];
  REP(i,D) REP(j,D) c[i][j] = (a[i] & b[j]).any();
}

bool empty(const matrix &a){
  REP(i,D) if (a[i].any()) return false;
  return true;
}

void copy(matrix &a, const matrix &b){
  REP(i,D) a[i] = b[i];
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  n = 500;
  REP(i,m){
    int u, v, t;
    cin >> u >> v >> t;
    mat[u-1][v-1][t] = true;
  }
  // REP(i,n) REP(j,n) REP(k,2) mat[i][j][k] = true;
  
  matrix A, B;
  matrix tA, tB;
  
  REP(i,D) REP(j,D)
    if (mat[i][j][0]) A[i][j] = 1;
    else A[i][j] = 0;

  REP(i,D) REP(j,D)
    if (mat[i][j][1]) B[i][j] = 1;
    else B[i][j] = 0;

  matrix _vA[61], _vB[61];
  matrix *vA = _vA, *vB = _vB;

  REP(i,61){
    copy(vA[i], A);
    copy(vB[i], B);
    mul(A, B, tA);
    mul(B, A, tB);
    copy(A, tA);
    copy(B, tB);
  }

  if (!empty(vA[60])){cout << -1 << endl; return 0;}

  matrix C;
  REP(i,D) C[i][i] = 1;
  ll sol = 0;

  for (int id = 59; id >= 0; --id){
    mul(C, vA[id], tA);
    if (empty(tA)) continue;
    copy(C, tA);
    sol += (1LL << id);
    swap(vA, vB);
  }

  if (sol > ool) sol = -1;
  cout << sol << endl;
    
  return 0;
}