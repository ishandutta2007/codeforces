#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int a, b, l, r;
};

const int nax = 1e5;
int par[nax], parc[nax], sz[nax];

pair<int,int> find(int p, int c = 0) {
  if (p == par[p]) {
    return {p,c};
  }
  return find(par[p],c^parc[p]);
}

int bads = 0;
struct Joiner {
  pair<int,int> pa, pb;
  int a, b;
  Joiner(int a0, int b0) {
    a = a0, b = b0;
    pa = find(a), pb = find(b);
    if (pa.first == pb.first) {
      //cout << pa.second << ' ' << pb.second << endl;
      bads += (pa.second == pb.second);
    } else {
      if (sz[pb.first] > sz[pa.first]) swap(pa,pb);
      par[pb.first] = pa.first;
      parc[pb.first] = pb.second^pa.second^1;
      sz[pa.first] += sz[pb.first];
    }
  }
  void undo() {
    if (pa.first == pb.first) {
      bads -= (pa.second == pb.second);
    } else {
      par[pb.first] = pb.first;
      parc[pb.first] = 0;
      sz[pa.first] -= sz[pb.first];
    }
  }
};

void dq(vector<Edge> edges, int l, int r) {
  int mid = l+r>>1;
  vector<Edge> a, b;
  vector<Joiner> joined;
  for (Edge e : edges) {
    if (e.l <= l && e.r >= r) {
      joined.push_back(Joiner(e.a,e.b));
      //cout << "join " << e.a+1 << ' ' << e.b+1 << endl;
      //cout << find(e.a).second << ' ' << find(e.b).second << endl;
    } else {
      if (e.l < mid && e.r > l) {
	a.push_back(e);
      }
      if (e.l < r && e.r > mid) {
	b.push_back(e);
      }
    }
  }

  if (r-l == 1) {
    assert(a.empty());
    assert(b.empty());
    cout << (bads ? "NO\n" : "YES\n");
  } else {
    dq(a, l, mid);
    dq(b, mid, r);
  }

  reverse(joined.begin(), joined.end());
  for (auto e : joined) {
    e.undo();
    //cout << "unjoin " << e.a+1 << ' ' << e.b+1 << endl;
  }
}

int main() {
  for (int i = 0; i < nax; i++) {
    par[i] = i, sz[i] = 1;
  }
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  map<pair<int,int>,int> active;
  vector<Edge> edges;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a > b) swap(a,b);
    if (active.count({a,b})) {
      edges.push_back({a,b,active[{a,b}],i});
      active.erase({a,b});
    } else {
      active[{a,b}] = i;
    }
  }
  for (auto pa : active) {
    edges.push_back({pa.first.first,pa.first.second,pa.second,q});
  }
  dq(edges, 0, q);
}