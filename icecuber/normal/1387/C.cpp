#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

vector<array<int,2>> tree(1);
int terminal[110];


ull inf = (1ull<<63)-1;

int s;
struct Mat {
  vector<ull> data;
  Mat() {
    data.assign(s*s, inf);
  }
};

Mat operator*(const Mat&a, const Mat&b) {
  Mat r;
  for (int i = 0; i < s; i++) {
    for (int k = 0; k < s; k++) {
      for (int j = 0; j < s; j++) {
	//if (a.data[i*s+k] != inf && b.data[k*s+j] != inf)
	r.data[i*s+j] = min(r.data[i*s+j], a.data[i*s+k]+b.data[k*s+j]);
      }
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int g, n, m;
  cin >> g >> n >> m;

  vector<pair<int,vector<int>>> mut;
  vector<vector<vector<int>>> node(g);
  for (int i = 0; i < n; i++) {
    int a, k;
    cin >> a >> k;
    node[a].push_back(vector<int>(k));
    mut.emplace_back(a, vector<int>());
    for (int&v : node[a].back()) {
      cin >> v;
      mut.back().second.push_back(v);
    }
  }

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    int p = 0;
    while (k--) {
      int c;
      cin >> c;
      if (!tree[p][c]) {
	tree[p][c] = tree.size();
	tree.push_back({0,0});
      }
      p = tree[p][c];
    }
    terminal[p] = 1;
  }

  {
    vector<int> link(tree.size());
    queue<int> q;
    q.push(0);
    while (q.size()) {
      int p = q.front();
      q.pop();
      int par = link[p];
      terminal[p] |= terminal[par];
      for (int c : {0,1}) {
	if (!tree[p][c]) {
	  tree[p][c] = tree[par][c];
	} else {
	  link[tree[p][c]] = p ? tree[par][c] : 0;
	  q.push(tree[p][c]);
	}
      }
    }
  }
  s = tree.size();
  for (int p = 0; p < s; p++)
    if (terminal[p]) tree[p][0] = tree[p][1] = p;

  vector<Mat> mat(g);
  for (int c : {0,1}) {
    for (int i = 0; i < s; i++) {
      mat[c].data[i*s+tree[i][c]] = 1;
    }
  }


  vector<int> changed(g,1);
  while (1) {
    int found = 0;
    //random_shuffle(mut.begin(), mut.end());
    vector<int> nchanged(g);
    for (auto&[a,v] : mut) {
      //for (int a = 2; a < g; a++) {
      //for (auto&v : node[a]) {
      int need = 0;
      for (int b : v) if (changed[b]) need = 1;
      if (!need) continue;
      Mat prod = mat[v[0]];
      for (int i = 1; i < (int)v.size(); i++) {
	prod = prod*mat[v[i]];
      }
      for (int i = 0; i < s*s; i++) {
	if (prod.data[i] < mat[a].data[i]) {
	  mat[a].data[i] = prod.data[i];
	  nchanged[a] = 1;
	  found = 1;
	}
      }
      //}
    }
    changed = nchanged;
    if (!found) break;
  }

  for (int a = 2; a < g; a++) {
    ull mi = inf;
    for (int i = 0; i < s; i++) {
      if (!terminal[i])
	mi = min(mi, mat[a].data[i]);
    }
    if (mi < inf) cout << "NO " << mi << endl;
    else cout << "YES" << endl;
  }
}