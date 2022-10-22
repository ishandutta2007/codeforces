#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> node[300000];

int done[300000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 3*n; i++) {
      done[i] = 0;
      node[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back({b,i+1});
      node[b].push_back({a,i+1});
    }
    vector<int> matching, indep;
    for (int i = 0; i < 3*n; i++) {
      if (done[i]) continue;
      int found = 0;
      for (auto p : node[i]) {
	if (done[p.first]) continue;
	done[p.first] = 1;
	found = p.second;
	break;
      }
      done[i] = 1;
      if (!found) indep.push_back(i);
      else matching.push_back(found);
    }
    if (matching.size() >= n) {
      cout << "Matching" << '\n';
      matching.resize(n);
      for (int i : matching)
	cout << i << ' ';
      cout << '\n';
    } else {
      assert(indep.size() >= n);
      cout << "IndSet" << '\n';
      indep.resize(n);
      for (int i : indep)
	cout << i+1 << ' ';
      cout << '\n';
    }
  }
}