#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100][100];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[j][i];
  vector<int> ans;
  for (int i = 0; i < n-1; i++) {
    vector<pair<int,int>> d;
    for (int j = 0; j < m; j++)
      d.push_back({a[i][j]-a[n-1][j], j});

    sort(d.rbegin(), d.rend());
    vector<int> ok;
    int balance = 0;
    for (auto p : d) {
      balance += p.first;
      if (balance < 0) break;
      ok.push_back(p.second);
    }
    if (ok.size() > ans.size()) ans = ok;
  }
  vector<int> cancel(m,1);
  for (int i : ans) cancel[i] = 0;
  cout << m-ans.size() << endl;
  for (int i = 0; i < m; i++)
    if (cancel[i])
      cout << i+1 << ' ';
  cout << endl;
}