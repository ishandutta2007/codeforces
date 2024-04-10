#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, a0;
  cin >> n >> a0;
  int sum = a0, coal = a0;
  vector<int> ans = {1};
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
    if (a0 >= a*2) {
      coal += a;
      ans.push_back(i+1);
    }
  }
  if (coal*2 > sum) {
    cout << ans.size() << endl;
    for (int v : ans) cout << v << ' ';
    cout << endl;
  } else cout << 0 << endl;
}