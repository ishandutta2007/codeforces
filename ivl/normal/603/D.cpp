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

#define double long double

using namespace std;

class line{
public:
  int a, b, c;
};

const double ep = 1e-12;

class comp{
public:
  double x, y;
  comp(double xx = 0, double yy = 0) : x(xx), y(yy){}
  double dis(){return x*x+y*y;}
};

int n;
line in[2005];
vector < comp > v;

comp getpoint(line l){
  comp r;
  r.y = (double)(-2*l.b*l.c) / (double)(l.a*l.a + l.b*l.b);
  r.x = (double)(-2*l.a*l.c) / (double)(l.a*l.a + l.b*l.b);
  return r;
}

int cnt = 0;

vector < pair < pair < double, double >, pii > > v2;
vector < pair < pair < double, double >, pii > > vxx;

double nagib(comp a, comp b){
  return (a.y-b.y)/(a.x-b.x);
}

bool eq(double a, double b){
  if (a > b) swap(a, b);
  return b-a < ep;
}

ll func2(ll a){return a*(a-1) / 2;}

ll func(ll a){return a*(a-1)*(a-2) / 6;}

pair < double, double > pravac(comp a, comp b){
  double k = nagib(a, b);
  return {k, a.y - a.x * k};
}

bool eq(pair < double, double > a, pair < double, double > b){
  return eq(a.x, b.x) && eq(a.y, b.y);
}

int main(){

  cin >> n;
  REP(i,n) cin >> in[i].a >> in[i].b >> in[i].c, in[i].c *= -1;

  REP(i,n) v.pb(getpoint(in[i]));

  REP(i,n) if (v[i].dis() < ep) ++cnt;

  ll R = 0;

  //REP(i,v.size()) TRACE(v[i].x _ v[i].y);
  
  if (cnt == 2){
    R += (v.size()-2);
    REP(i,v.size()) if (v[i].dis() < ep){v.erase(v.begin()+i); break;}
  }

  REP(i,v.size()) REP(j,i){
    if (eq(v[i].x, v[j].x)) vxx.pb({{v[i].x, 0}, {i,j}});
    else v2.pb({pravac(v[i], v[j]), {i, j}});
  }

  sort(v2.begin(), v2.end());
  sort(vxx.begin(), vxx.end());

  for (int i = 0, j = 0; i < (int)v2.size(); i = j){
    while (j < (int)v2.size() && eq(v2[i].x, v2[j].x)) ++j;
    set < int > S;
    FOR(k,i,j) S.insert(v2[k].y.x), S.insert(v2[k].y.y);
    R += func(S.size());
    if (cnt < 2) continue;
    bool ex = false;
    for (auto x : S) if (v[x].dis() < ep) ex = true;
    if (ex) R += func2(S.size()-1);
  }
  
  swap(v2, vxx);
  for (int i = 0, j = 0; i < (int)v2.size(); i = j){
    while (j < (int)v2.size() && eq(v2[i].x, v2[j].x)) ++j;
    set < int > S;
    FOR(k,i,j) S.insert(v2[k].y.x), S.insert(v2[k].y.y);
    R += func(S.size());
    if (cnt < 2) continue;
    bool ex = false;
    for (auto x : S) if (v[x].dis() < ep) ex = true;
    if (ex) R += func2(S.size()-1);
  }

  cout << R << endl;
  
  return 0;
}