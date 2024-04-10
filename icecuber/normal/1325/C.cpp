#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> edges;
  map<pair<int,int>, int> label;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
    edges.emplace_back(a, b);
  }
  int found = 0;
  for (int i = 0; i < n; i++) {
    if (node[i].size() >= 3) {
      for (int j = 0; j < 3; j++) {
	int k = node[i][j];
	label[{i,k}] = label[{k,i}] = j;
      }
      found = 3;
      break;
    }
  }
  for (auto [a,b] : edges) {
    if (label.count({a,b})) cout << label[{a,b}] << '\n';
    else cout << found++ << '\n';
  }
}