#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  
  vector<ll> s(k);
  for(int i = 0; i < k; ++i) cin >> s[i];

  if(k == 1) { cout << "Yes\n"; return; }
  for(int i = 0; i + 2 < k; ++i) if(s[i + 2] - s[i + 1] < s[i + 1] - s[i]) { cout << "No\n"; return; }
  if(k >= 2 && s[0] <= (n - k + 1) * (s[1] - s[0])) cout << "Yes\n";
  else cout << "No\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--) { solve(); }

  return 0;
}