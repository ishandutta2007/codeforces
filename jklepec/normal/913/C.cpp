#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2005;
ll c[MAXN];
ll manja[MAXN];

ll cost;

bool ok[MAXN];

int main() {
  ll n, L; cin >> n >> L;

  REP(i, n) {
    cin >> c[i];
  }

  FOR(i, 1, n) {
    c[i] = min(c[i], c[i - 1] * 2);
  }

  FOR(i, n, 30) {
    c[i] = c[i - 1] * 2;
  }

  manja[29] = c[29];
  manja[30] = manja[29] * 2;

  for(int i = 28; i >= 0; --i) {
    if(manja[i + 1] <= c[i]) {
      ok[i] = true;
    }
    manja[i] = min(c[i], manja[i + 1]);
  }


  ll fin = 1e18 * 5;
  ll sol = 0;

  for(int log = 29; log >= 0; --log) {
    if(L >= (1 << log)) {
      fin = min(fin, sol + manja[log + 1]);
      if(ok[log]) {
        sol += manja[log];
        break;
      }
      sol += min(c[log], manja[log]);
      L -= (1 << log);
    }

  }

  cout << min(fin,sol);
}