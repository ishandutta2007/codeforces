#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n%2) {
    cout << "Second" << endl;
    vector<vector<int>> edge(n);
    for (int i = 1; i <= n*2; i++) {
      int v;
      cin >> v, v--;
      edge[v].push_back(i%(n*2));
    }
    for (int i = 0; i < n; i++) {
      edge.push_back({i,i+n});
    }
    vector<vector<int>> node(n*2);
    for (auto v : edge) {
      node[v[0]].push_back(v[1]);
      node[v[1]].push_back(v[0]);
    }
    vector<int> col(n*2);
    function<void(int,int)> dfs = [&](int p, int c) {
      if (col[p]) return;
      col[p] = c;
      for (int i : node[p]) dfs(i,3-c);
    };
    for (int i = 0; i < n*2; i++) dfs(i,1);
    int sum = 0;
    for (int i = 0; i < n*2; i++) {
      if (col[i] == 1) (sum += i) %= n*2;
    }
    int acol = 1;
    if (sum) acol = 2;
    int sum2 = 0;
    for (int i = 0; i < n*2; i++) {
      if (col[i] == acol) {
	cout << (i ? i : n*2) << ' ';
	(sum2 += i) %= n*2;
      }
    }
    cout << endl;
    assert(sum2 == 0);
  } else {
    cout << "First" << endl;
    vector<pair<int,int>> p;
    for (int i = 1; i <= n*2; i++) {
      cout << i%n+1 << ' ';
    }
    cout << endl;
  }
  int verdict;
  cin >> verdict;
}