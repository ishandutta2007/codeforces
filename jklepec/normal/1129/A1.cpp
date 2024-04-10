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

const int MAXN = 500;
int mn[MAXN], cnt[MAXN];

int n;

int dist(int x, int y) {
  if(y >= x) return y - x;
  return n - x + y;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int m; cin >> n >> m;
  REP(i, n + 1) {
    mn[i] = 500;
  }
  REP(i, m) {
    int x, y; cin >> x >> y;
    cnt[x] ++;
    mn[x] = min(mn[x], dist(x, y));
  }

  FOR(i, 1, n + 1) {
    int sol = 0;
    FOR(j, 1, n + 1) {
      if(cnt[j] != 0) {
        sol = max(sol, (cnt[j] - 1) * n + dist(i, j) + mn[j]);
      }
    }
    cout << sol << " ";
  }
}