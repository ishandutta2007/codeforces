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

const int offset = (1<<20);

int n, k, a, b, q;

pii T[offset*2];

void update(int id, int lo, int hi, int p, int v){
  if (lo > p || hi < p) return;
  if (lo == hi){
    T[id].x += v;
    if (T[id].x > b) T[id].x = b;
    T[id].y += v;
    if (T[id].y > a) T[id].y = a;
    return;
  }
  int m = (lo+hi)/2;
  update(id*2, lo, m, p, v);
  update(id*2+1, m+1, hi, p, v);
  T[id] = {T[id*2].x+T[id*2+1].x, T[id*2].y+T[id*2+1].y};
}

pii query(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return {0, 0};
  if (lo >= slo && hi <= shi) return T[id];
  int m = (lo+hi) / 2;
  pii a = query(id*2, lo, m, slo, shi);
  pii b = query(id*2+1, m+1, hi, slo, shi);
  return {a.x+b.x, a.y+b.y};
}

int main(){

  cin >> n >> k >> a >> b >> q;

  REP(ttt,q){
    int t;
    cin >> t;
    if (t == 1){
      int x, y;
      cin >> x >> y;
      update(1, 0, offset-1, x, y);
    } else {
      int p;
      cin >> p;
      cout << query(1, 0, offset-1, 0, p-1).x + query(1, 0, offset-1, p+k, offset-1).y << endl;
    }
  }
  
  return 0;
}