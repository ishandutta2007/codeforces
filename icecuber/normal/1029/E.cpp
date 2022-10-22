#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];

int marked[200000], good[200000], marks = 0;
void dfs(int p, int par) {
  int bad_child = 0;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i,p);
    if (!good[i]) bad_child = 1;
    if (marked[i]) good[p] = 1;
  }
  if (bad_child && par) marked[p] = 1, good[p] = 1, marks++;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  for (int i : node[0]) {
    dfs(i,0);
  }
  cout << marks << endl;
}