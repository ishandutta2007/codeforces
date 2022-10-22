#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d[200][30000];
vector<int> child[30000], node[30000];
int par[30000];

void fail() {
  cout << -1 << endl;
  exit(0);
}

int done[30000];
void check(int*dist, int p, int par, int d) {
  if (done[p]++ || d != dist[p]) fail();
  for (int i : node[p]) {
    if (i != par)
      check(dist, i, p, d+1);
  }
}

#define puts elrkjger
vector<tuple<int,int,int>> puts[200];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  fill_n(par, n, -1);

  vector<int> I(k);
  for (int i = 0; i < k; i++) {
    int found = -1;
    for (int j = 0; j < n; j++) {
      cin >> d[i][j];
      if (d[i][j] == 0) {
	if (found != -1) fail();
	found = j;
      }
    }
    if (found == -1) fail();
    I[i] = found;
    for (int j = 0; j < i; j++) if (I[j] == found) fail(); // Can he remember one vertex twice?
  }

  int r = I[0];
  for (int i = 1; i < k; i++) {
    vector<int> path(d[0][I[i]]+1, -1);
    for (int j = 0; j < n; j++) {
      if (d[0][j] + d[i][j] == d[0][I[i]]) {
	if (path[d[0][j]] != -1) fail();
	path[d[0][j]] = j;
      }
    }
    path[d[0][I[i]]] = I[i];
    int p = r;
    for (int j = 1; j <= d[0][I[i]]; j++) {
      if (path[j] == -1 || path[j] == r) fail();
      //cout << path[j] << ' ';
      if (par[path[j]] == -1) {
	child[p].push_back(path[j]);
	par[path[j]] = p;
	p = path[j];
      } else {
	if (par[path[j]] != p) fail();
	p = path[j];
      }
    }
    //cout << endl;
  }

  /*for (int i = 0; i < n; i++)
    for (int j : child[i]) cout << i+1 << ' ' << j+1 << endl;
    return 0;*/

  for (int j = 0; j < n; j++) {
    if (par[j] != -1 || j == r) continue;
    int best = d[0][j], besti = 0;
    for (int i = 1; i < k; i++) {
      int rem = d[i][j]-d[0][I[i]]+d[0][j];
      if (rem%2) fail();
      rem /= 2;
      if (rem < best) {
	best = rem;
	besti = i;
      }
    }
    puts[besti].push_back({d[besti][j]-best, best, j});
    //cout << j+1 << ' ' << besti+1 << ' ' << best << endl;
  }

  for (int i = 0; i < k; i++) {
    sort(puts[i].begin(), puts[i].end());
    int e = 0, ups = 0;
    for (int p = I[i]; p != -1; p = par[p], ups++) {
      vector<vector<int>> v = {{p}};
      while (e < puts[i].size() && get<0>(puts[i][e]) == ups) {
	int out = get<1>(puts[i][e]);
	int j = get<2>(puts[i][e]);
	if (out > v.size()) fail();
	else if (out == v.size()) v.push_back({j});
	else v[out].push_back(j);
	e++;
      }
      v.erase(v.begin());
      int q = p;
      for (auto&w : v) {
	for (int j : w) {
	  child[q].push_back(j);
	  par[j] = q;
	}
	q = child[q].back();
      }
    }
    if (e < puts[i].size()) fail();
  }

  /*for (int i = 0; i < n; i++)
    for (int j : child[i]) cout << i+1 << ' ' << j+1 << endl;
    return 0;*/

  int tot = 0;
  for (int i = 0; i < n; i++) {
    if (i != r && par[i] == -1) fail();
    for (int j : child[i]) {
      tot++;
      node[i].push_back(j);
      node[j].push_back(i);
    }
  }
  if (tot != n-1) fail();
  for (int i = 0; i < k; i++) {
    fill_n(done, n, 0);
    check(d[i], I[i], -1, 0);
  }

  for (int i = 0; i < n; i++) {
    for (int j : child[i]) {
      cout << i+1 << ' ' << j+1 << '\n';
    }
  }
}