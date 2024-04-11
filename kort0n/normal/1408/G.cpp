#include <bits/stdc++.h>
//#include <atcoder/all>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
const ll mod = 998244353;
template< int mod >
struct NumberTheoreticTransform {

  vector< int > rev, rts;
  int base, max_base, root;

  NumberTheoreticTransform() : base(1), rev{0, 1}, rts{0, 1} {
    assert(mod >= 3 && mod % 2 == 1);
    auto tmp = mod - 1;
    max_base = 0;
    while(tmp % 2 == 0) tmp >>= 1, max_base++;
    root = 2;
    while(mod_pow(root, (mod - 1) >> 1) == 1) ++root;
    assert(mod_pow(root, mod - 1) == 1);
    root = mod_pow(root, (mod - 1) >> max_base);
  }

  inline int mod_pow(int x, int n) {
    int ret = 1;
    while(n > 0) {
      if(n & 1) ret = mul(ret, x);
      x = mul(x, x);
      n >>= 1;
    }
    return ret;
  }

  inline int inverse(int x) {
    return mod_pow(x, mod - 2);
  }

  inline unsigned add(unsigned x, unsigned y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
  }

  inline unsigned mul(unsigned a, unsigned b) {
    return 1ull * a * b % (unsigned long long) mod;
  }

  void ensure_base(int nbase) {
    if(nbase <= base) return;
    rev.resize(1 << nbase);
    rts.resize(1 << nbase);
    for(int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    assert(nbase <= max_base);
    while(base < nbase) {
      int z = mod_pow(root, 1 << (max_base - 1 - base));
      for(int i = 1 << (base - 1); i < (1 << base); i++) {
        rts[i << 1] = rts[i];
        rts[(i << 1) + 1] = mul(rts[i], z);
      }
      ++base;
    }
  }

  void ntt(vector< int > &a) {
    const int n = (int) a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for(int i = 0; i < n; i++) {
      if(i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for(int k = 1; k < n; k <<= 1) {
      for(int i = 0; i < n; i += 2 * k) {
        for(int j = 0; j < k; j++) {
          int z = mul(a[i + j + k], rts[j + k]);
          a[i + j + k] = add(a[i + j], mod - z);
          a[i + j] = add(a[i + j], z);
        }
      }
    }
  }

  vector< int > multiply(vector< int > a, vector< int > b) {
    int need = a.size() + b.size() - 1;
    int nbase = 1;
    while((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz, 0);
    b.resize(sz, 0);
    ntt(a);
    ntt(b);
    int inv_sz = inverse(sz);
    for(int i = 0; i < sz; i++) {
      a[i] = mul(a[i], mul(b[i], inv_sz));
    }
    reverse(a.begin() + 1, a.end());
    ntt(a);
    a.resize(need);
    return a;
  }
};
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    vector<ll> Edge;
    vector<vector<ll>> vertexes;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        Edge.resize(n + 1);
        vertexes.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            par[i] = i, rank[i] = 0, Size[i] = 1;
            vertexes[i].push_back(i);
        }
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        Edge[x]++;
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        Edge[x] += Edge[y];
        for(auto v : vertexes[y]) {
            vertexes[x].push_back(v);
        }
        return true;
    }

    ll size(int x){
        return Size[root(x)];
    }

    vector<ll> Vertexes(ll x) {
        x = root(x);
        return vertexes[x];
    }

    bool IsComplete(ll x) {
        x = root(x);
        ll num = size(x);
        return num * (num - 1) / 2 == Edge[x];
    }
};

ll N;
ll a[2000][2000];
ll Last[2000];
vector<ll> p;
vector<vector<ll>> children;
vector<vector<int>> dp;
NumberTheoreticTransform<mod> NTT;
void dfs(int now) {
    dp[now].push_back(0);
    dp[now].push_back(1);
    if(children[now].empty()) return;
    vector<int> tmp;
    tmp.push_back(1);
    for(auto to : children[now]) {
        dfs(to);
        tmp = NTT.multiply(tmp, dp[to]);
    }
    dp[now].resize(tmp.size());
    for(int i = 0; i < tmp.size(); i++) {
        dp[now][i] = (dp[now][i] + tmp[i]) % mod;
    }
    /*
    cerr << "-------" << now << "--------" << endl;
    cerr << "{";
    for(int i = 0; i < dp[now].size(); i++) {
        if(i != 0) cerr << ", ";
        cerr << dp[now][i];
    }
    cerr << "}" << endl;
    */
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    NumberTheoreticTransform<mod> NTT;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    vector<l_l> E;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) E.push_back({i, j});
    }
    sort(E.begin(), E.end(), [&](l_l b, l_l c){
        return a[b.first][b.second] < a[c.first][c.second];
    });
    UnionFind uni(N);
    vector<vector<ll>> cliques;
    for(int i = 0; i < N; i++) {
        cliques.push_back({i});
    }
    for(auto e : E) {
        uni.merge(e.first, e.second);
        if(uni.IsComplete(e.first)) {
            cliques.push_back(uni.Vertexes(e.first));
        }
    }
    for(auto &v : cliques) {
        sort(v.begin(), v.end());
        //for(auto tmp : v) cerr << tmp << ", ";
        //cerr << endl;
    }
    int ROOT = cliques.size() - 1;
    p.resize(ROOT + 1);
    children.resize(ROOT + 1);
    dp.resize(ROOT + 1);
    for(int i = 0; i < N; i++) {
        Last[i] = ROOT;
    }
    for(int i = ROOT - 1; i >= 0; i--) {
        p[i] = Last[cliques[i][0]];
        children[p[i]].push_back(i);
        for(auto tmp : cliques[i]) {
            Last[tmp] = i;
        }
    }
    p[ROOT] = -1;
    /*
    for(int i = 0; i < cliques.size(); i++) {
        auto v = cliques[i];
        cerr << p[i] << " ";
        cerr << "{";
        for(auto tmp : v) cerr << tmp << ", ";
        cerr << "}" << endl;
    }
    */
    dfs(ROOT);
    for(int i = 1; i <= N; i++) {
        if(i != 1) cout << " ";
        cout << dp[ROOT][i];
    }
    cout << endl;
    return 0;
}