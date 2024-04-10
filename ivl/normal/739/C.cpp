#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << setw(3) << setfill('0') << __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair < int, int > pii;
typedef long long ll;
typedef unsigned int uint;

int n;
int a[1<<19];
int m;

class node{
public:

  uint best;
  ll l, r;
  uint len;
  uint lbest, rbest;
  uint ld, rd;
  
} dummy;

void merge(const node &x, const node &y, node &r){
  if (y.best == 0){r = x; return;}
  if (x.best == 0){r = y; return;}

  r.best = x.best < y.best ? y.best : x.best;
  r.l = x.l;
  r.r = y.r;
  r.len = x.len+y.len;
  r.lbest = x.lbest;
  r.rbest = y.rbest;
  r.ld = x.ld;
  r.rd = y.rd;

  if (x.r < y.l){
    if (y.rd == y.len) r.rd = y.len+x.rd;
    if (y.rbest == y.len) r.rbest = y.len+x.rd;
    if (x.rd == x.len && y.lbest+x.len > r.lbest) r.lbest = y.lbest+x.len;
    if (x.rd+y.lbest > r.best) r.best = x.rd+y.lbest;
  }

  if (x.r > y.l){
    if (x.ld == x.len) r.ld = x.len+y.ld;
    if (x.lbest == x.len) r.lbest = x.len+y.ld;
    if (y.ld == y.len && x.rbest+y.len > r.rbest) r.rbest = x.rbest+y.len;
    if (x.rbest+y.ld > r.best) r.best = x.rbest+y.ld;
  }
    
}

const int offset = 1<<19;
node T[offset*2];
ll P[offset*2];

void prop(int id){
  if (!P[id]) return;
  ll val = P[id]; P[id] = 0;

  P[id*2] += val;
  P[id*2+1] += val;

  T[id*2].l += val;
  T[id*2].r += val;

  T[id*2+1].l += val;
  T[id*2+1].r += val;
  
}

void add(int id, int lo, int hi, int slo, int shi, ll val){
  if (lo > shi || hi < slo) return;
  if (lo >= slo && hi <= shi){
    P[id] += val;

    T[id].l += val;
    T[id].r += val;

    return;
  }
  int mid = (lo+hi)/2;
  prop(id);
  add(id*2, lo, mid, slo, shi, val);
  add(id*2+1, mid+1, hi, slo, shi, val);
  merge(T[id*2], T[id*2+1], T[id]);
}

void init(int id, int lo, int hi){
  if (lo == hi){
    if (lo >= n){
      T[id].best = 0;
      return;
    }
    T[id].best = 1;
    T[id].len = 1;
    T[id].l = T[id].r = a[lo];
    T[id].lbest = T[id].rbest = T[id].ld = T[id].rd = 1;
    return;
  }
  int mid = (lo+hi)/2;
  init(id*2, lo, mid);
  init(id*2+1, mid+1, hi);
  merge(T[id*2], T[id*2+1], T[id]);
}

int main(){
  ios_base::sync_with_stdio(false);

  dummy.best = 0;
  
  cin >> n;
  REP(i,n) cin >> a[i];
  init(1, 0, offset-1);
  cin >> m;
  REP(ttt,m){
    int l, r, d;
    cin >> l >> r >> d;
    --l, --r;
    add(1, 0, offset-1, l, r, d);

    cout << T[1].best << endl;
    
  }
  
  return 0;
}