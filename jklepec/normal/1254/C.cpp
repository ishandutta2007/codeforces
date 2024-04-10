#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define TRACE(x) cerr << #x << "  " << x << endl
template<typename T1, typename T2>inline void minaj(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void maxaj(T1 &x, T2 y) { x = (x < y ? y: x);}

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const ll inf = 1e18;
const int MAXN = 1005;

ll ask_area(int x, int y, int z) {
  cout << "1 " << x+1 _ y+1 _ z+1 << endl;
  ll ret; cin >> ret;
  return ret;
}

int ask_ccw(int x, int y, int z) {
  cout << "2 " << x+1 _ y+1 _ z+1 << endl;
  int ret; cin >> ret;
  return ret;
}

vector<int> L, R;
vector<int> sol;

ll area[MAXN];

bool cmp(const int &aa, const int &bb) {
  return area[aa] < area[bb];
}

void solve(int A, int B, vector<int> &v) {
  for(auto i: v) {
    area[i] = ask_area(A, B, i);
  }
  sort(all(v), cmp);
  vector<int> lf, rt;
  REP(i, (int) v.size()) {
    if(i + 1 == (int) v.size()) {
      lf.pb(v[i]);
    }
    else if(ask_ccw(A, v[i], v[i + 1]) == -1) {
      lf.pb(v[i]);
    }
    else {
      rt.pb(v[i]);
    }
  }

  sol.pb(A);
  for(auto x: lf) {
    sol.pb(x);
  }
  reverse(all(rt));
  for(auto x: rt) {
    sol.pb(x);
  }
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  FOR(i, 2, n) {
    int tmp = ask_ccw(0, 1, i);
    if(tmp == 1) {
      L.pb(i);
    }
    else {
      R.pb(i);
    }
  }

  solve(0, 1, L);
  solve(1, 0, R);

  reverse(all(sol));
  int poc = 0;
  FOR(i, 1, n) if(sol[i] == 0) poc = i;
  cout << 0 << " ";
  REP(i, n) {
    cout << sol[(poc + i) % n]+1 << " ";
  }
  cout << endl;
}