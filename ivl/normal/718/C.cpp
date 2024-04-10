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

const int Mod = 1000000007;
int add(int x, int y){x += y; if (x >= Mod) return x-Mod; return x;}
int mul(int x, int y){return (int)((ll)x*y%Mod);}

class matrix{
public:
  int mat[2][2];
  int* operator[](int x){return mat[x];}
} I = {1, 0, 0, 1}, F = {1, 1, 1, 0};

matrix operator*(matrix a, matrix b){
  matrix c;
  REP(i,2) REP(j,2) c[i][j] = 0;
  REP(i,2) REP(j,2) REP(k,2) c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
  return c;
}

matrix operator+(matrix a, matrix b){
  matrix c;
  REP(i,2) REP(j,2) c[i][j] = 0;
  REP(i,2) REP(j,2) c[i][j] = add(a[i][j], b[i][j]);
  return c;
}

matrix operator^(matrix a, int x){
  matrix r = I;
  while (x){
    if (x&1) r = r*a;
    a = a*a, x >>= 1;
  } return r;
}

void operator*=(matrix &a, matrix b){a = a*b;}
void operator+=(matrix &a, matrix b){a = a+b;}
void operator^=(matrix &a, int b){a = a^b;}

int n, m;
int a[1000005];

const int offset = 1<<17;
matrix T[2*offset];
matrix P[2*offset];

void init(int id, int lo, int hi){
  P[id] = I;
  if (lo == hi){
    T[id] = F^a[lo];
    return;
  }
  int mid = (lo+hi)/2;
  init(id*2, lo, mid);
  init(id*2+1, mid+1, hi);
  T[id] = T[id*2] + T[id*2+1];
}

void propagiraj(int id){
  T[id*2] *= P[id];
  T[id*2+1] *= P[id];
  P[id*2] *= P[id];
  P[id*2+1] *= P[id];
  P[id] = I;
}

matrix query(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return {0, 0, 0, 0};
  if (lo >= slo && hi <= shi) return T[id];
  propagiraj(id);
  int mid = (lo+hi)/2;
  return query(id*2, lo, mid, slo, shi) + query(id*2+1, mid+1, hi, slo, shi);
}

void update(int id, int lo, int hi, int slo, int shi, matrix M){
  if (lo > shi || hi < slo) return;
  if (lo >= slo && hi <= shi){
    T[id] *= M;
    P[id] *= M;
    return;
  }
  propagiraj(id);
  int mid = (lo+hi)/2;
  update(id*2, lo, mid, slo, shi, M);
  update(id*2+1, mid+1, hi, slo, shi, M);
  T[id] = T[id*2] + T[id*2+1];
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,n) cin >> a[i];
  init(1, 0, offset-1);

  REP(i,m){
    // TRACE(i);
    int type;
    cin >> type;
    if (type == 1){
      int l, r, x;
      cin >> l >> r >> x;
      update(1, 0, offset-1, l-1, r-1, F^x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(1, 0, offset-1, l-1, r-1)[0][1] << endl;
    }
  }

  return 0;
}