#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int end, req, id;
};

vector<Edge> node[100000];

int done[100000];
vector<int> topo;
int itopo[100000];
int dfs(int p, int c) {
  if (done[p] == 1) return 1;
  if (done[p] == 2) return 0;
  done[p] = 1;
  //cout << "1 " << p << endl;
  for (Edge e : node[p]) if (e.req > c && dfs(e.end,c)) return 1;
  //cout << "2 " << p << endl;
  done[p] = 2;
  itopo[p] = topo.size();
  topo.push_back(p);
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--,b--;
    node[a].push_back({b,c,i+1});
  }
  int fail = -1, pass = 1e9; //TODO
  while (fail+1 < pass) {
    int mid = pass+fail>>1;
    int ok = 1;
    topo.clear();
    fill_n(done, n, 0);
    for (int i = 0; i < n; i++)
      if (dfs(i,mid)) { ok = 0; break; }
    if (ok) pass = mid;
    else fail = mid;
  }

  topo.clear();
  fill_n(done, n, 0);
  for (int i = 0; i < n; i++)
    dfs(i,pass);

  vector<int> revs;
  for (int i : topo) {
    for (Edge e : node[i]) {
      if (itopo[e.end] > itopo[i]) {
	assert(e.req <= pass);
	revs.push_back(e.id);
      }
    }
  }

  cout << pass << ' ' << revs.size() << '\n';
  for (int i : revs) cout << i << ' ';
  cout << endl;
}