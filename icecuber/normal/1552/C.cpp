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
    set<int> left;
    for (int i = 0; i < n*2; i++) left.insert(i);

    vector<array<int,2>> chord(k);
    for (auto&[a,b] : chord) {
      cin >> a >> b;
      a--, b--;
      if (a > b) swap(a,b);
      left.erase(a);
      left.erase(b);
    }
    vector<int> sorted;
    for (int v : left) sorted.push_back(v);

    for (int i = 0; i < n-k; i++) 
      chord.push_back({sorted[i], sorted[i+n-k]});
    int ans = 0;
    for (auto&[a,b] : chord) {
      for (auto&[c,d] : chord) {
        if (a == c) continue;
        if ((a < c && c < b) + (a < d && d < b) == 1) ans++;
      }
    }
    cout << ans/2 << endl;
  }
}