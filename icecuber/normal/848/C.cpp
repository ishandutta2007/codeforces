#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FenwickTree {
  static const int nax = 1<<18;
  ll data[nax];
  void add(int i, int v) {
    for (i += 5; i < nax; i += i&-i) data[i] += v;
  }
  ll sum(int i) {
    ll r = 0;
    for (i += 5; i; i -= i&-i) r += data[i];
    return r;
  }
} tree;

struct Point {
  int x, y, z, w;
};
vector<Point> point;

struct Query {
  int x, y, z, w, ansi;
};
vector<Query> query;

struct Event {
  int t, x, y, w, ansi;
};
bool operator<(Event a, Event b) {
  if (a.y == b.y) return a.t < b.t;
  return a.y < b.y;
}

vector<ll> ans;
void dq(vector<Point>&p, vector<Query>&q, int l, int r) {
  if (r-l <= 1) return;
  vector<Point> pl, pr;
  vector<Query> ql, qr;
  vector<Event> e;
  int m = l+r>>1;
  for (auto&pi : p) {
    if (pi.z < m) {
      pl.push_back(pi);
      e.push_back({1, pi.x, pi.y, pi.w, -1});
    } else
      pr.push_back(pi);
  }
  for (auto&qi : q) {
    if (qi.z < m)
      ql.push_back(qi);
    else {
      qr.push_back(qi);
      e.push_back({2, qi.x, qi.y, qi.w, qi.ansi});
    }
  }

  assert(tree.sum(tree.nax-10) == 0);

  sort(e.begin(), e.end());
  for (auto&ei : e) {
    if (ei.t == 1) {
      tree.add(ei.x, ei.w);
    } else {
      ans[ei.ansi] += (tree.sum(tree.nax-10)-tree.sum(ei.x-1))*ei.w;
    }
  }
  for (auto&ei : e)
    if (ei.t == 1)
      tree.add(ei.x, -ei.w);

  dq(pl, ql, l, m);
  dq(pr, qr, m, r);
}

void solve() {
  dq(point, query, 0, 1<<18);

  /*for (auto q : query) {
    for (auto p : point) {
      if (p.x >= q.x && p.y <= q.y && p.z < q.z) {
	ans[q.ansi] += p.w*q.w;
      }
    }
    }*/
}

void addPoint(int x, int y, int z, int w) {
  point.push_back({x,y,z,w});
}

void addQuery(int x, int y, int z, int w, int ansi) {
  query.push_back({x,y,z,w,ansi});
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  map<int,set<int>> pos;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].insert(i);
  }

  int z = 0;

  auto nbr = [&](int i) {
    auto&s = pos[a[i]];
    auto it = s.lower_bound(i);
    assert(it != s.end());
    assert(*it == i);
    int nxt = n, prv = -1;
    if (next(it) != s.end()) nxt = *next(it);
    if (it != s.begin()) prv = *prev(it);
    return make_pair(prv,nxt);
  };

  for (int i = 0; i < n; i++) {
    int nxt = nbr(i).second;
    if (nxt < n)
      addPoint(i, nxt, z, (nxt-i));
  }

  for (int qi = 0; qi < m; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, x;
      cin >> i >> x;
      i--;

      z++;
      int prv,nxt;
      tie(prv,nxt) = nbr(i);
      if (nxt < n)
	addPoint(i, nxt, z, -(nxt-i));
      if (prv > -1) {
	addPoint(prv, i, z, -(i-prv));
	if (nxt < n)
	  addPoint(prv, nxt, z, (nxt-prv));
      }
      pos[a[i]].erase(i);
      a[i] = x;
      pos[x].insert(i);
      tie(prv,nxt) = nbr(i);
      if (nxt < n)
	addPoint(i, nxt, z, (nxt-i));
      if (prv > -1) {
	addPoint(prv, i, z, (i-prv));
	if (nxt < n)
	  addPoint(prv, nxt, z, -(nxt-prv));
      }
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      addQuery(l, r, z+1, 1, ans.size());
      ans.push_back(0);
    }
  }

  solve();

  for (ll a : ans) cout << a << '\n';
}