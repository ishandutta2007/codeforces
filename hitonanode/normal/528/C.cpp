#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

struct UnionFind {
  vector< int > data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) {
    return -data[find(k)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};
// https://ei1333.github.io/library/graph/others/eulerian-trail.cpp
template< bool directed >
struct EulerianTrail {
  vector< vector< pair< int, int > > > g;
  vector< pair< int, int > > es;
  int M;
  vector< int > used_vertex, used_edge, deg;

  explicit EulerianTrail(int V) : g(V), M(0), deg(V), used_vertex(V) {}

  void add_edge(int a, int b) {
    es.emplace_back(a, b);
    g[a].emplace_back(b, M);
    if(directed) {
      deg[a]++;
      deg[b]--;
    } else {
      g[b].emplace_back(a, M);
      deg[a]++;
      deg[b]++;
    }
    M++;
  }

  pair< int, int > get_edge(int idx) const {
    return es[idx];
  }

  vector< vector< int > > enumerate_eulerian_trail() {
    if(directed) {
      for(auto &p : deg) if(p != 0) return {};
    } else {
      for(auto &p : deg) if(p & 1) return {};
    }
    used_edge.assign(M, 0);
    vector< vector< int > > ret;
    for(int i = 0; i < (int) g.size(); i++) {
      if(g[i].empty() || used_vertex[i]) continue;
      ret.emplace_back(go(i));
    }
    return ret;
  }

  vector< vector< int > > enumerate_semi_eulerian_trail() {
    UnionFind uf(g.size());
    for(auto &p : es) uf.unite(p.first, p.second);
    vector< vector< int > > group(g.size());
    for(int i = 0; i < (int) g.size(); i++) group[uf.find(i)].emplace_back(i);
    vector< vector< int > > ret;
    used_edge.assign(M, 0);
    for(auto &vs : group) {
      if(vs.empty()) continue;
      int latte = -1, malta = -1;
      if(directed) {
        for(auto &p : vs) {
          if(abs(deg[p]) > 1) {
            return {};
          } else if(deg[p] == 1) {
            if(latte >= 0) return {};
            latte = p;
          }
        }
      } else {
        for(auto &p : vs) {
          if(deg[p] & 1) {
            if(latte == -1) latte = p;
            else if(malta == -1) malta = p;
            else return {};
          }
        }
      }
      ret.emplace_back(go(latte == -1 ? vs.front() : latte));
      if(ret.back().empty()) ret.pop_back();
    }
    return ret;
  }

  vector< int > go(int s) {
    stack< pair< int, int > > st;
    vector< int > ord;
    st.emplace(s, -1);
    while(!st.empty()) {
      int idx = st.top().first;
      used_vertex[idx] = true;
      if(g[idx].empty()) {
        ord.emplace_back(st.top().second);
        st.pop();
      } else {
        auto e = g[idx].back();
        g[idx].pop_back();
        if(used_edge[e.second]) continue;
        used_edge[e.second] = true;
        st.emplace(e);
      }
    }
    ord.pop_back();
    reverse(ord.begin(), ord.end());
    return ord;
  }
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> deg(N);
    EulerianTrail<false> et(N);
    vector<pint> edges;
    REP(_, M)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        et.add_edge(a, b);
        deg[a]++, deg[b]++;
        edges.emplace_back(a, b);
    }
    vector<int> odds;
    REP(i, N) if (deg[i] % 2) odds.emplace_back(i);
    for (int i = 0; i < odds.size(); i += 2) {
        et.add_edge(odds[i], odds[i + 1]);
        edges.emplace_back(odds[i], odds[i + 1]);
    }
    if (edges.size() % 2) {
        et.add_edge(0, 0);
        edges.emplace_back(0, 0);
    }
    vector<int> v = et.enumerate_eulerian_trail()[0];
    dbg(v);
    auto build = [&](int init) -> vector<int> {
        vector<int> ret;
        int now = init;
        for (auto ie : v) {
            ret.emplace_back(now);
            if (now != edges[ie].first and now != edges[ie].second) return {};
            now = now ^ edges[ie].first ^ edges[ie].second;
        }
        return ret;
    };
    vector<int> ret1 = build(edges[v[0]].first);
    vector<int> ret2 = build(edges[v[0]].second);
    if (ret1.empty()) ret1 = ret2;
    cout << ret1.size() << '\n';
    REP(i, ret1.size()) {
        int a = ret1[i] + 1, b = ret1[(i + 1) % ret1.size()] + 1;
        if (i % 2) swap(a, b);
        cout << a << ' ' << b << '\n';
    }
}