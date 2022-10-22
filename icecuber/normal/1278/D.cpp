#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define s first
#define e second

vector<int> node[500000];
int done[500000];

void dfs(int p, int par = -1) {
  if (done[p]++) {
    cout << "NO" << endl;
    exit(0);
  }
  for (int i : node[p]) {
    if (i != par) dfs(i, p);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> inv(n);
  for (int i = 0; i < n; i++) {
    cin >> inv[i].s >> inv[i].e;
  }
  sort(inv.begin(), inv.end());
  {
    set<pair<int,int>> st;
    int i = 0, edges = 0;
    for (auto [s,e] : inv) {
      for (auto it = st.lower_bound({s,0}); it != st.end() && it->first < e; ++it) {
	node[i].push_back(it->second);
	node[it->second].push_back(i);
	edges++;
	if (edges > n-1) {
	  cout << "NO" << endl;
	  return 0;
	}
      }
      st.insert({e, i++});
    }
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    if (!done[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}