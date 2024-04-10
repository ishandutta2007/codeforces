#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000];

void fail() {
  cout << -1 << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<pair<int,int>> edge;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
    edge.insert({a,b});
  }
  set<int> one, two, three;
  for (int i = 0; i < n; i++) one.insert(i);
  for (int i : node[0]) one.erase(i);
  for (int j = 0; j < n; j++) {
    if (!one.count(j)) {
      for (int i = 0; i < n; i++) two.insert(i);
      for (int i : node[j]) two.erase(i);

      for (int i = 0; i < n; i++) three.insert(i);
      for (int i : one) three.erase(i);
      for (int i : two) {
	if (!three.count(i)) fail();
	three.erase(i);
      }
      break;
    }
  }
  //cout << one.size() << ' ' << two.size() << ' '<< three.size() << endl;
  if (one.size() && two.size() && three.size()) {
    for (int i : one) for (int j : two) if (!edge.count({min(i,j),max(i,j)})) fail();
    for (int i : two) for (int j : three) if (!edge.count({min(i,j),max(i,j)})) fail();
    for (int i : three) for (int j : one) if (!edge.count({min(i,j),max(i,j)})) fail();
    for (int i : one) for (int j : node[i]) if (one.count(j)) fail();
    for (int i : two) for (int j : node[i]) if (two.count(j)) fail();
    for (int i : three) for (int j : node[i]) if (three.count(j)) fail();

    vector<int> ans(n);
    for (int i : one) ans[i] = 1;
    for (int i : two) ans[i] = 2;
    for (int i : three) ans[i] = 3;
    for (int i : ans) cout << i << ' ';
    cout << endl;
  } else fail();
}