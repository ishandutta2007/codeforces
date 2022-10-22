#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> child[500001];
int perm[500001], topos;

void dfs(int p) {
  for (int i : child[p])
    dfs(i);
  perm[p] = topos++;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> next(n);
    for (int i = 0; i < n; i++) {
      cin >> next[i];
      next[i]--;
      if (next[i] == -2)
	next[i] = i+1;
    }

    stack<int> reach;
    reach.push(n);
    int ok = 1;
    for (int i = 0; i < n; i++) {
      while (i >= reach.top()) reach.pop();
      if (next[i] > reach.top()) {
	ok = 0;
	break;
      } else if (next[i] < reach.top())
	reach.push(next[i]);
    }
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    for (int i = 0; i <= n; i++)
      child[i].clear();
    for (int i = 0; i < n; i++)
      child[next[i]].push_back(i);
    for (int i = 0; i <= n; i++)
      reverse(child[i].begin(), child[i].end());
    topos = 1;
    dfs(n);

    /*cout << endl;
    for (int i = 0; i < n; i++)
      cout << next[i] << ' ';
      cout << endl;*/
    for (int i = 0; i < n; i++)
      cout << perm[i] << ' ';
    cout << endl;
  }
}