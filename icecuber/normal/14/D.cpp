#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200];
int done1[200];
int n;
int done2[200];

int best, besti;
void dfs2(int p, int par = -1, int l = 0) {
  if (done1[p]) return;
  done2[p] = 1;
  if (l > best) {
    best = l;
    besti = p;
  }
  for (int i : node[p])
    if (i != par)
      dfs2(i, p, l+1);
}

int solve() {
  fill_n(done2, n, 0);
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (done1[i] || done2[i]) continue;
    best = -1;
    dfs2(i);
    best = -1;
    dfs2(besti);
    r = max(r, best);
  }
  return r;
}

int ans = 0;
void dfs1(int p, int l = 0) {
  if (done1[p]) return;
  done1[p] = 1;
  ans = max(ans, solve()*l);
  for (int i : node[p])
    dfs1(i, l+1);
  done1[p] = 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    dfs1(i);
  }
  cout << ans << endl;
}