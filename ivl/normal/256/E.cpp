#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int Mod = 777777777;

int add(int a, int b){a += b; if (a >= Mod) return a-Mod; return a;}
int mul(int a, int b){return (int)(((ll)a*b)%Mod);}

int n, m;
int good[3][3];

class Node{
public:
  bool bla;
  int mat[3][3];
  Node(int t = -1, bool ch = false){bla = ch; memset(mat, 0, sizeof mat); REP(i,3) mat[i][i] = (t == 0 || t == i+1);}
  int* operator[](int x){return mat[x];}
};
Node operator+(Node a, Node b){
  if (a.bla) return b;
  if (b.bla) return a;
  Node c;
  REP(i,3) REP(j,3) REP(k,3) if (good[k][j]) c[i][j] = add(c[i][j], a[i][k]);
  a = Node();
  REP(i,3) REP(j,3) REP(k,3) a[i][j] = add(a[i][j], mul(c[i][k], b[k][j]));
  return a;
}

const int offset = 1<<17;
Node T[offset*2];

void Set(int id, int lo, int hi, int p, int v){
  if (lo > p || hi < p) return;
  if (lo == hi){T[id] = v; return;}
  int mid = (lo+hi)/2;
  Set(id*2, lo, mid, p, v);
  Set(id*2+1, mid+1, hi, p, v);
  T[id] = T[id*2] + T[id*2+1];
}

Node Query(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return {-1, true};
  if (lo >= slo && hi <= shi) return T[id];
  int mid = (lo+hi)/2;
  return Query(id*2, lo, mid, slo, shi) + Query(id*2+1, mid+1, hi, slo, shi);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,3) REP(j,3) cin >> good[i][j];

  REP(i,n) Set(1, 0, offset-1, i, 0);

  REP(i,m){
    int p, v;
    cin >> p >> v, --p;
    Set(1, 0, offset-1, p, v);
    Node M = Query(1, 0, offset-1, 0, n-1);
    int bla = 0;
    REP(j,3) REP(k,3) bla = add(bla, M[j][k]);
    cout << bla << endl;
  }

  return 0;
}