#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, l, k;
  cin >> n >> l >> k;
  string s;
  cin >> s;
  vi c(26);
  for (char x : s) c[x - 'a']++;
  int L = 0;
  vs res(n, string(l, 0));
  for (int j = 0; j < l; ++j) {
    int it = 0;
    for (int i = L; i < k; ++i) {
      while (c[it] == 0) ++it;
      --c[it];
      res[i][j] = it + 'a';
    }
    while (res[L][j] != res[k - 1][j]) ++L;
  }
  int it = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < l; ++j) if (!res[i][j]) {
    while (c[it] == 0) ++it;
    --c[it];
    res[i][j] = it + 'a';
  }
  for (int i = 0; i < n; ++i) cout << res[i] << '\n';
  return 0;
}