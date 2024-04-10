#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;
const int nax = 1e5+10;
vector<int> node[nax];

ll bin_pow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

ll w[nax];
vector<pair<int,int>> event[nax];

int par[nax], depth[nax], maxdepth[nax];

void dfs(int p, int parent = -1, int d = 0) {
  depth[p] = d;
  par[p] = parent;
  maxdepth[p] = d;
  for (int i : node[p]) {
    if (i == parent) continue;
    dfs(i, p, d+1);
    maxdepth[p] = max(maxdepth[p], maxdepth[i]);
  }
}

struct SlowTree {
  ll data[nax];
  void init() {}
  void add(int i, int v) {
    for (int p = i; p != -1; p = par[p])
      (data[p] += v) %= mod;
  }
  ll sum(int i) {
    ll r = 0;
    for (int p = i; p != -1; p = par[p])
      (r += data[p]) %= mod;
    return r;
  }
};

struct FenTree {
  vector<int> a, b;
  int n;
  FenTree(int n_) {
    n = n_+5;
    a.resize(n);
    b.resize(n);
  }
  void add(int r, ll v) {
    r++;
    for (int i = 1; i < n; i += i&-i) {
      (a[i] += v) %= mod;
    }
    for (int i = r; i < n; i += i&-i) {
      (a[i] -= v) %= mod;
      (b[i] += r*v%mod) %= mod;
    }
  }
  ll sum(int r) {
    r++;
    ll ra = 0, rb = 0;
    for (int i = r; i; i -= i&-i) {
      (ra += a[i]) %= mod;
      (rb += b[i]) %= mod;
    }
    return (ra*r+rb)%mod;
  }
};

struct SlowFenTree {
  vector<int> data;
  int n;
  SlowFenTree(int n_) {
    n = n_;
    data.resize(n);
  }
  void add(int r, ll v) {
    for (int i = 0; i <= r; i++)
      (data[i] += v) %= mod;
  }
  ll sum(int r) {
    ll ans = 0;
    for (int i = 0; i <= r; i++)
      (ans += data[i]) %= mod;
    return ans;
  }
};


struct FastTree {
  int treei[nax], treep[nax];
  vector<FenTree> tree;
  vector<int> hpar;
  void hld(int p, int par, int treei_, int treep_) {
    if (treei_ == -1) {
      treei_ = tree.size();
      treep_ = 0;
      tree.push_back(FenTree(maxdepth[p]-depth[p]+1));
      hpar.push_back(par);
    }
    treei[p] = treei_;
    treep[p] = treep_;

    int heavy = -1, d = -1;
    for (int i : node[p]) {
      if (i == par) continue;
      if (maxdepth[i] > d) {
	heavy = i;
	d = maxdepth[i];
      }
    }
    if (heavy != -1)
      hld(heavy, p, treei_, treep_+1);

    for (int i : node[p]) {
      if (i == par || i == heavy) continue;
      hld(i, p, -1, -1);
    }
  }
  void init() {
    hld(0, -1, -1, -1);
  }
  void add(int i, ll v) {
    for (; i != -1; i = hpar[treei[i]]) {
      tree[treei[i]].add(treep[i], v);
    }
  }
  ll sum(int i) {
    ll r = 0;
    for (; i != -1; i = hpar[treei[i]]) {
      (r += tree[treei[i]].sum(treep[i])) %= mod;
    }
    return r;
  }
};

FastTree tree1;
//SlowTree tree1;

ll total = 0;
ll current = 0;
ll sumw1 = 0;
ll sumw2 = 0;

void add(int i, ll v) {
  (total += v) %= mod;

  (sumw2 += v*v%mod * (depth[i]+1)) %= mod;
  (sumw2 += 2*v%mod * tree1.sum(i)) %= mod;

  (sumw1 -= tree1.sum(i)) %= mod;
  tree1.add(i, v);
  (sumw1 += tree1.sum(i)) %= mod;

  current = (total*sumw1-sumw2)%mod;
}

int main() {
  if (0) {
    int n = 100;
    FenTree fast(n);
    SlowFenTree slow(n);
    srand(3);
    for (int i = 0; i < 1000; i++) {
      int r = rand()%n;
      int v = rand()%mod;
      fast.add(r, v);
      slow.add(r, v);
    }
    for (int i = 0; i < 1000; i++) {
      int r = rand()%n;
      //cout << fast.sum(r) << endl;
      //cout << slow.sum(r) << endl;
      assert((fast.sum(r)+mod)%mod == (slow.sum(r)+mod)%mod);
    }
    return 0;
  }


  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> l(nax), r(nax);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    event[l[i]].emplace_back(i, 1);
    event[r[i]].emplace_back(i,-1);
  }

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }

  dfs(0);
  tree1.init();

  for (int i = 0; i < n; i++) {
    w[i] = bin_pow(r[i]-l[i], mod-2);
  }

  ll ans = 0;
  for (int c = 0; c < nax; c++) {
    for (auto p : event[c]) {
      add(p.first, w[p.first]*p.second);
    }
    //if (c < 10)
    //  cout << total << ' ' << sumw1 << ' ' << sumw2 << endl;
    (ans += current) %= mod;
  }

  ll base = 1;
  for (int i = 0; i < n; i++)
    (base *= r[i]-l[i]) %= mod;
  ans = ans*base%mod;
  cout << (ans%mod+mod)%mod << endl;
}