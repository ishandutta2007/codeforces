#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k > (n+1)/2) {
      cout << -1 << endl;
      continue;
    }
    vector<string> ans(n, string(n,'.'));
    for (int i = 0; i < k; i++)
      ans[i*2][i*2] = 'R';
    for (string s : ans) cout << s << endl;
  }
}