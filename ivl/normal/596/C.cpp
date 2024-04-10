#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void imp(){cout << "NO\n"; exit(0);}

int n;
pii pt[100005];
int w[100005];

vector < int > _Vpt[200005], _Vw[200005];
vector < int > *Vpt = _Vpt+100002, *Vw = _Vw+100002;

int sol[100005];
pii sol2[100005];
int ind[100005];

map < pii, int > MM;
int& M(pii t){
  if (!MM.count(t)) MM[t] = 1000000000;
  return MM[t];
}

int min(int a, int b, int c){return min(min(a,b),c);}

int main(){
  cin >> n;
  REP(i,n) scanf("%d%d", &pt[i].x, &pt[i].y);
  REP(i,n) scanf("%d", w+i);

  REP(i,n) Vpt[pt[i].y-pt[i].x].pb(i);
  REP(i,n) Vw[w[i]].pb(i);

  FOR(i,-100001,100001) if (Vpt[i].size() != Vw[i].size()) imp();
  FOR(i,-100001,100001){
    sort(ALL(Vpt[i]), [&](int a, int b){return pt[a] < pt[b];});
    sort(ALL(Vw[i]));
    REP(j,Vpt[i].size()) sol[Vpt[i][j]] = Vw[i][j];
  }
  REP(i,n) sol2[sol[i]] = pt[i], ind[i] = i;

  sort(ind, ind+n, [&](int a, int b){if (pt[a].x != pt[b].x) return pt[a].x > pt[b].x; return pt[a].y > pt[b].y;});

  REP(i,n){
    int id = ind[i];
    int v = sol[id];
    pii t = pt[id];
    M(t) = min(v, M({t.x, t.y+1}), M({t.x+1, t.y}));
    //TRACE(i _ id _ v _ M(t));
    if (M(t) < v) imp();
  }
  
  cout << "YES\n";
  REP(i,n) printf("%d %d\n", sol2[i].x, sol2[i].y);
  cout << endl;
  return 0;
}