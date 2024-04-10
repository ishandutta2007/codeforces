// Hydro submission #61cb06f8af89a7cb7f638d40@1640755273977
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

const int MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    int A = a, B = b;
    if (a + b > n - 2 || abs(a - b) > 1) {
      cout << -1 << endl;
    } else {
      string s;
      if (a == b) {
        for (int i = 0; i <= a; i++)
          s += "BR";
        while (s.size() != n)
          s += "R";
      }
      if (a == b + 1) {
        for (int i = 0; i < a; i++)
          s += "RB";
        while (s.size() != n)
          s += "R";
      }
      if (a == b - 1) {
        for (int i = 0; i < b; i++)
          s += "BR";
        while (s.size() != n)
          s += "B";
      }
      int mi = 1, mx = 0;
      vector<int> ans;
      for (char c : s)
        if (c == 'B')
          ans.pb(++mx);
        else
          ans.pb(--mi);
      for (int i : ans)
        cout << i - mi + 1 << " ";
      cout << endl;
    }
  }
  return 0;
}