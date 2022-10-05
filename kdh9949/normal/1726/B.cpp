#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  if(m < n) { cout << "No\n"; return; }
  if(n % 2 == 1) {
    cout << "Yes\n";
    for(int i = 0; i < n - 1; ++i) cout << "1 ";
    cout << (m - n + 1) << '\n';
    return;
  }
  if(m % 2 == 1) { cout << "No\n"; return; }
  cout << "Yes\n";
  for(int i = 0; i < n - 2; ++i) cout << "1 ";
  cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}