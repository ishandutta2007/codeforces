#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];
int done[200000];
void dfs(int p, int col = 1) {
  if (done[p]) {
    if (done[p] != col) {
      cout << "NO" << endl;
      exit(0);
    }
    return;
  }
  done[p] = col;
  for (int i : node[p])
    dfs(i, 3-col);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> edge(m);
  for (auto&p : edge) {
    cin >> p.first >> p.second;
    p.first--, p.second--;
    node[p.first].push_back(p.second);
    node[p.second].push_back(p.first);
  }
  dfs(0);
  cout << "YES" << endl;
  for (auto p : edge)
    cout << (done[p.first] == 1);
  cout << endl;
}