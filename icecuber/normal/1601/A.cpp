#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> cnt(30);
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      for (int b = 0; b < 30; b++) {
        cnt[b] += v>>b&1;
      }
    }
    for (int k = 1; k <= n; k++) {
      int ok = 1;
      for (int b = 0; b < 30; b++) 
        ok &= (cnt[b]%k == 0);
      if (ok) cout << k << ' ';
    }
    cout << endl;
  }
}