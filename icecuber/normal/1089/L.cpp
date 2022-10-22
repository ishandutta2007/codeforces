#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000], b[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  map<int, vector<int>> m;
  for (int i = 0; i < n; i++)
    m[a[i]].push_back(b[i]);
  vector<int> leftovers;
  for (auto&p : m) {
    sort(p.second.begin(), p.second.end());
    for (int i = 0; i+1 < p.second.size(); i++)
      leftovers.push_back(p.second[i]);
  }
  sort(leftovers.begin(), leftovers.end());
  ll ans = 0;
  int left = k+leftovers.size()-n, i = 0;
  while (left--) {
    ans += leftovers[i++];
  }
  cout << ans << endl;
}