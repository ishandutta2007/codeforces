#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
set<int> node[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) node[i].clear();
    map<pair<int,int>, vector<int>> m;
    auto add = [&](int a, int b, int i) {
      if (node[a].count(b)) {
	node[a].erase(b);
	node[b].erase(a);
      } else {
	node[a].insert(b);
	node[b].insert(a);
      }
      if (a > b) swap(a,b);
      m[{a,b}].push_back(i);
    };
    vector<tuple<int,int,int>> v(n-2);
    {
      int i = 0;
      for (auto&[a, b, c] : v) {
	cin >> a >> b >> c;
	a--, b--, c--;
	add(a,b, i);
	add(a,c, i);
	add(b,c, i);
	i++;
      }
    }
    vector<int> perm;
    {
      int p = 0, par = -1;
      for (int i = 0; i < n; i++) {
	perm.push_back(p);
	assert(node[p].size() == 2);
	int q = (*node[p].begin() == par ? *node[p].rbegin() : *node[p].begin());
	par = p;
	p = q;
      }
      assert(p == 0);
    }
    vector<int> cuts;
    {
      vector<int> oks(n-2);
      queue<int> q;
      auto cut = [&](int a, int b) {
	if (a > b) swap(a,b);
	for (int i : m[{a,b}]) {
	  if (++oks[i] == 2) q.push(i);
	}
      };
      for (int i = 0; i < n; i++) {
	cut(perm[i], perm[(i+1)%n]);
      }
      while (q.size()) {
	int i = q.front();
	cuts.push_back(i);
	q.pop();
	auto [a, b, c] = v[i];
	cut(a,b);
	cut(a,c);
	cut(b,c);
      }
    }
    for (int i : perm) cout << i+1 << ' ';
    cout << endl;
    for (int i : cuts) cout << i+1 << ' ';
    cout << endl;
  }
}