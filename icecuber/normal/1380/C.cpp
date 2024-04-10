#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      a[i] = (x+v-1)/v;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int has = 0;
    for (int i = 0; i < n; i++) {
      has++;
      if (has >= a[i]) ans++, has = 0;
    }
    cout << ans << endl;
  }
}