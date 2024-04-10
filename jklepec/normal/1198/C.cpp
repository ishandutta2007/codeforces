#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 3e5 + 5, MAXM = 5e5 + 5;

int X[MAXM], Y[MAXM];
vector<pii> e[MAXN];

bool bio[MAXN], took[MAXM];
vector<int> matching;

int n, m;

void print_set() {
  cout << "IndSet\n";
  int cnt = n;
  FOR(i, 1, 3 * n + 1) {
    if(!bio[i]) {
      cout << i << " ";
      cnt --;
    }
    if(!cnt) break;
  }
  cout << '\n';
}

void solve() {
  cin >> n >> m;
  matching.clear();

  REP(i, m + 1) {
    took[i] = false;
  }
  REP(i, 3 * n + 1) {
    bio[i] = false;
    e[i].clear();
  }

  REP(i, m) {
    int x, y; cin >> x >> y;
    e[x].pb({y, i});
    e[y].pb({x, i});
    X[i] = x;
    Y[i] = y;
  }

  int next_to_take = 0;
  REP(i, n) {
    while(took[next_to_take]) next_to_take++;
    if(next_to_take >= m) {
      print_set();
      return;
    }
    matching.pb(next_to_take);

    bio[X[next_to_take]] = true;
    bio[Y[next_to_take]] = true;
    for(auto p: e[X[next_to_take]]) {
      took[p.se] = true;
    }
    for(auto p: e[Y[next_to_take]]) {
      took[p.se] = true;
    }
  }
  cout << "Matching\n";
  for(auto i: matching) {
    cout << i + 1 << " ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}