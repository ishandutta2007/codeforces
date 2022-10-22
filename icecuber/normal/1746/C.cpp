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
    vector<int> p(n);
    for (int&v : p) cin >> v, v--;
    vector<array<int,2>> order = {{-1<<30,n}};
    for (int i = 1; i < n; i++) {
      order.push_back({p[i-1]-p[i], i+1});
    }
    sort(order.begin(), order.end());
    for (auto [_,i] : order) cout << i << ' ';
    cout << endl;
  }
}