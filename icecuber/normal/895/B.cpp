#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x, k;
  cin >> n >> x >> k;
  map<int,int> c;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    c[a]++;
  }
  ll ans = 0;
  map<int,int> count;
  for (auto p : c) {
    count[(p.first-1)/x] += p.second;
    ans += (ll)count[p.first/x-k]*p.second;
  }
  cout << ans << endl;
}