#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> child[300000];
int type[300000];
int sz[300000];

int dfs(int p) {
  int ans = 0;
  sz[p] = child[p].empty();
  if (type[p] == 0) {
    for (int i : child[p]) {
      ans += dfs(i);
      sz[p] += sz[i];
    }
  } else {
    map<int,int> v;
    for (int i : child[p]) {
      v[i] = dfs(i);
      sz[p] += sz[i];
    }
    for (int i : child[p])
      ans = max(ans, sz[p]-sz[i]+v[i]);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> type[i];
  for (int i = 1; i < n; i++) {
    int par;
    cin >> par;
    par--;
    child[par].push_back(i);
  }
  cout << dfs(0)+1 << endl;
}