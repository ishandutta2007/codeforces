#include <bits/stdc++.h>
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
//const ll mod = 1000000007;
typedef vector<vector<int>> UnWeightedGraph;

template< typename G >
struct LowLink {
  const G &g;
  vector< int > used, ord, low;
  vector< int > articulation;
  vector< pair< int, int > > bridge;
 
  LowLink(const G &g) : g(g) {}
 
  int dfs(int idx, int k, int par) {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];
    bool is_articulation = false;
    int cnt = 0;
    for(auto &to : g[idx]) {
      if(!used[to]) {
        ++cnt;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        is_articulation |= ~par && low[to] >= ord[idx];
        if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));
      } else if(to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_articulation |= par == -1 && cnt > 1;
    if(is_articulation) articulation.push_back(idx);
    return k;
  }
 
  virtual void build() {
    used.assign(g.size(), 0);
    ord.assign(g.size(), 0);
    low.assign(g.size(), 0);
    int k = 0;
    for(int i = 0; i < g.size(); i++) {
      if(!used[i]) k = dfs(i, k, -1);
    }
  }
};

template< typename G >
struct TwoEdgeConnectedComponents : LowLink< G > {
  using LL = LowLink< G >;
  vector< int > comp;
 
  TwoEdgeConnectedComponents(const G &g) : LL(g) {}
 
  int operator[](const int &k) {
    return comp[k];
  }
 
  void dfs(int idx, int par, int &k) {
    if(~par && this->ord[par] >= this->low[idx]) comp[idx] = comp[par];
    else comp[idx] = k++;
    for(auto &to : this->g[idx]) {
      if(comp[to] == -1) dfs(to, idx, k);
    }
  }
 
  void build(UnWeightedGraph &t) {
    LL::build();
    comp.assign(this->g.size(), -1);
    int k = 0;
    for(int i = 0; i < comp.size(); i++) {
      if(comp[i] == -1) dfs(i, -1, k);
    }
    t.resize(k);
    for(auto &e : this->bridge) {
      int x = comp[e.first], y = comp[e.second];
      t[x].push_back(y);
      t[y].push_back(x);
    }
  }
};

vector<ll> mp[301000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    UnWeightedGraph g(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    TwoEdgeConnectedComponents<UnWeightedGraph> bcc(g);
    UnWeightedGraph t;
    bcc.build(t);
    for(ll i = 0; i < N; i++) {
        mp[bcc[i]].push_back(i);
    }
    vector<l_l> v;
    for(int i = 0; i < N; i++) {
        if(mp[i].size() <= 1) continue;
        //sort(w.begin(), w.end());
        ll maxi = -1;
        ll mini = N;
        for(auto val : mp[i]) {
            chmax(maxi, val);
            chmin(mini, val);
        }
        v.push_back({mini, maxi});
    }
    /*
    for(auto tmp : v) {
        cerr << "[" << tmp.first << ", " << tmp.second << "]" << endl;
    }
    */
    vector<ll> maxi(N + 1);
    maxi[N] = N;
    sort(v.begin(), v.end());
    for(int i = N - 1; i >= 0; i--) {
        maxi[i] = maxi[i+1];
        while(!v.empty()) {
            if(v.back().first != i) break;
            chmin(maxi[i], v.back().second - 1);
            v.pop_back();
        }
    }
    //for(int i = 0; i < N; i++) cerr << maxi[i] << " ";
    //cerr << endl;
    vector<ll> sum(N + 2);
    for(int i = 0; i <= N; i++) {
        sum[i+1] = sum[i] + maxi[i];
    }
    int Q;
    cin >> Q;
    for(int q = 0; q < Q; q++) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll ans = (r + l) * (r - l + 1) / 2;
        ans *= -1;
        ans += (r - l + 1);
        auto itr = lower_bound(maxi.begin(), maxi.end(), r);
        ll idx = distance(maxi.begin(), itr);
        chmax(idx, l);
        chmin(idx, r);
        ans += sum[idx] - sum[l];
        ans += r * (r - idx + 1);
        cout << ans << "\n";
    }
    return 0;
}