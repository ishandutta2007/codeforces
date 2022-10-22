#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<ll,int>> ans;
  for (int i = 0; i < n; i++) {
    ans.emplace_back(a[i], 1);
    while (ans.size() >= 2) {
      auto [ap,aq] = ans.end()[-2];
      auto [bp,bq] = ans.end()[-1];
      if (ap*bq < bp*aq) break;
      ans.pop_back();
      ans.pop_back();
      ans.emplace_back(ap+bp, aq+bq);
    }
  }
  cout << setprecision(14);
  for (auto [p,q] : ans) {
    double avg = p*1./q;
    for (int i = 0; i < q; i++)
      cout << avg << '\n';
  }
}