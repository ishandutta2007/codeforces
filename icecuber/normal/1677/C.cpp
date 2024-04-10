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
    vector<int> a(n), b(n);
    for (int&v : a) cin >> v, v--;
    for (int&v : b) cin >> v, v--;

    vector<vector<int>> node(n);
    for (int i = 0; i < n; i++) {
      node[a[i]].push_back(b[i]);
      node[b[i]].push_back(a[i]);
    }
    for (int i = 0; i < n; i++) assert(node[i].size() == 2);

    int skips = 0;
    vector<int> done(n);
    for (int s = 0; s < n; s++) {
      if (done[s]) continue;
      int par = -1, len = 0, p = s;
      while (!done[p]++) {
        int cp = p;
        p = (node[p][0] == par ? node[p][1] : node[p][0]);
        par = cp;
        len++;
      }
      skips += len%2;
    }
    ll ans = 0;
    for (int i = 0; i < (n-skips)/2; i++)
      ans += n-1-i - i;
    cout << ans*2 << endl;
  }
}