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

class vektor{
public:
  pii x[20];
  int sz;
  vektor() : sz(0){}
  int size(){return sz;}
  void clear(){sz = 0;}
  void pb(pii t){x[sz++] = t;}
  pii& operator[](int t){return x[t];}
  pii& front(){return x[0];}
};

int loga1[6005];
void set1(int p){
  int v = p;
  p += 10;
  while (p < 6005){
    loga1[p] = max(loga1[p], v);
    p += p&-p;
  }
}
int get1(int p){
  p += 10;
  int r = -100;
  while (p){
    r = max(r, loga1[p]);
    p -= p&-p;
  } return r;
}

const int oo = 1000000;

int loga2[6005];
void set2(int p){
  int v = p;
  p = 4000-p;
  while (p < 6005){
    loga2[p] = min(loga2[p], v);
    p += p&-p;
  }
}
int get2(int p){
  p = 4000-p;
  int r = oo;
  while (p){
    r = min(r, loga2[p]);
    p -= p&-p;
  } return r;
}

int r, c, n, k;
int mat[3005][3005];

vector < int > E[3005];

ll cnt = 0;
int _ex[3010], *ex = _ex+5;
vektor v1, v2;
void add(int p){
  v1.clear(), v2.clear();
  ++ex[p];
  set1(p), set2(p);

  int tmp = 0;
  for (int it = p; it > -100; it = get1(it-1)){
    v1.pb({it, ex[it]});
    tmp += ex[it];
    if (tmp > k) break;
  } tmp = 0;
  for (int it = p; it < oo; it = get2(it+1)){
    v2.pb({it, ex[it]});
    tmp += ex[it];
    if (tmp > k) break;
  } v2.front().y = 0;

  REP(i,v1.size()-1) v1[i+1].y += v1[i].y;
  REP(i,v2.size()-1) v2[i+1].y += v2[i].y;

  int p1 = (int)v1.size()-2;
  int p2 = 0;

  if (p1 < 0) return;

  while (true){
    if (p2 >= (int)v2.size()-1) break;
    if (v1[p1].y + v2[p2].y < k){
      ++p2;
      if (p2 == (int)v2.size()) break;
    }
    if (v1[p1].y + v2[p2].y == k){
      cnt += (v1[p1].x - v1[p1+1].x) * (v2[p2+1].x - v2[p2].x);

      if (p1) --p1;
      else break;
    }
    if (v1[p1].y + v2[p2].y > k){
      if (p1 == 0) break;
      --p1;
    }
  }
  
}

int main(){

  cin >> r >> c >> n >> k;
  REP(i,n){
    int x, y;
    cin >> x >> y;
    --x, --y;
    ++mat[x][y];
    E[x].pb(y);
  }

  ll R = 0;
  REP(i,r){
    REP(t,6005) loga1[t] = -100;
    REP(t,6005) loga2[t] = oo;
    memset(_ex, 0, sizeof _ex);
    set1(-1), set2(-1);
    set1(c), set2(c);
    cnt = 0;
    FOR(j,i,r){
      for (auto t : E[j]) add(t);
      R += cnt;
    }
  }

  cout << R << endl;
  return 0;
}