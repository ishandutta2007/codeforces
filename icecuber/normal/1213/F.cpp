#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
vector<int> node[nax], rnode[nax];

vector<int> topo;
int done1[nax];
void dfs1(int p) {
  if (done1[p]++) return;
  for (int i : node[p])
    dfs1(i);
  topo.push_back(p);
}

int done2[nax];
int components = 0;
char component[nax];

void dfs2(int p) {
  if (done2[p]++) return;
  for (int i : rnode[p])
    dfs2(i);
  component[p] = min(components,25)+'a';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int k : {0,1}) {
    int last;
    cin >> last;
    for (int i = 1; i < n; i++) {
      int cur;
      cin >> cur;
      node[last-1].push_back(cur-1);
      rnode[cur-1].push_back(last-1);
      last = cur;
    }
  }
  for (int i = 0; i < n; i++)
    dfs1(i);
  reverse(topo.begin(), topo.end());
  for (int i : topo) {
    if (done2[i]) continue;
    dfs2(i);
    components++;
  }
  if (components >= k) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
      cout << component[i];
    cout << endl;
  } else cout << "NO" << endl;
}