#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e6+10;
int tree[nax][26];
int par[nax];
int ins[nax];
int subs[nax];

void dfs1(int p) {
  subs[p] = ins[p];
  for (int c = 0; c < 26; c++) {
    int i = tree[p][c];
    if (i) {
      dfs1(i);
      subs[p] += subs[i];
    }
  }
}

int cost[nax], tabcost[nax];
void dfs2(int p) {
  if (p) {
    cost[p] = cost[par[p]]+1;
    if (ins[p]) {
      cost[p] = min(cost[p], tabcost[p]);
    }
  } else tabcost[p] = 1;
  tabcost[p] = min(tabcost[p], cost[p]+1);

  int acc = ins[p];
  for (int c = 0; c < 26; c++) {
    int i = tree[p][c];
    if (i) {
      tabcost[i] = tabcost[p]+acc;
      dfs2(i);
      acc += subs[i];
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int sz = 1;
  for (int i = 0; i < n; i++) {
    int p;
    char c;
    cin >> p >> c;
    par[sz] = p;
    tree[p][c-'a'] = sz++;
  }
  int k;
  cin >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
   ins[a[i]] = 1;
  }
  dfs1(0);
  dfs2(0);
  for (int i = 0; i < k; i++)
    cout << cost[a[i]] << ' ';
  cout << endl;
}