#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define point pair < ll, ll >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

ll ccw(pii a, pii b, pii c){
  return (ll)a.x*(b.y-c.y) + (ll)b.x*(c.y-a.y) + (ll)c.x*(a.y-b.y);
}

int n, p, q;
pii w[1000005];

int sign(ll a){
  if (a < 0) return -1;
  return !!a;
}

double Calc(point a, point b, point x){
  if (sign(a.x*x.y - a.y*x.x) * sign(b.x*x.y - b.y*x.x) == 1) return 1e9;
  double t = (double)(b.y*x.x-b.x*x.y) / (double)((a.x-b.x)*x.y - (a.y-b.y)*x.x);
  //TRACE(a.x _ a.y _ b.x _ b.y _ p _ q _ t);
  return (double)x.x / (double)(t*a.x + (1-t)*b.x);
}

int main(){
  cin >> n >> p >> q;
  REP(i,n) scanf("%d%d", &w[i].x, &w[i].y);

  sort(w, w+n);
  vector < pii > hull;
  REP(i,n){
    pii t = w[i];
    while (!hull.empty()){
      pii nt = hull.back();
      if (nt.y <= t.y){hull.pop_back(); continue;}
      if (hull.size() <= 1) break;
      pii nnt = hull[(int)hull.size()-2];
      if (ccw(t, nnt, nt) >= 0){hull.pop_back(); continue;}
      break;
    } hull.pb(t);
  }
  hull.insert(hull.begin(), {0, hull.front().y});
  hull.pb({hull.back().x, 0});

  for (auto x : hull) TRACE(x.x _ x.y);

  double R = 1e9;
  REP(i,hull.size()-1) R = min(R, Calc(hull[i], hull[i+1], {p, q}));
  printf("%.15lf\n", R);
  
  return 0;
}