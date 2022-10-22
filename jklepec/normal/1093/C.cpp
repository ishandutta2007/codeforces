#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;

const ll inf = 1e18;

ll a[MAXN], b[MAXN], c[MAXN];

int main() {
  int n; cin >> n;

  ll lmin = 0, lmax = inf;

  REP(i, n / 2) {
    cin >> b[i];
    ll x, y;
    x = lmin;
    y = b[i] - x;
    if(y > lmax) {
      y = lmax;
      x = b[i] - y;
    }

    lmin = x;
    lmax = y;

    c[i] = x;
    c[n - i - 1] = y;
  }

  REP(i, n) {
    cout << c[i] << ' ';
  }
}