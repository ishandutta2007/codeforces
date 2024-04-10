#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> p(n), cnt(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
      cnt[(i-p[i]+n)%n]++;
    }
    vector<int> ans;
    for (int s = 0; s < n; s++) {
      if (cnt[s] < n/3) continue;
      int syks = 0;
      vector<int> done(n);
      for (int i = 0; i < n; i++) {
        if (done[i]) continue;
        int x = i;
        syks++;
        while (!done[x]) {
          done[x] = 1; 
          x = p[(x+s)%n];
        }
      }
      if (n-syks <= m) {
        ans.push_back(s);
      }
    }
    cout << ans.size();
    for (int v : ans) cout << ' ' << v;
    cout << endl;
  }
}