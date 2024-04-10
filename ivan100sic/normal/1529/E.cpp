// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[300005], f[300005];

int dl[300005], dr[300005], dt;

void dfs_f(int x) {
  dl[x] = ++dt;
  for (int y : f[x]) {
    dfs_f(y);
  }
  dr[x] = ++dt;
}

int sol;
set<pair<int, int>> q;

void dfs_e(int x) {
  int el = -1, er = -1;
  bool inserted;

  auto it = q.lower_bound({dl[x], dr[x]});
  if (it != q.end() && it->first < dr[x]) {
    // do not insert
    inserted = false;
  } else {
    if (it != q.begin() && prev(it)->second > dr[x]) {
      // erase prev
      tie(el, er) = *prev(it);
      q.erase(prev(it));
    }
    q.insert({dl[x], dr[x]});
    inserted = true;
  }

  sol = max(sol, (int)q.size());

  for (int y : e[x]) {
    dfs_e(y);
  }

  if (inserted) {
    q.erase({dl[x], dr[x]});
  }

  if (el != -1) {
    q.insert({el, er});
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    dt = 0;
    sol = 0;
    for (int i=1; i<=n; i++) {
      e[i] = {};
      f[i] = {};
    }

    for (int i=2; i<=n; i++) {
      int x;
      cin >> x;
      e[x] += i;
    }

    for (int i=2; i<=n; i++) {
      int x;
      cin >> x;
      f[x] += i;
    }

    dfs_f(1);
    dfs_e(1);
    cout << sol << '\n';
  }
}