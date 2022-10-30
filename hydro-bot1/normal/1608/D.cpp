// Hydro submission #61cb072e776765cb52f8685c@1640695598569
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll

const int MOD = 998244353;

int qpow(int i, int j) {
  int a = 1;
  while (j) {
    if (j % 2)
      a = 1ll * a * i % MOD;
    i = 1ll * i * i % MOD;
    j >>= 1;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  bool c1 = 1, c2 = 1;
  for (int i = 0; i < n; i++) {
    c1 = c1 && (v[i] == "BW" || v[i] == "B?" || v[i] == "?W" || v[i] == "??");
    c2 = c2 && (v[i] == "WB" || v[i] == "W?" || v[i] == "?B" || v[i] == "??");
  }
  int dt2 = 1;
  for (int i = 0; i < n; i++) {
    int a = (v[i] == "BW" || v[i] == "B?" || v[i] == "?W" || v[i] == "??");
    int b = (v[i] == "WB" || v[i] == "W?" || v[i] == "?B" || v[i] == "??");
    dt2 = 1ll * dt2 * (a + b) % MOD;
  }
  int a = 0, b = 0, c = 0, d = 0, e = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == "BB")
      a++;
    if (v[i] == "WW")
      b++;
    if (v[i] == "B?" || v[i] == "?B")
      c++;
    if (v[i] == "W?" || v[i] == "?W")
      d++;
    if (v[i] == "??")
      e++;
  }
  if (!(0 <= b + d + e - a && b + d + e - a <= c + d + 2 * e)) {
    cout << 0 << endl;
    return 0;
  }
  int x = 1;
  for (int i = b + d + e - a + 1; i <= c + d + 2 * e; i++)
    x = 1ll * x * i % MOD;
  for (int j = 1; j <= c + d + 2 * e - (b + d + e - a); j++)
    x = 1ll * x * qpow(j, MOD - 2) % MOD;
  cout << ((x + MOD - dt2) % MOD + c1 + c2) % MOD << endl;
  return 0;
}