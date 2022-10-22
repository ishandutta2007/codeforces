#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> mi, ma;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (!mi.count(a)) mi[a] = i;
    ma[a] = i;
  }
  vector<pair<int,int>> v;
  for (auto p : mi)
    v.push_back({p.second, ma[p.first]});
  sort(v.begin(), v.end());
  int last = 0;
  ll ans = 1;
  for (auto p : v) {
    if (p.first > last) ans = ans*2%mod;
    last = max(last, p.second);
  }
  cout << ans << endl;
}