#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, a, b, k;
  cin >> n >> a >> b >> k;

  vector<int> need;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    h--;
    h %= a+b;
    need.push_back(h/a);
  }
  sort(need.begin(), need.end());
  int ans = 0;
  for (int v : need) {
    k -= v;
    if (k < 0) break;
    ans++;
  }
  cout << ans << endl;
}