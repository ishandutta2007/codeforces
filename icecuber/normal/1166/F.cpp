#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e6;
set<int> nbs[nax];
int par[nax];

int find(int p) {
  return par[p] = (par[p] == p ? p : find(par[p]));
}

void join(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return;
  if (nbs[b].size() > nbs[a].size()) swap(a,b);
  par[b] = a;
  for (int i : nbs[b])
    nbs[a].insert(i);
  nbs[b].clear();
}

map<pair<int,int>,int> m;
int id(int p, int col) {
  pair<int,int> pi(p,col);
  if (!m.count(pi)) {
    int i = m.size();
    m[pi] = i;
    par[i] = i;
    nbs[i].insert(p);
  }
  return m[pi];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, cols, q;
  cin >> n >> m >> cols >> q;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    join(id(a,0),id(b,c));
    join(id(a,c),id(b,0));
  }
  while (q--) {
    char cmd;
    cin >> cmd;
    if (cmd == '+') {
      int a, b, c;
      cin >> a >> b >> c;
      join(id(a,0),id(b,c));
      join(id(a,c),id(b,0));
    } else if (cmd == '?') {
      int a, b;
      cin >> a >> b;
      cout << (nbs[find(id(a,0))].count(b) ? "Yes" : "No") << '\n';
    } else assert(0);
  }
}