#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 5e5;
vector<int> node[nax];
int l[nax], r[nax];

int m = 2;
void dfs(int p, int par) {
  int children = (int)node[p].size()-(par != -1);
  int x = m+children;
  r[p] = x;
  m = x+1;
  for (int i : node[p]) {
    if (i == par) continue;
    l[i] = --x;
    dfs(i, p);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  l[0] = 1;
  dfs(0, -1);
  //cout << m << ' ' << n*2 << endl;
  for (int i = 0; i < n; i++)
    cout << l[i] << ' ' << r[i] << '\n';
}