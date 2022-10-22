#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sz[5000];
vector<int> child[5000];
int par[5000];

void dfs(int p) {
  sz[p] = child[p].empty();
  for (int i : child[p]) {
    dfs(i);
    sz[p] += sz[i];
  }
}

vector<int> operator+(vector<int> a, vector<int> b) {
  for (int i : b)
    a.push_back(i);
  return a;
}

int knapsack(vector<int> v, int target) {
  if (target < 0) return 0;
  vector<int> dp(target+1,0);
  dp[0] = 1;
  for (int i : v) {
    for (int j = target; j >= i; j--)
      dp[j] |= dp[j-i];
  }
  return dp[target];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int a[4];
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    child[p].push_back(i);
    par[i] = p;
  }
  vector<int> s[5];
  dfs(0);
  int branchi[4];
  for (int i = 0; i < 4; i++) {
    int p = a[i];
    int last = p;
    while (p) {
      for (int j : child[p]) {
	if (j == last) continue;
	s[i].push_back(sz[j]);
      }
      if (par[p] == 0)
	branchi[i] = p;
      p = par[p];
    }
  }
  for (int i : child[0]) {
    int done = 0;
    for (int k : {0,1,2,3})
      if (branchi[k] == i) done = 1;
    if (!done)
      s[4].push_back(sz[i]);
  }

  if (sz[0]%2 == 0 && knapsack(s[0]+s[2]+s[4], sz[0]/2-1-sz[branchi[1]]) && knapsack(s[1]+s[3]+s[4], sz[0]/2-1-sz[branchi[0]]))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}