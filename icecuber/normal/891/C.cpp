#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int a, b, c, i;
};

const int nax = 5e5;
vector<int> node[nax];
vector<Edge> edges;
int mst[nax];
pair<int,int> pa[nax];

int par[nax];
int find(int p) {
  return p == par[p] ? p : par[p] = find(par[p]);
}

int check(vector<pair<int,int>>&e) {
  for (auto [a,b] : e) {
    par[a] = a;
    par[b] = b;
  }
  for (auto [a,b] : e) {
    a = find(a), b = find(b);
    if (a == b) return 0;
    par[a] = b;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) par[i] = i;

  map<int,vector<int>> v;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].push_back(i);
    node[b].push_back(i);
    v[c].push_back(i);
    edges.push_back({a, b, c, i});
  }
  for (auto&[c,l] : v) {
    for (int ei : l) {
      Edge&e = edges[ei];
      if (find(e.a) != find(e.b)) {
	mst[e.i] = 1;
	pa[e.i] = {find(e.a), find(e.b)};
      }
    }
    for (int ei : l) {
      Edge&e = edges[ei];
      par[find(e.a)] = find(e.b);
    }
  }

  //for (int i = 0; i < m; i++)
  //  if (mst[i]) cout << edges[i].i+1 << ' ' << edges[i].a+1 << ' ' << edges[i].b+1 << endl;

  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    vector<pair<int,int>> out;
    map<int,vector<pair<int,int>>> in;

    int ok = 1;
    for (int i = 0; i < k; i++) {
      int j;
      cin >> j;
      Edge&e = edges[j-1];
      if (!mst[e.i]) {
	ok = 0;
      } else {
	out.emplace_back(e.a, e.b);
	in[e.c].push_back(pa[e.i]);
      }
    }
    if (ok) {
      if (!check(out)) ok = 0;
      for (auto&[c,v] : in)
	if (!check(v)) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}