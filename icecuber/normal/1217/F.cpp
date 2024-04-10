#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<18;
tuple<int,int,int> query[nax];

struct Join {
  int last, x, y;
};
vector<Join> joins[nax*2];

int par[nax], sz[nax];

int find(int p) {
  if (p == par[p]) return p;
  else return find(par[p]);
}

struct Undo {
  int a, b;
};

Undo join(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return {-1,-1};
  if (sz[a] < sz[b]) swap(a,b);
  par[b] = a;
  sz[a] += sz[b];
  return {a,b};
}
void unjoin(Undo u) {
  if (u.a == -1) return;
  par[u.b] = u.b;
  sz[u.a] -= sz[u.b];
}

set<pair<int,int>> edges;

int n;
void rec(int&last, int l, int r, int i0 = 1) {
  vector<Undo> joined;
  for (auto e : joins[i0]) {
    if (edges.count({e.x,e.y})) {
      joined.push_back(join(e.x, e.y));
    }
  }

  if (r-l > 1) {
    int m = l+r>>1;
    rec(last, l, m, i0*2);
    rec(last, m, r, i0*2+1);
  } else {
    int t, x, y;
    tie(t,x,y) = query[l];
    int a = (x+n-1+last)%n, b = (y+n-1+last)%n;
    if (a > b) swap(a,b);
    if (t == 2) {
      cout << (last=(find(a)==find(b)));
    } else {
      if (edges.count({a,b})) edges.erase({a,b});
      else edges.insert({a,b});
    }
  }

  reverse(joined.begin(), joined.end());
  for (auto e : joined) {
    unjoin(e);
  }
}

void insert(int a, int b, Join&j, int l = 0, int r = nax, int i0 = 1) {
  if (a <= l && b >= r) {
    joins[i0].push_back(j);
    return;
  }
  if (a >= r || b <= l) return;
  int m = l+r>>1;
  insert(a,b,j,l,m,i0*2);
  insert(a,b,j,m,r,i0*2+1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    par[i] = i, sz[i] = 1;

  map<pair<int,int>,pair<int,int>> last;
  for (int i = 0; i < m; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    if (x > y) swap(x,y);
    x--, y--;
    query[i] = {t,x,y};
    if (t == 1) {
      for (int j : {0,1}) {
	int a = (x+n-1+j)%n, b = (y+n-1+j)%n;
	if (a > b) swap(a,b);
	if (last.count({a,b})) {
	  auto p = last[{a,b}];
	  Join J = {p.second,a,b};
	  insert(p.first, i, J);
	}
	last[{a,b}] = {i+1,j};
      }
    }
  }
  for (auto p : last) {
    Join J = {p.second.second,p.first.first,p.first.second};
    insert(p.second.first, m, J);
  }
  {
    int last = 0;
    rec(last, 0, nax);
    cout << endl;
  }
}