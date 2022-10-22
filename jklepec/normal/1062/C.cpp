#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;

int add(int x, int y) {
  x +=y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}

const int MAXN = 1e5 + 5;

int p[MAXN], s[MAXN], pr[MAXN];;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, q; cin >> n >> q;

  p[1] = 1;
  s[1] = 1;

  FOR(i, 2, MAXN) {
    p[i] = add(s[i - 1], 1);
    s[i] = add(s[i - 1], p[i]);
  }

  REP(i, n) {
    char x; cin >> x;
    pr[i + 1] = pr[i];
    if(x == '1') {
      pr[i + 1] ++;
    }
  }


  while(q --) {
    int l, r; cin >> l >> r;

    int j = pr[r] - pr[l - 1];

    int sol = s[j];
    sol = add(sol, mul(s[r - l + 1 - j], s[j]));

    cout << sol << '\n';
  }


}