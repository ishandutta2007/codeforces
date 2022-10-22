#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 5e5;
int depth[nax];
int para[nax], parb[nax];
vector<int> node[nax];

void dfs(int p, int par, int d = 0) {
  depth[p] = d;
  for (int j = 0; j < node[p].size(); j++) {
    int i = node[p][j];
    if (i != par) {
      para[i] = j;
      dfs(i,p,d+1);
    } else parb[p] = j;
  }
}

void fail() {
  cout << 0 << endl;
  exit(0);
}

struct Union {
  vector<int> par;
  Union(int n) {
    par.resize(n);
    for (int i = 0; i < n; i++)
      par[i] = i;
  }
  int join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return 1;
    par[a] = b;
    return 0;
  }
  int find(int p) {
    return p == par[p] ? p : p = find(par[p]);
  }
};

vector<pair<int,int>> constr[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a) {
      a--;
      int x = i, y = a;
      if (x == y) fail();

      int parx = -1, pary = node[y].size();
      while (x != y) {
	if (depth[x] >= depth[y]) {
	  constr[x].emplace_back(parx, parb[x]);
	  if (constr[x].size() > node[x].size()+1) fail();
	  parx = para[x];
	  x = node[x][parb[x]];
	} else {
	  constr[y].emplace_back(parb[y], pary);
	  if (constr[y].size() > node[y].size()+1) fail();
	  pary = para[y];
	  y = node[y][parb[y]];
	}
      }
      constr[x].emplace_back(parx, pary);
    }
  }

  const ll mod = 1e9+7;
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    int deg = node[i].size();
    vector<int> indeg(deg+2), outdeg(deg+2);
    Union uf(deg+2);
    for (auto p : constr[i]) {
      int a, b;
      tie(a,b) = p;
      a++, b++;
      if (outdeg[a]++ || indeg[b]++) fail();
      if (uf.join(a,b)) fail();
    }
    int rem = deg-(int)constr[i].size();
    if (rem > -1 && uf.find(0) == uf.find(deg+1)) fail();
    for (int i = 2; i <= rem; i++)
      ans = ans*i%mod;
  }
  cout << ans << endl;
}