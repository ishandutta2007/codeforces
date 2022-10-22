#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
  vector<pair<int,int>> node[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> balance(n);
  for (int&v : balance) cin >> v;
  vector<pair<int,int>> edge;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].emplace_back(b, i);
    node[b].emplace_back(a, i);
    balance[a]--;
    balance[b]--;
    edge.emplace_back(a,b);
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (balance[i] >= 0) {
      for (auto [b,ei] : node[i])
	q.push(ei);
    }
  }
  vector<int> ans;
  vector<int> done(m);
  while (q.size()) {
    int p = q.front();
    q.pop();
    if (done[p]++) continue;
    ans.push_back(p);
    auto [a, b] = edge[p];
    for (int x : {a,b}) {
      balance[x]++;
      if (balance[x] == 0) {
	for (auto [b,ei] : node[x])
	  q.push(ei);
      }
    }
  }

  if ((int)ans.size() != m) {
    cout << "DEAD" << endl;
  } else {
    reverse(ans.begin(), ans.end());
    cout << "ALIVE" << endl;
    for (int i : ans) cout << i+1 << ' ';
    cout << endl;
  }
}