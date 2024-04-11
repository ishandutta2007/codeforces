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
//const ll mod = 1000000007;
using UnWeigtedGraph = vector<vector<int>>;
template< typename G >
struct DoublingLowestCommonAncestor {
  const int LOG;
  vector< int > dep;
  const G &g;
  vector< vector< int > > table;

  DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
    table.assign(LOG, vector< int >(g.size(), -1));
  }

  void dfs(int idx, int par, int d) {
    table[0][idx] = par;
    dep[idx] = d;
    for(auto &to : g[idx]) {
      if(to != par) dfs(to, idx, d + 1);
    }
  }

  void build() {
    dfs(0, -1, 0);
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = LOG - 1; i >= 0; i--) {
      if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--) {
      if(table[i][u] != table[i][v]) {
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }
};

ll N;
vector<ll> a;
ll ainv[301000];
vector<vector<int>> edges;
vector<vector<int>> children;
ll mini[301000];
vector<ll> ans;
ll ansinv[301000];

void dfs1(int now, int from) {
    mini[now] = a[now];
    for(auto to : edges[now]) {
        if(to == from) continue;
        children[now].push_back(to);
        dfs1(to, now);
        chmin(mini[now], mini[to]);
    }
}

ll order = 0;
vector<int> pos;
vector<int> prepos;
ll p[301000];
void dfs2(int now) {
    prepos.push_back(now);
    ans[now] = order;
    ansinv[ans[now]] = now;
    order++;
    for(auto to : children[now]) {
        p[to] = now;
        dfs2(to);
    }
    pos.push_back(now);
}

void NO() {
    cout << "NO" << endl;
    exit(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    a.resize(N);
    edges.resize(N);
    ans.resize(N);
    children.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
        ainv[a[i]] = i;
    }
    for(int i = 0; i < N - 1; i++) {
        ll q, w;
        cin >> q >> w;
        q--;
        w--;
        edges[q].push_back(w);
        edges[w].push_back(q);
    }
    dfs1(0, -1);
    for(int i = 0; i < N; i++) {
        sort(children[i].begin(), children[i].end(), [&](int q, int w){
            return mini[q] < mini[w];
        });
    }
    p[0] = -1;
    dfs2(0);
    //for(auto tmp : pos) cout << tmp << " ";
    //cout << endl;
    DoublingLowestCommonAncestor<UnWeigtedGraph> LCA(edges);
    LCA.build();
    int err = 0;
    ll ansval = 0;
    while(err < N) {
        ansval += LCA.dep[ainv[err]];
        if(ainv[err] == pos[err]) {
            err++;
        } else break;
    }
    //cout << err << endl;
    if(err != N) {
        int ub = N - 1;
        while(ub >= 0) {
            if(a[prepos[ub]] == ub) ub--;
            else break;
        }
        //cout << err << " " << ub << endl;
        if(ub >= 0 and ub >= err) {
            vector<int> v;
            for(int val = err; val <= ub; val++) {
                v.push_back(ainv[val]);
            }
            sort(v.begin(), v.end(), [&](int q, int w){
                return LCA.dep[q] < LCA.dep[w];
            });
            for(int i = 1; i < (int)v.size(); i++) {
                //cerr << i << endl;
                if(p[v[i]] != v[i-1]) NO();
            }
            auto itr = find(v.begin(), v.end(), ainv[err]);
            v.erase(itr);
            /*
            for(auto tmp : v) cerr << tmp << " ";
            cerr << endl;
            */
            for(int i = 1; i < (int)v.size(); i++) {
                //cerr << i << endl;
                if(a[v[i-1]] >= a[v[i]]) NO();
            }
            /*
            for(auto tmp : v) {
                cerr << tmp << " ";
            }
            cerr << endl;
            */
        }
    }
    cout << "YES" << endl;
    cout << ansval << endl;
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
    return 0;
}