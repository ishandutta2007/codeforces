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

const int Mod = 1000003;
class mint{
public:
  int x;
  mint(int y = 0) : x(y){}
};
mint operator+(mint a, mint b){a.x += b.x; if (a.x >= Mod) a.x -= Mod; return a;}
mint operator*(mint a, mint b){return (int)(((ll)a.x*b.x)%Mod);}
void operator+=(mint &a, mint b){a.x += b.x; if (a.x >= Mod) a.x -= Mod;}
void operator*=(mint &a, mint b){a.x = (int)(((ll)a.x*b.x)%Mod);}

class matrix{
public:
  mint mat[105][105];
  matrix(int x = 0){
    REP(i,105) REP(j,105) mat[i][j] = x * (i==j);
  }
  mint* operator[](int x){return mat[x];}
};

matrix operator*(matrix a, matrix b){
  matrix c;
  REP(i,105) REP(j,105) REP(k,105) c[i][j] += a[i][k] * b[k][j];
  return c;
}

void operator*=(matrix &a, matrix b){a = a * b;}

mint pot(mint a, int b){
  mint r = 1;
  while (b){
    if (b&1) r *= a;
    a *= a;
    b >>= 1;
  } return r;
}

matrix pot(matrix a, int b){
  matrix r = 1;
  while (b){
    if (b&1) r *= a;
    a *= a;
    b >>= 1;
  } return r;
}

inline mint f(int w, int h){ // broj histograma unutar w x h pravokutnika
  if (w < 0 || h < 0) return 0;
  return pot(mint(h+1), w);
}

inline mint g(int w, int h){ // isto ko f, samo sto je donji red cijeli poplocan
  return f(w, h-1);
}

int c, w, h;

int main(){
  ios_base::sync_with_stdio(false);

  cin >> c >> w >> h;

  vector < mint > start(w+1);
  REP(i,w+1) start[i] = f(i, h);

  if (c < w+1){cout << start[c].x << endl; return 0;}

  // REP(i,w+1) TRACE(i _ start[i].x);
  
  matrix bla;
  REP(i,w+1) REP(j,w) bla[i][j] = (i-1 == j);
  REP(i,w+1) bla[w-i][w] = g(i, h);

  // REP(i,w+1){REP(j,w+1) cout << bla[i][j].x << " "; cout << endl;}

  bla = pot(bla, c-w);
  mint r = 0;
  REP(i,w+1) r += start[i] * bla[i][w];
  cout << r.x << endl;

  return 0;
}