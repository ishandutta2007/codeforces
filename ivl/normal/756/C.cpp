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

int m;
int p[100005];
int t[100005];
int x[100005];

const int offset = 1<<17;
pii T[offset*2];
int Val[offset];

void init(int id, int lo, int hi){
  T[id] = {0, 0};
  if (lo == hi) return;
  int mid = (lo+hi)/2;
  init(id*2, lo, mid);
  init(id*2+1, mid+1, hi);
}

pii merge(pii a, pii b){
  pii c = {a.x, b.y};
  if (a.y > b.x) c.y += a.y - b.x;
  else c.x += b.x - a.y;
  return c;
}

void Set(int id, int lo, int hi, int pp, pii v){
  if (lo > pp || hi < pp) return;
  if (lo == hi){T[id] = v; return;}
  int mid = (lo+hi)/2;
  Set(id*2, lo, mid, pp, v);
  Set(id*2+1, mid+1, hi, pp, v);
  T[id] = merge(T[id*2], T[id*2+1]);
}

int Query(int id, int lo, int hi, int pc){
  if (lo == hi){
    if (pc) return -1;
    if (T[id].y == 0) return -1;
    return Val[lo];
  }

  int mid = (lo+hi)/2;
  pii tmp = T[id*2+1];
  if (tmp.y > pc) return Query(id*2+1, mid+1, hi, pc);
  pc -= tmp.y;
  pc += tmp.x;
  return Query(id*2, lo, mid, pc);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> m;
  REP(i,m){cin >> p[i] >> t[i]; --p[i]; if (t[i] == 1) cin >> x[i];}

  init(1, 0, offset-1);

  REP(i,m){
    pii com;
    if (t[i] == 0) com = {1, 0};
    else com = {0, 1}, Val[p[i]] = x[i];
    Set(1, 0, offset-1, p[i], com);
    cout << Query(1, 0, offset-1, 0) << endl;
  }
  
  return 0;
}