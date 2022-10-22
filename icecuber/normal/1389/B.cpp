#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    vector<int> acc(n+1);
    for (int i = 0; i < n; i++) {
      acc[i+1] = acc[i]+a[i];
    }
    k++;
    int ans = acc[k];
    for (int i = 0; i+1 < n; i++) {
      int ma = max(min((k-i)/2, z), 0);
      int score = (a[i]+a[i+1])*ma+acc[k-ma*2];
      ans = max(ans, score);
    }
    cout << ans << endl;
  }
}