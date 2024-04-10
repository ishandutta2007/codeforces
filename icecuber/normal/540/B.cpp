#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, p, x, y;
  cin >> n >> k >> p >> x >> y;
  int s = 0;
  int under = 0, over = 0;
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    s += a;
    under += a<y;
    over += a>=y;
  }
  vector<int> ans;
  for (int i = k; k < n; k++) {
    if (over <= under) ans.push_back(y), over++, s += y;
    else ans.push_back(1), under++, s += 1;
  }
  if (s <= x && over >= under) {
    for (int i : ans) cout << i << ' ';
    cout << endl;
  } else cout << -1 << endl;
}