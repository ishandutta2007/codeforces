#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> p;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    p.emplace_back(v, i);
  }
  sort(p.begin(), p.end());
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[p[(i+1)%n].second] = p[i].first;
  }
  for (int i : ans) cout << i << ' ';
  cout << endl;
}