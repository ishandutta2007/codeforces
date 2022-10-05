#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;
  
  vector<int> t(n), a, b;
  for(int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  ll sum = 0;
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if(t[i]) a.push_back(x);
    else b.push_back(x);
    sum += x;
  }
  if(a.size() < b.size()) swap(a, b);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if(a.empty() || b.empty()) cout << sum << '\n';
  else {
    sum *= 2;
    for(int i = 0; i + b.size() < a.size(); ++i) sum -= a[i];
    if(a.size() == b.size()) sum -= min(a[0], b[0]);
    cout << sum << '\n'; 
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--) { solve(); }

  return 0;
}