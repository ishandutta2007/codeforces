#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<19;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<array<int,2>>> node(n);
  for (int i = 0; i < n-1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].push_back({b,c});
    node[b].push_back({a,c});
  }
  const int lods = 20;
  vector<vector<array<int,2>>> par(lods, vector<array<int,2>>(n));
  vector<int> depth(n);
  function<void(int,int,int)> dfs = [&](int p, int pa, int d) {
    depth[p] = d;
    for (auto [i,w] : node[p]) {
      if (i == pa) continue;
      par[0][i] = {p,w};
      dfs(i,p,d+1);
    }
  };
  dfs(0,-1,0);
  par[0][0] = {0,-1};
  for (int l = 0; l+1 < lods; l++) {
    for (int i = 0; i < n; i++) {
      int pa = par[l][i][0];
      par[l+1][i] = {par[l][pa][0], max(par[l][pa][1], par[l][i][1])};
    }
  }
  auto lca = [&](int a, int b) {
    if (depth[a] < depth[b]) swap(a,b);
    int ma = -1;
    for (int l = lods-1; l >= 0; l--) {
      if (depth[a]-depth[b] >= 1<<l) {
        ma = max(ma, par[l][a][1]);
        a = par[l][a][0];
      }
    }
    assert(depth[a] == depth[b]);

    for (int l = lods-1; a != b; l -= !!l) {
      if (par[l][a][0] != par[l][b][0] || l == 0) {
        ma = max(ma, par[l][a][1]);
        ma = max(ma, par[l][b][1]);
        a = par[l][a][0];
        b = par[l][b][0];
      }
    }
    return array<int,2>{a,ma};
  };


  vector<array<int,2>> data(nax*2, array<int,2>{-1,-1});
  vector<array<int,2>> ON(nax*2, array<int,2>{-1,-1});
  vector<int> lazy(nax*2);

  auto join = [&](array<int,2> a, array<int,2> b) {
    if (a[0] == -1) return b;
    if (b[0] == -1) return a;
    array<int,2> l = lca(a[0],b[0]);
    return array<int,2>{l[0],max({l[1],a[1],b[1]})};
  };
  for (int i = 0; i < n; i++) {
    ON[nax+i] = {i,-1};
  }
  for (int i = nax-1; i; i--) {
    ON[i] = join(ON[i*2], ON[i*2+1]);
  }

  auto push = [&](int i) {
    assert(i < nax*2);
    if (lazy[i]) {
      if (lazy[i] == 1) {
        data[i] = ON[i];
      } else {
        assert(lazy[i] == 2);
        data[i] = {-1,-1};
      }
      if (i < nax) {
        lazy[i*2] = lazy[i];
        lazy[i*2+1] = lazy[i];
      }
      lazy[i] = 0;
    }
  };

  function<void(int,int,int,int,int,int)> update = [&](int a, int b, int v, int l, int r, int i) {
    push(i);
    if (a <= l && b >= r) {
      lazy[i] = v;
      push(i);
      return;
    } else if (a >= r || b <= l) return;
    int m = (l+r)/2;
    update(a,b,v,l,m,i*2);
    update(a,b,v,m,r,i*2+1);
    data[i] = join(data[i*2], data[i*2+1]);
  };
  function<bool(int,int,int,int)> isOpen = [&](int p, int l, int r, int i) {
    push(i);
    if (l == p && r == p+1) {
      return (data[i][0] != -1);
    } else if (p >= r || p < l) return false;
    int m = (l+r)/2;
    return isOpen(p,l,m,i*2) || isOpen(p,m,r,i*2+1);
  };

  while (q--) {
    //for (int i = 0; i < n; i++) cout << int(isOpen(i, 0,nax,1));
    //cout << ": " << data[1][1] << endl;
    int t;
    cin >> t;
    if (t == 1 || t == 2) {
      int l, r;
      cin >> l >> r;
      l--;
      update(l,r,t, 0,nax,1);
    } else {
      assert(t == 3);
      int x;
      cin >> x;
      x--;
      bool wasOpen = isOpen(x, 0,nax,1);
      update(x,x+1,1, 0,nax,1);
      cout << data[1][1] << '\n';
      if (!wasOpen) update(x,x+1,2, 0,nax,1);
    }
  }
}