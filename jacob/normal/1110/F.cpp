#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <tuple>
using namespace std;

using ll = long long;
constexpr ll INF = numeric_limits<ll>::max() / 2;

constexpr int TREE_SIZE = 1<<19;

ll tr[TREE_SIZE * 2] = {};
ll prop[TREE_SIZE * 2] = {};

void unroll(int p) {
  if (p >= TREE_SIZE) {
    prop[p] = 0;
    return;
  }
  tr[p * 2] += prop[p];
  tr[p * 2 + 1] += prop[p];
  prop[p * 2] += prop[p];
  prop[p * 2 + 1] += prop[p];
  prop[p] = 0;
 // unroll(2 * p);
 // unroll(2 * p + 1);
}

void inc(int l, int r, ll val, int p = 1, int ll = 0, int rr = TREE_SIZE) {
  l = max(ll, l);
  r = min(rr, r);
  if (r <= l) {
    return;
  }
  if (l == ll && r == rr) {
    tr[p] += val;
    prop[p] += val;
    return;
  }
  unroll(p);
  int mm = (ll + rr) / 2;
  inc(l, r, val, p * 2, ll, mm);
  inc(l, r, val, p * 2 + 1, mm, rr);
  tr[p] = min(tr[p * 2], tr[p * 2 + 1]);
}

ll get(int l, int r, int p = 1, int ll = 0, int rr = TREE_SIZE) {
  l = max(ll, l);
  r = min(rr, r);
  if (r <= l) {
    return INF;
  }
  if (l == ll && r == rr) {
    return tr[p];
  }
  unroll(p);
  int mm = (ll + rr) / 2;
  return min(
      get(l, r, p * 2, ll, mm),
      get(l, r, p * 2 + 1, mm, rr));
}

bool is_inner[TREE_SIZE] = {};
ll depth[TREE_SIZE] = {};
int parent[TREE_SIZE] = {};
int rightmost[TREE_SIZE] = {};
vector<vector<pair<int, ll>>> edges;

vector<vector<tuple<int, int, int>>> queries;
vector<ll> result;

void dfs(int p) {
  for (const auto& q: queries[p]) {
    int l, r, ind;
    tie(ind, l, r) = q;
    result[ind] = get(l, r) + depth[p];
  }
  for (const auto& e: edges[p]) {
    inc(e.first, rightmost[e.first] + 1, -2 * e.second);
    //inc(rightmost[e.first] + 1, TREE_SIZE, e.second);
    //inc(0, e.first, e.second);
    dfs(e.first);
    inc(e.first, rightmost[e.first] + 1, 2 * e.second);
    //inc(rightmost[e.first] + 1, TREE_SIZE, -e.second);
    //inc(0, e.first, -e.second);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  edges.resize(n);
  queries.resize(n);
  for (int i = 1; i < n; ++i) {
    int p;
    ll w;
    cin >> p >> w;
    --p;
    is_inner[p] = true;
    depth[i] = depth[p] + w;
    edges[p].push_back(make_pair(i, w));
    parent[i] = p;
  }
  for (int i = n - 1; i >= 0; --i) {
    rightmost[i] = max(i, rightmost[i]);
    rightmost[parent[i]] = max(rightmost[parent[i]], rightmost[i]);
  }
  for (int i = 0; i < q; ++i) {
    int v, l, r;
    cin >> v >> l >> r;
    --v; --l; --r;
    queries[v].push_back(make_tuple(i, l, r + 1));
  }
  result.assign(q, -1);
  inc(0, TREE_SIZE, INF);
  for (int i = 0; i < n; i++) {
    if (!is_inner[i]) {
      inc(i, i+1, depth[i] - INF);
    }
  }
  dfs(0);
  for (int i = 0; i < q; ++i) {
    cout << result[i] << endl;
  }
  return 0;
}