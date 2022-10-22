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
    vector<int> w(n);
    int sum = 0;
    for (int&v : w) cin >> v, sum += v;
    if (sum == x) {
      cout << "NO" << endl;
      continue;
    }
    sort(w.begin(), w.end());
    int acc = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (acc+w[i] == x) {
        ans.push_back(w[i+1]);
        ans.push_back(w[i]);
        acc += w[i] + w[i+1];
        i++;
      } else {
        ans.push_back(w[i]);
        acc += w[i];
      }
    }
    cout << "YES" << endl;
    for (int v : ans) cout << v << ' ';
    cout << endl;
  }
}