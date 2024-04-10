#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using os_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

os_set<int> ost;
int cnt[2000];
vector<int> child[2000];
int ans[2000];
int sz[2000];

void fail() {
  cout << "NO" << endl;
  exit(0);
}

void dfs(int p) {
  sz[p] = 1;
  auto it = ost.find_by_order(cnt[p]);
  if (it == ost.end()) fail();
  ans[p] = *it;
  ost.erase(ans[p]);
  for (int i : child[p]) {
    dfs(i);
    sz[p] += sz[i];
  }
  if (cnt[p] >= sz[p]) {
    fail();
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int root;
  for (int i = 0; i < n; i++) {
    int par;
    cin >> par >> cnt[i];
    if (par) {
      child[par-1].push_back(i);
    } else root = i;
    ost.insert(i+1);
  }
  dfs(root);
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << endl;
}