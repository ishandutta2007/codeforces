#include <bits/stdc++.h>
using namespace std;

void fail() {
  puts("-1");
  exit(0);
}

struct cmp {
  unordered_set<int> ok, bad;
};

struct cmp_set {
  list<cmp> all;
  set<int> ready;
  unordered_map<int, int> bad;

  cmp_set(int m) {
    for (int i = 0; i < m; i++)
      ready.insert(i);
  }

  void add_cmp(const cmp& c) {
    all.push_back(c);
    for (int u: c.bad) {
      ready.erase(u);
      bad[u]++;
    }
  }

  bool done() const {
    return all.size() == 0;
  }

  int get_next() {
    if (ready.size() == 0)
      return -1;
    int x = *ready.begin();
    ready.erase(ready.begin());
    return x;
  }

  void filter(int x) {
    for (auto it = all.begin(); it != all.end();)
      if (it->ok.find(x) != it->ok.end()) {
        for (int u: it->bad)
          if (--bad[u] == 0)
            ready.insert(u);
        it = all.erase(it);
      } else
        it++;
  }
};

map<vector<int>, queue<int> > idx;
vector<int> a[1505], b[1505];
int n, m;

void read(vector<int>* x) {
  for (int i = 0; i < n; i++) {
    x[i].resize(m);
    for (int j = 0; j < m; j++)
      scanf("%d", &x[i][j]);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  read(a); read(b);
  // reindex
  for (int i = 0; i < n; i++)
    idx[a[i]].push(i);
  for (int i = 0; i < n; i++) {
    queue<int>& u = idx[b[i]];
    if (u.size() == 0)
      fail();
    b[i].push_back(u.front());
    u.pop();
  }
  // initialize
  cmp_set all(m);
  for (int i = 1; i < n; i++) {
    cmp me;
    for (int j = 0; j <= m; j++) {
      if (b[i-1][j] < b[i][j])
        me.ok.insert(j);
      else if (b[i-1][j] > b[i][j])
        me.bad.insert(j);
    }
    all.add_cmp(me);
  }
  // solve
  stack<int> ans;
  while (!all.done()) {
    int u = all.get_next();
    if (u == -1)
      fail();
    ans.push(u);
    all.filter(u);
    if (u == m && !all.done())
      fail();
  }
  // output
  if (ans.top() == m)
    ans.pop();
  for (printf("%d\n", ans.size()); !ans.empty(); ans.pop()) {
    printf("%d\n", ans.top()+1);
  }
  return 0;
}