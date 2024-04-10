#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 100100;
const int MOD = 10007;

int n, a[MAXN];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> n;
  REP(i, n) cin >> a[i];
  sort(a, a + n);
  int ans = 0;
  REP(i, n) {
    int add = (ll)a[i] * a[n-1-i] % MOD;
    ans += add;
    ans %= MOD;
  }
  cout << ans << endl; 
  return 0;
}