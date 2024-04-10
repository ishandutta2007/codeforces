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

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 4e5 + 5;

unordered_map<int, int> mapping;
int rev[MAXN];
int a[MAXN];

int sz[MAXN];

vector<int> ev[MAXN];

bool cmp(const int &aa, const int &bb) {
  if(sz[aa] == sz[bb]) return aa < bb;
  return sz[aa] > sz[bb];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  vector<int> v;

  int n; cin >> n;
  REP(i, n) {
    cin >> a[i];
    v.pb(a[i]);
  }

  sort(all(v));
  v.erase(unique(all(v)), v.end());

  int cookie = 0;
  REP(i, v.size()) {
    if(i && v[i] != v[i - 1]) {
      cookie ++;
    }
    rev[cookie] = v[i];
    mapping[v[i]] = cookie;
  }

  REP(i, n) {
    a[i] = mapping[a[i]];
    sz[a[i]] ++;
  }

  int diff = 0;
  REP(i, cookie + 5) {
    ev[sz[i]].pb(i);
    if(sz[i] != 0) diff ++;
  }

  int difi = diff;

  int sum = n;

  int best = 1;
  int M = 1;

  FOR(m, 1, n + 1) {
    if(m * m > n) break;
    for(int x: ev[m]) {
      sum -= m;
      diff --;
    }
    int ostatak = sum - diff * m;
    int tmp = n - ostatak;
    tmp -= tmp % m;
    if(tmp / m < m) continue;
    if(tmp >= best) {
      M = m;
      best = tmp;
    }
  }

  vector<int> sol;

  REP(i, cookie + 5) {
    REP(j, min(sz[i], M)) {
      sol.pb(i);
    }
  }
  while(sol.size() > best) sol.pop_back();

  REP(i, cookie + 5) sz[i] = 0;
  REP(i, sol.size()) {
    sz[sol[i]] ++;
  }
  sort(all(sol), cmp);

  vector<vector<int>> print;
  print.resize(M);
  REP(i, M) print[i].resize(best / M);

  cout << best << endl;
  cout << M _ best / M << endl;
  assert(best / M >= M);
  assert(best % M == 0);
  assert(best <= n);
  assert(sol.size() >= best);

  REP(i, best / M) REP(j, M) {
    int k = i * M + j;
    int r = j;
    int c = (i + j) % (best / M);
    print[r][c] = sol[k];
  }

  REP(i, M) {
    REP(j, best / M) cout << rev[print[i][j]] << " ";
    cout << endl;
  }
}