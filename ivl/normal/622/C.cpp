#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

class Node{
public:
  pii a, b;
  Node(){a = b = {-1, -1};}
  Node(int t, int p){a = {t, p}; b = {-1, -1};}
};
bool operator==(Node a, Node b){return a.a == b.a && a.b == b.b;}
Node operator+(Node a, Node b){
  if (b == Node()) return a;
  if (a == Node()) return b;
  if (a.b != pii{-1, -1}) return a;
  if (b.b != pii{-1, -1}) return b;
  if (a.a.x == b.a.x) return a;
  a.b = b.a; return a;
}

const int offset = 1<<20;

int n, m;
int a[offset*2];

Node T[offset*2];
void Build(int id, int lo, int hi){
  if (lo == hi){T[id] = Node(a[lo], lo+1); return;}
  int mid = (lo+hi)/2;
  Build(id*2, lo, mid);
  Build(id*2+1, mid+1, hi);
  T[id] = T[id*2] + T[id*2+1];
}

Node Get(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return Node();
  if (lo >= slo && hi <= shi) return T[id];
  int mid = (lo+hi) / 2;
  return Get(id*2, lo, mid, slo, shi) + Get(id*2+1, mid+1, hi, slo, shi);
}

int main(){
  cin >> n >> m;
  REP(i,n) scanf("%d", a+i);
  Build(1, 0, offset-1);
  REP(i,m){
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x), --l, --r;
    Node A = Get(1, 0, offset-1, l, r);
    if (A.a.x == x) printf("%d\n", A.b.y);
    else printf("%d\n", A.a.y);
  }
  return 0;
}