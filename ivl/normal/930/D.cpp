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

const int oo = 5e8;

int n;
pii pt[100005];

void rotate45(vector<pii> &v){
  for (auto &p : v)
    p = {(p.x + p.y) / 2, (p.x - p.y) / 2};
}

void rotate90(vector<pii> &v){
  for (auto &p : v)
    p = {-p.y, p.x};
}

// assumes up = I quadrant orientation
void simplify(vector<pii> &v){
  sort(v.begin(), v.end());
  vector<pii> tmp = {v.front()};
  for (auto t : v)
    if (t.y < tmp.back().y) tmp.pb(t);
  v = tmp;
}

template<class a, class b>
ostream& operator<<(ostream& out, pair<a, b> p){
  return out << "(" << p.x << " " << p.y << ")";
}

template<class T>
ostream& operator<<(ostream& out, vector<T> v){
  for (auto t : v) out << t << " ";
  return out;
}

ll solve(vector<pii> all){
  if (all.empty()) return 0;

  vector<pii> up, down, left, right;
  for (auto p : all){
    up.pb({p.x+1, p.y});
    down.pb({p.x-1, p.y});
    left.pb({p.x, p.y-1});
    right.pb({p.x, p.y+1});
  }
  rotate45(up);
  rotate45(down);
  rotate45(left);
  rotate45(right);

  simplify(up);

  rotate90(down);
  rotate90(down);
  simplify(down);
  rotate90(down);
  rotate90(down);
  sort(down.begin(), down.end());
  
  rotate90(left);
  rotate90(left);
  rotate90(left);
  simplify(left);
  rotate90(left);
  sort(left.begin(), left.end());

  rotate90(right);
  simplify(right);
  rotate90(right);
  rotate90(right);
  rotate90(right);
  sort(right.begin(), right.end());

  // TRACE(up);
  // TRACE(down);
  // TRACE(left);
  // TRACE(right);

  ll sol = 0;
  int pos = -oo;
  int state[4] = {+oo, down[0].y, left[0].y, -oo};
  vector<pair<pii, int>> sweep;

  REP(i,up.size()) sweep.pb({up[i], 0});

  REP(i,down.size())
    if (i != (int)down.size()-1) sweep.pb({{down[i].x+1, down[i+1].y}, 1});
    else sweep.pb({{down[i].x+1, -oo}, 1});

  REP(i,left.size())
    if (i != (int)left.size()-1) sweep.pb({{left[i].x+1, left[i+1].y}, 2});
    else sweep.pb({{left[i].x+1, +oo}, 2});  

  REP(i,right.size()) sweep.pb({right[i], 3});
  
  sort(sweep.begin(), sweep.end());
  for (int i = 0, j = 0; i < (int)sweep.size(); i = j){
    // TRACE(state[0] _ state[1] _ state[2] _ state[3]);
    int height = min(state[1], state[3]) - max(state[0], state[2]) + 1;
    // TRACE(height);
    sol += (ll)(sweep[i].x.x - pos) * max(height, 0);
    while (j < (int)sweep.size() && sweep[i].x.x == sweep[j].x.x) ++j;
    FOR(k,i,j) state[sweep[k].y] = sweep[k].x.y;
    pos = sweep[i].x.x;
  }

  return sol;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> pt[i].x >> pt[i].y;

  vector<pii> parnepar[2];
  // guarantees odd sum, therefore even relevants pts
  REP(i,n) parnepar[(pt[i].x+pt[i].y+oo)%2].pb({pt[i].x - (~pt[i].x+pt[i].y+oo)%2, pt[i].y});
  cout << solve(parnepar[0]) + solve(parnepar[1]) << endl;

  return 0;
}