#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll p, q;
  cin >> p >> q;
  if (__gcd(p,q) > 1) {
    cout << "Impossible" << endl;
    return 0;
  }
  vector<pair<char,ll>> ans;
  while (p != 1 || q != 1) {
    if (p >= q) {
      ll k = (p-1)/q;
      ans.push_back({'A',k});
      p -= q*k;
    } else {
      ll k = (q-1)/p;
      ans.push_back({'B',k});
      q -= p*k;
    }
  }
  for (auto p : ans) {
    cout << p.second << p.first;
  }
  cout << endl;
}