#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> home, away;
  for (int i = 0; i < n; i++) {
    int h, a;
    cin >> h >> a;
    home[h]++;
    away[a]++;
  }
  ll ans = 0;
  for (auto p : home) ans += p.second*away[p.first];
  cout << ans << endl;
}