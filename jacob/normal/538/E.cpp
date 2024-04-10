#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
vector<vi> children;
int n, m;

void dfs_clear_children(int p, int parent = -1) {
  auto it = find(children[p].begin(), children[p].end(), parent);
  if (it != children[p].end()) {
    children[p].erase(it);
  }
  for (auto t : children[p]) {
    dfs_clear_children(t, p);
  }
}

int dfs2(int p);

int dfs1(int p) {
  if (children[p].empty())
    return 1;
  int result = m + 1;
  for (int ch : children[p]) {
    result = min(result, dfs2(ch));
  }
  return result;
}

int dfs2(int p) {
  if (children[p].empty())
    return 1;
  int result = 0;
  for (int ch : children[p]) {
    result += dfs1(ch);
  }
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> n;
  children.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    children[a].push_back(b);
    children[b].push_back(a);
  }
  dfs_clear_children(0);
  m = count_if(children.begin(), children.end(), [](const vi& v) { return v.empty(); });
  cout << m + 1 - dfs1(0) << " " << dfs2(0) << endl;
  return 0;
}