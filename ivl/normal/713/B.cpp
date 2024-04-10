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

typedef pair < pii, pii > rect;

int n;
int CNT;
vector < rect > INPUT;

inline bool in(const rect &q, const rect &t){
  return q.x.x <= t.x.x && q.x.y <= t.x.y &&
    t.y.x <= q.y.x && t.y.y <= q.y.y;
}

int query(rect q){
  ++CNT;
  if (q.x.x < 1 || q.x.y < 1) assert(false);
  if (q.y.x > n || q.y.y > n) assert(false);

  /*{
    int r = 0;
    for (auto t : INPUT) if (in(q, t)) ++r;
    return r;
    }*/
  
  if (q.x.x > q.y.x || q.x.y > q.y.y) return 0;
  cout << "? " << q.x.x << " " << q.x.y << " " << q.y.x << " " << q.y.y << endl;
  int r;
  cin >> r;
  return r;
}

vector < rect > found;

bool exist(rect q){
  int r = query(q);
  for (auto t : found) if (in(q, t)) --r;
  return r;
}

void bs(rect &r, int &v, bool flag){
  int lo = 1, hi = n, mid;
  while (hi-lo > 1){
    mid = (lo+hi) / 2;
    v = mid;
    if (exist(r) == flag) hi = mid;
    else lo = mid;
  }

  v = lo; bool slo = exist(r);
  v = hi; bool shi = exist(r);
  if (!slo){v = hi; return;}
  if (!shi){v = lo; return;}
  if (flag) v = lo; else v = hi;
}

int main(){
  
  cin >> n;
  //INPUT.resize(2);
  //for (auto &t : INPUT) cin >> t.x.x >> t.x.y >> t.y.x >> t.y.y;

  REP(blatruc,2){
    rect r = {{1, 1}, {n, n}};
    bs(r, r.x.x, false);
    bs(r, r.x.y, false);
    bs(r, r.y.x, true);
    bs(r, r.y.y, true);
    found.pb(r);
    TRACE(r.x.x _ r.x.y _ r.y.x _ r.y.y);
  }

  TRACE(CNT);
  cout << "! ";
  for (auto t : found) cout << t.x.x << " " << t.x.y << " " << t.y.x << " " << t.y.y << " ";
  cout << endl;

  return 0;
}