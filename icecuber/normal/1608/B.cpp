#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a-b) > 1 || a+b > n-2) {
      cout << -1 << endl;
    } else {
      int flip = 0;
      if (a < b) swap(a,b), flip = 1;
      vector<int> ans(n);

      int l = 0, r = 1;
      for (int i = 0; i < n-a-b; i++) 
        ans[i] = r++;
      for (int i = 0; i < a+b; i++) {
        if (i%2 == 0) {
          ans[n-a-b+i] = l--;
        } else {
          ans[n-a-b+i] = r++;
        }
      }

      for (int i = 0; i < n; i++)
        ans[i] -= l;

      if (flip) {
        for (int&v : ans) v = n+1-v;
        swap(a,b);
      }
      for (int v : ans) cout << v << ' ';
      cout << endl;

      set<int> seen;
      int mi = 0, ma = 0;
      for (int i = 0; i < n; i++) {
        if (ans[i] < 1 || ans[i] > n || seen.count(ans[i])) assert(0);
        if (i > 0 && i+1 < n) {
          ma += ans[i] > ans[i-1] && ans[i] > ans[i+1];
          mi += ans[i] < ans[i-1] && ans[i] < ans[i+1];
        }
      }
      assert(ma == a);
      assert(mi == b);
    }
  }
}