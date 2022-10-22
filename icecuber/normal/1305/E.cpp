#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cover[10010];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll has = 0;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    has += cover[i];
    while (has > m) {
      has -= cover[i];
      i++;
      has += cover[i];
    }
    ans.push_back(i);
    if (has == m) {
      for (int v : ans) cout << v << ' ';
      for (int j = ans.size(); j < n; j++) {
	cout << 100000ll*(j+1)+1 << ' ';
      }
      return 0;
    }
    for (int j = 1; j < i; j++)
      cover[i+j]++;
  }
  cout << -1 << endl;
}