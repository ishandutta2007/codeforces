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
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (int) ((ll) x * y % mod);
}
int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}

ll sol;

const int MAXN = 5e5 + 5;

ll cnt[MAXN];
ll pref[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, k; cin >> n >> k;

  string a, b; cin >> a >> b;

  int i = 0;
  while(i < n && a[i] == b[i]) {
    ++i;
    ++sol;
  }

  sol += (n - i);
  k --;
  if(k) {
    sol += (n - i);
    k --;
  }

  FOR(j, i + 1, n) {
    if(a[j] == 'a') {
      cnt[n - j] ++;
    }
    if(b[j] == 'b') {
      cnt[n - j] ++;
    }
  }

  for(int v = n; v >= 0; --v) {
    pref[v] += pref[v + 1];
    cnt[v] += pref[v];

    ll uz = min((ll) k, cnt[v]);

    sol += uz * v;
    pref[v - 1] += uz;

    k -= uz;
  }

  cout << sol << endl;
}