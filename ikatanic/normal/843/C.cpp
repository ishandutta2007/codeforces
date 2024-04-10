#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;

vector<int> E[MAX];

int sz[MAX];
int bal[MAX];

void dfs(int x, int dad) {
  sz[x] = 1;
  bal[x] = 0;
  for (int y: E[x]) {
    if (y != dad) {
      dfs(y, x);
      sz[x] += sz[y];
      bal[x] = max(bal[x], sz[y]);
    }
  }
}

vector<pair<pair<int, int>, int>> ret;

vector<int> v;
int parent[MAX];

void explore(int x, int dad) {
  v.push_back(x);
  for (int y: E[x])
    if (y != dad) {
      parent[y] = x;
      explore(y, x);
    }
}

void solve(int x, int dad) {
  for (int y: E[x]) {
    if (y != dad) {
      v.clear();
      explore(y, x);
      
      int center = v[0];
      int cur_center = center;
      for (int i = (int)v.size()-1; i > 0; --i) {
        if (parent[v[i]] != center) {
          ret.push_back({{x, cur_center}, v[i]});
          ret.push_back({{v[i], parent[v[i]]}, center});
          cur_center = v[i];
        }
      }
      
      if (cur_center != center) {
        ret.push_back({{x, cur_center}, center});
      }
    }
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1);
  vector<int> centroids;
  REP(x, n) {
    bal[x] = max(bal[x], n - sz[x]);
    if (bal[x] <= n/2) centroids.push_back(x);
  }

  if (centroids.size() == 1) {
    solve(centroids[0], -1);
  } else if (centroids.size() == 2) {
    solve(centroids[0], centroids[1]);
    solve(centroids[1], centroids[0]);
  } else assert(false);


  printf("%d\n", (int)ret.size());
  for (auto p: ret) printf("%d %d %d\n", p.first.first+1, p.first.second+1, p.second+1);
  return 0;
}