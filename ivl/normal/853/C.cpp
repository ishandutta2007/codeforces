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
typedef pair<ll, ll> pll;

int n, q;
int p[200005];
pair<pii, pii> upit[200005];
ll num[200005][3][3];

//           y               x
vector<pair<int, ll&>> v[200005];

int loga[200005];
void add(int x){
  for (x += 2; x < 200005; x += x & -x)
    ++loga[x];
}

int sum(int x){
  int sol = 0;
  for (x += 2; x; x -= x & -x)
    sol += loga[x];
  return sol;
}

void query(int x, int y, ll &r){
  if (x < 0 || y < 0){r = 0; return;}
  v[x].pb({y, r});
}

void rotate(ll m[3][3]){
  ll o[3][3];
  REP(i,3) REP(j,3) o[i][j] = m[j][2-i];
  REP(i,3) REP(j,3) m[i][j] = o[i][j];
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> q;
  REP(i,n) cin >> p[i+1];
  REP(i,q) cin >> upit[i].x.x >> upit[i].x.y >> upit[i].y.x >> upit[i].y.y;

  REP(i,q){
    REP(dx,3) REP(dy,3){
      int x;
      if (dx == 0) x = upit[i].x.x-1;
      if (dx == 1) x = upit[i].y.x;
      if (dx == 2) x = n;
      int y;
      if (dy == 0) y = upit[i].x.y-1;
      if (dy == 1) y = upit[i].y.y;
      if (dy == 2) y = n;
      query(x, y, num[i][dx][dy]);
    }
  }

  FOR(i,1,n+1){
    add(p[i]);
    for (auto x : v[i])
      x.y = sum(x.x);
  }

  REP(i,q){
    auto bla = num[i];
    REP(x,2) REP(y,2)
      bla[2-x][2-y] -= bla[1-x][2-y] + bla[2-x][1-y] - bla[1-x][1-y];
    bla[2][0] -= bla[1][0];
    bla[1][0] -= bla[0][0];
    bla[0][2] -= bla[0][1];
    bla[0][1] -= bla[0][0];
    // REP(x,3){REP(y,3) cout << bla[x][y] << " "; cout << endl;} cout << endl;
    ll sol = 0;
    sol += bla[1][1] * (bla[1][1]-1) / 2;
    sol += bla[1][1] * (bla[0][0] + bla[0][1] + bla[0][2] + bla[1][0] + bla[1][2] + bla[2][0] + bla[2][1] + bla[2][2]);
    bla[1][1] = 0;
    REP(truc,4){
      sol += bla[0][0] * (bla[1][2] + bla[2][2] + bla[2][1]);
      bla[0][0] = 0;
      rotate(bla);
    }
    REP(truc,4){
      sol += bla[1][0] * (bla[1][2] + bla[2][1] + bla[0][1]);
      bla[1][0] = 0;
      rotate(bla);
    }
    cout << sol << endl;
  }
  
  return 0;
}