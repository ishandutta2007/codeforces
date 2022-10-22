#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ll;

ll inf = 2e9;

const int n = 1<<18;
struct Tree {
  pair<ll,ll> data[n*2];
  Tree() {
    fill_n(data, n*2, make_pair(inf,inf));
  }
  pair<ll,ll> merge(pair<ll,ll> a, pair<ll,ll> b) {
    for (ll v : {b.first,b.second}) {
      if (v < a.first) {
	a.second = a.first;
	a.first = v;
      } else if (v < a.second)
	a.second = v;
    }
    return a;
  }
  void set(int i, ll v) {
    i += n;
    data[i] = {v,inf};
    for (i >>= 1; i; i >>= 1) {
      data[i] = merge(data[i*2], data[i*2+1]);
    }
  }
  pair<ll,ll> rec_query(int a, int b, int l = 0, int r = n, int i = 1) {
    if (a <= l && b >= r) {
      return data[i];
    }
    if (a >= r || b <= l) return {inf,inf};
    int m = l+r>>1;
    pair<ll,ll> x = rec_query(a, b, l, m, i*2);
    pair<ll,ll> y = rec_query(a, b, m, r, i*2+1);
    return merge(x,y);
  }
  ll query(int l, int r) {
    pair<ll,ll> ans = rec_query(l, r);
    return ans.first+ans.second;
  }
};

Tree tree[10];

int a[200000];
void add(int i) {
  int v = a[i];
  for (int j = 0; j < 10; j++) {
    if (v%10) {
      tree[j].set(i, a[i]);
    }
    v /= 10;
  }
}

void rem(int i) {
  int v = a[i];
  for (int j = 0; j < 10; j++) {
    if (v%10) {
      tree[j].set(i, inf);
    }
    v /= 10;
  }
}

ll query(int l, int r) {
  ll ans = inf;
  for (int j = 0; j < 10; j++) {
    ans = min(ans, tree[j].query(l, r));
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    add(i);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, x;
      cin >> i >> x;
      i--;
      rem(i);
      a[i] = x;
      add(i);
    } else {
      int l, r;
      cin >> l >> r;
      long long ans = query(l-1, r);
      cout << (ans == inf ? -1 : ans) << '\n';
    }
  }
}