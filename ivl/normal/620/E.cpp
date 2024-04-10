#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m;
int c[1<<20];
vector < int > E[1<<20];

int cnt = 0;
int clr[1<<20];
int wh[1<<20];
int fin[1<<20];
void init(int id, int p){
  wh[id] = cnt++;
  clr[wh[id]] = c[id];
  for (auto x : E[id]) if (x != p) init(x, id);
  fin[wh[id]] = cnt-1;
}

const int offset = 1<<20;
ll T[2*offset];
ll P[2*offset];
void init2(int id, int lo, int hi){
  if (lo == hi){T[id] = (1LL<<clr[lo]); return;}
  int mid = (lo+hi)/2;
  init2(id*2, lo, mid);
  init2(id*2+1, mid+1, hi);
  T[id] = (T[id*2] | T[id*2+1]);
}

void prop(int id){
  if (!P[id]) return;
  T[id*2] = P[id*2] = P[id];
  T[id*2+1] = P[id*2+1] = P[id];
  P[id] = 0;
}

void Set(int id, int lo, int hi, int slo, int shi, int cv){
  if (lo > shi || hi < slo) return;
  if (lo >= slo && hi <= shi){T[id] = P[id] = (1LL<<cv); return;}
  prop(id);
  int mid = (lo+hi)/2;
  Set(id*2, lo, mid, slo, shi, cv);
  Set(id*2+1, mid+1, hi, slo, shi, cv);
  T[id] = (T[id*2] | T[id*2+1]);
}

void Set(int lo, int hi, int cv){Set(1, 0, offset-1, lo, hi, cv);}

ll Get(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return 0;
  if (lo >= slo && hi <= shi) return T[id];
  prop(id);
  int mid = (lo+hi)/2;
  return (Get(id*2, lo, mid, slo, shi) | Get(id*2+1, mid+1, hi, slo, shi));
}

ll Get(int lo, int hi){return Get(1, 0, offset-1, lo, hi);}

int main(){
  //ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,n) scanf("%d", c+i);
  REP(i,n-1){
    int x, y;
    scanf("%d%d", &x, &y), --x, --y;
    E[x].pb(y);
    E[y].pb(x);
  } init(0, 0);
  init2(1, 0, offset-1);

  REP(i,m){
    int t;
    scanf("%d", &t);
    if (t == 1){
      int vk, ck;
      scanf("%d%d", &vk, &ck), vk = wh[vk-1];
      Set(vk, fin[vk], ck);
    } else {
      int vk;
      scanf("%d", &vk), vk = wh[vk-1];
      printf("%d\n", __builtin_popcountll(Get(vk, fin[vk])));
    }
  }
  
  return 0;
}