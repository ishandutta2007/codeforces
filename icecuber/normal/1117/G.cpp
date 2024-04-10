#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int n = 1<<20;
ll sum[n*2], lazy[n*2];
//ll mydata[n];

void reset() {
  fill_n(sum, n*2, 0);
  fill_n(lazy, n*2, 0);
}
inline void prop(int i, int w) {
  if (lazy[i]) {
    sum[i] += lazy[i]*w;
    if (i < n) {
      lazy[i*2] += lazy[i];
      lazy[i*2+1] += lazy[i];
    }
    lazy[i] = 0;
  }
}

ll querySum(int a, int b, int l = 0, int r = n, int i = 1) {
  // ll ans = 0;
  // for (int i = a; i < b; i++) ans += mydata[i];
  // return ans;
  if (a >= r || b <= l) return 0;
  prop(i, r-l);
  if (a <= l && b >= r) return sum[i];
  int m = l+r>>1;
  return querySum(a, b, l, m, i*2)+querySum(a, b, m, r, i*2+1);
}

void add(int a, int b, int v, int l = 0, int r = n, int i = 1) {
  // for (int i = a; i < b; i++)
  //   mydata[i] += v;
  // return;
  prop(i, r-l);
  if (a >= r || b <= l) return;
  if (a <= l && b >= r) {
    lazy[i] += v;
    prop(i, r-l);
    return;
  }
  int m = l+r>>1;
  add(a, b, v, l, m, i*2);
  add(a, b, v, m, r, i*2+1);
  sum[i] = sum[i*2]+sum[i*2+1];
}

struct Query {
  int l, i;
};
vector<Query> query[1000001];
int p[1000000];
ll ans[1000000];
int tleft[1000000], tright[1000000];

void solve(vector<pair<int,int>> query0, int n, int q) {
  reset();
  for (int i = 0; i <= n; i++)
    query[i].clear();
  for (int i = 0; i < q; i++)
    query[query0[i].second].push_back({query0[i].first-1, i});

  for (int i = n-1; i >= 0; i--) {
    tright[i] = i+1;
    while (tright[i] < n && p[tright[i]] < p[i])
      tright[i] = tright[tright[i]];
  }
  for (int i = 0; i < n; i++) {
    tleft[i] = i-1;
    while (tleft[i] > -1 && p[tleft[i]] < p[i])
      tleft[i] = tleft[tleft[i]];
  }

  for (int i = 0; i <= n; i++) {
    for (Query q : query[i])
      ans[q.i] += querySum(q.l, i);
    if (i < n) {
      add(tleft[i]+1, i, 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> p[i];
  vector<pair<int,int>> query0(q);
  for (auto&p : query0) cin >> p.first;
  for (auto&p : query0) cin >> p.second;
  for (int i = 0; i < q; i++)
    ans[i] = query0[i].second+1-query0[i].first;
  solve(query0, n, q);
  reverse(p, p+n);
  for (int i = 0; i < q; i++) {
    query0[i].first = n+1-query0[i].first;
    query0[i].second = n+1-query0[i].second;
    swap(query0[i].first, query0[i].second);
  }
  solve(query0, n, q);

  for (int i = 0; i < q; i++)
    cout << ans[i] << ' ';
  cout << endl;
}