#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> child[100000];
vector<int> ans;

int p[100000], c[100000];
void dfs(int p) {
  int ok = c[p];
  for (int i : child[p]) {
    ok &= c[i];
    dfs(i);
  }
  if (ok) ans.push_back(p);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int root;
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> c[i];
    p[i]--;
    if (p[i] == -2) root = i;
    else
      child[p[i]].push_back(i);
  }
  dfs(root);
  sort(ans.begin(), ans.end());
  if (ans.empty())
    cout << -1 << endl;
  else {
    for (int i : ans) cout << i+1 << ' ';
    cout << endl;
  }
}