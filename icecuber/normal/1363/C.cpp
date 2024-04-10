#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    x--;
    vector<vector<int>> node(n);
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    if (node[x].size() <= 1) {
      cout << "Ayush" << endl;
    } else {
      cout << (n%2 == 0 ? "Ayush" : "Ashish") << endl;
    }
  }
}