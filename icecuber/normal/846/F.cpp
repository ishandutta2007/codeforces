#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,vector<int>> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    m[a].push_back(i);
  }
  double ans = 0;
  for (auto&p : m) {
    auto&v = p.second;
    v.push_back(n);
    int last = -1;
    ans += 1;
    for (int i : v) {
      int w = i-last-1;
      ans -= 1.*w*w / (1.*n*n);
      last = i;
    }
  }
  cout << setprecision(20) << ans << endl;
}