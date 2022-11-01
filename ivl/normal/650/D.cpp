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
int h[1<<20];

vector < pair < pii, int > > V;
int out[1<<20];

pii loga[1<<21];
void sett(int p, pii v){
  p += 5;
  for (; p < (1<<21); p += p&-p)
    loga[p] = max(loga[p], v);
}
pii get(int p){
  p += 5;
  pii r = {0, 0};
  for (; p; p -= p&-p)
    r = max(loga[p], r);
  return r;
}

int cnt[1<<20];
int back[1<<20];

int loc[1<<20];

int main(){
  //ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,n) scanf("%d", h+i);
  REP(i,m){
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    V.pb({{a, b}, i});
    loc[i] = a;
  } sort(V.begin(), V.end());

  vector < int > sazm;
  REP(i,n) sazm.pb(h[i]);
  REP(i,m) sazm.pb(V[i].x.y);
  sort(sazm.begin(), sazm.end());
  sazm.erase(unique(sazm.begin(), sazm.end()), sazm.end());
  REP(i,n) h[i] = 1+lower_bound(sazm.begin(), sazm.end(), h[i])-sazm.begin();
  REP(i,m) V[i].x.y = 1+lower_bound(sazm.begin(), sazm.end(), V[i].x.y)-sazm.begin();

  int poin = 0;
  REP(i,n){
    while (poin < m && V[poin].x.x == i){
      out[V[poin].y] += get(V[poin].x.y-1).x+1;
      ++poin;
    } sett(h[i], {get(h[i]-1).x+1, 0});
  } memset(loga, 0, sizeof loga);

  poin = m-1;
  for (int i = n-1; i >= 0; --i){
    while (poin >= 0 && V[poin].x.x == i){
      out[V[poin].y] += get((1<<20)-(V[poin].x.y+1)).x;
      --poin;
    } sett((1<<20)-h[i], {get((1<<20)-(h[i]+1)).x+1, 0});
  } memset(loga, 0, sizeof loga);

  REP(i,n){
    pii t = get(h[i]-1);
    back[i] = t.y;
    sett(h[i], {t.x+1, i+1});
  }
  poin = get(1<<20).y;
  while (poin){
    //TRACE(poin);
    ++cnt[poin-1];
    poin = back[poin-1];
  } memset(loga, 0, sizeof loga);

  int len = 0;

  REP(i,n){
    pii t = get(h[i]-1);
    back[i] = -t.y;
    sett(h[i], {t.x+1, -(i+1)});
  }
  poin = -get(1<<20).y;
  while (poin){ ++len;
    //TRACE(poin);
    ++cnt[poin-1];
    poin = back[poin-1];
  } memset(loga, 0, sizeof loga);

  REP(i,m) printf("%d\n", max(out[i], len - (cnt[loc[i]]==2)));
  
  return 0;
}