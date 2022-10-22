#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  map<int,int> m;
  set<int> s;
  for (int i = 0; i < n; i++) {
    m[a[i]] = s.size();
    s.insert(a[i]);
  }
  ll ans = 0;
  for (auto [a,cnt] : m) ans += cnt;
  cout << ans << endl;
}