#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MAXN = 1e5 + 5;

int a[MAXN];
vector<int> v;

int main() {
  int n, m, k; cin >> n >> m >> k;
  REP(i, n) cin >> a[i];
  sort(a, a + n);

  REP(i, n - 1) {
    v.pb(a[i + 1] - a[i] - 1);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  int sol = a[n - 1] - a[0] + 1;
  REP(i, min((int) v.size(), k - 1)) {
    sol -= v[i];
  }

  cout << sol;

}