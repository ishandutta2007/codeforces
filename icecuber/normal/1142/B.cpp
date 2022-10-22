#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int done[200000];
int stack_trace[200000], stack_size = 0;
vector<int> child[200000];
int n, m, q;

struct Query {
  int s, e, i;
};
bool operator<(Query a, Query b) {
  if (a.e != b.e) return a.e < b.e;
  return a.i < b.i;
}

vector<Query> good;

void dfs(int p) {
  if (done[p]++) return;
  stack_trace[stack_size++] = p;
  if (stack_size >= n) {
    //cout << stack_trace[stack_size-n] << ' ' << p << endl;
    good.push_back({stack_trace[stack_size-n], p+1, -1});
  }
  for (int i : child[p]) {
    //cout << p << ' ' << i << endl;
    dfs(i);
  }
  stack_size--;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> q;
  vector<int> prev(n), p(n);
  for(int&i : p) cin >> i, i--;
  for (int i = 0; i < n; i++)
    prev[p[i]] = p[(i+n-1)%n];

  vector<int> a(m);
  for (int&i : a) cin >> i, i--;
  vector<int> last(n,-1), par(m);
  for (int i = 0; i < m; i++) {
    int par = last[prev[a[i]]];
    if (par > -1)
      child[par].push_back(i);
    last[a[i]] = i;
  }
  for (int i = 0; i < m; i++)
    dfs(i);

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    good.push_back({l-1, r, i});
  }

  sort(good.begin(), good.end());

  vector<int> data(m+20,0);
  auto add = [&](int i, int v) {
    for (i += 10; i; i -= i&-i) data[i] += v;
  };
  auto get = [&](int i) {
    int r = 0;
    for (i += 10; i < data.size(); i += i&-i) r += data[i];
    return r;
  };
  vector<int> ans(q,0);
  for (Query q : good) {
    if (q.i == -1) {
      add(q.s, 1);
    } else {
      ans[q.i] = !!get(q.s);
    }
  }
  for (int i : ans) cout << i;
  cout << endl;
}