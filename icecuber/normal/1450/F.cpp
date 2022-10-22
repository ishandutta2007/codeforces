#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);

    map<int,int> cnt;
    for (int&v : a) {
      cin >> v;
      cnt[v]++;
    }
    int ok = 1;
    for (auto [v,c] : cnt) if (c*2 > n+1) ok = 0;
    if (!ok) {
      cout << -1 << endl;
      continue;
    }

    vector<array<int,2>> b;
    int start = a[0];
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i-1]) {
        b.push_back({start, a[i-1]});
        start = a[i];
      }
    }
    b.push_back({start, a[n-1]});

    cnt.clear();
    for (auto [x,y] : b) cnt[x]++, cnt[y]++;
    int ma = 0;
    for (auto [v,c] : cnt) ma = max(ma, c);
    int k = b.size();
    cout << k-1+max(ma-(k+1),0) << endl;
  }
}