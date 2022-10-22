#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[2000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  set<int> s, all;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    all.insert(a[i]);
  }
  if (all.size() == n) {
    cout << 0 << endl;
    return 0;
  }
  int j = n, ans = n;
  while (j && !s.count(a[j-1])) s.insert(a[--j]);
  for (int i = 0; i < n; i++) {
    ans = min(ans, j-i);
    while (j < n && s.count(a[i])) s.erase(a[j++]);
    if (j == n && s.count(a[i])) break;
    s.insert(a[i]);
  }
  cout << ans << endl;
}