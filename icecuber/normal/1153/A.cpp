#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, t;
  cin >> n >> t;
  int first = 1e9, ans = 1;
  for (int i = 0; i < n; i++) {
    int s, d;
    cin >> s >> d;
    int k = max(0, (t-s+d-1)/d);
    int board = s+k*d;
    if (board < first) {
      first = board;
      ans = i+1;
    }
  }
  cout << ans << endl;
}