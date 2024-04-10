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

int n, k;
int a[200005];
vector < int > E[200005];

int LIMIT;

int par[200005];
pii down[200005];
pii up[200005];
void BuildDown(int id, int p){
  par[id] = p;
  int sum = 1, sumw = 1, best = 0;
  for (auto x : E[id]) if (x != p){
      BuildDown(x, id);
      pii t = down[x];
      sum += t.x;
      if (t.x == t.y) sumw += t.x;
      else best = max(best, t.y);
    }
  down[id] = {sum, sumw + best};
  if (a[id] < LIMIT) down[id].y = 0;
}

void BuildUp(int id, int p){
  pii u = up[id];
  vector < int > v;
  for (auto x : E[id]) if (x != p) v.pb(x);
  int n = (int)v.size();
  vector < pii > lt(n), rt(n);
  vector < int > ls(n), rs(n);

  REP(i,n-1){
    pii t = down[v[i]];
    ls[i+1] = t.x;
    if (t.x == t.y) lt[i+1].x = t.x;
    else lt[i+1].y = t.y;
    lt[i+1].x += lt[i].x;
    lt[i+1].y = max(lt[i+1].y, lt[i].y);
    ls[i+1] += ls[i];
  }
  
  for (int i = n-1; i > 0; --i){
    pii t = down[v[i]];
    rs[i-1] = t.x;
    if (t.x == t.y) rt[i-1].x = t.x;
    else rt[i-1].y = t.y;
    rt[i-1].x += rt[i].x;
    rt[i-1].y = max(rt[i-1].y, rt[i].y);
    rs[i-1] += rs[i];
  }

  REP(i,n){
    up[v[i]].x = u.x + ls[i] + rs[i] + 1;
    int sum = rt[i].x + lt[i].x + 1, best = max(rt[i].y, lt[i].y);
    if (u.x == u.y) sum += u.x;
    else best = max(best, u.y);
    up[v[i]].y = sum+best;
  }

  REP(i,n) if (a[id] < LIMIT) up[v[i]].y = 0;
  REP(i,n) BuildUp(v[i], id);
}

int main(){

  cin >> n >> k;
  REP(i,n) scanf("%d", a+i);
  REP(i,n-1){
    int u, v;
    scanf("%d%d", &u, &v), --u, --v;
    E[u].pb(v);
    E[v].pb(u);
  }

  int lo = 0, hi = 1000000;
  while (lo != hi){
    LIMIT = (lo+hi+1) / 2;
        
    BuildDown(0, 0);
    up[0] = {0, 0};
    BuildUp(0, 0);

    int ms = -1;
    REP(i,n){
      if (a[i] < LIMIT) continue;
      int cs = 1, best = 0;
      for (auto x : E[i]) if (x != par[i]){
	  if (down[x].x == down[x].y) cs += down[x].x;
	  else best = max(best, down[x].y);
	} 
      if (up[i].x == up[i].y) cs += up[i].x;
      else best = max(best, up[i].y);
      ms = max(ms, cs+best);
    } 
    
    if (ms < k) hi = LIMIT-1;
    else lo = LIMIT;
  } cout << lo << endl;
  
  return 0;
}