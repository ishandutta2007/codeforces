// https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
#include <bits/stdc++.h>
using namespace std;
template <class C> constexpr int sz(const C &c) { return int(c.size()); }
constexpr const char nl = '\n', sp = ' '; using uint = unsigned int;
using ll = long long; using ull = unsigned long long; using ld = long double;
#if __SIZEOF_INT128__
  using i128 = __int128_t; using ui128 = __uint128_t;
#endif

template <class T, class Op> struct WeightedUnionFindUndo {
  vector<int> UF; vector<T> W; int cnt;
  vector<tuple<int, int, int, T, T>> history; Op op;
  WeightedUnionFindUndo(const vector<T> &W, Op op = Op())
      : UF(W.size(), -1), W(W), cnt(W.size()), op(op) {
    history.reserve(W.size());
  }
  int find(int v) { return UF[v] < 0 ? v : find(UF[v]); }
  bool join(int v, int w) {
    if ((v = find(v)) == (w = find(w))) {
      history.emplace_back(v, w, 0, W[v], W[w]); return false;
    }
    if (UF[v] > UF[w]) swap(v, w);
    history.emplace_back(v, w, UF[w], W[v], W[w]);
    UF[v] += UF[w]; UF[w] = v; W[v] = op(W[v], W[w]); cnt--; return true;
  }
  void undo() {
    int v, w, ufw; T wv, ww; tie(v, w, ufw, wv, ww) = history.back();
    history.pop_back(); if (ufw == 0) return;
    UF[w] = ufw; UF[v] -= UF[w]; W[v] = wv; W[w] = ww; cnt++;
  }
  bool connected(int v, int w) { return find(v) == find(w); }
  int getSize(int v) { return -UF[find(v)]; }
  T getWeight(int v) { return W[find(v)]; }
};

template <class S> struct SetDivAndConq {
  using T = typename S::T; using R = typename S::R; using Q = typename S::Q;
  vector<T> add, rem; vector<Q> queries; vector<R> ans; vector<int> type;
  void addElement(const T &v) { add.push_back(v); type.push_back(1); }
  void removeElement(const T &v) { rem.push_back(v); type.push_back(-1); }
  void addQuery(const Q &q) { queries.push_back(q); type.push_back(0); }
  template <class ...Args> void solveQueries(Args &&...args) {
    int E = type.size(); ans.clear(); ans.reserve(queries.size());
    vector<T> A = add; sort(A.begin(), A.end());
    vector<pair<int, int>> events; events.reserve(E);
    vector<int> last(A.size(), INT_MAX); S s(forward<Args>(args)...);
    for (int i = 0, addInd = 0, remInd = 0, queryInd = 0; i < E; i++) {
      if (type[i] == 1) {
        int j = lower_bound(A.begin(), A.end(), add[addInd++]) - A.begin();
        events.emplace_back(j, last[j]); last[j] = i;
      } else if (type[i] == -1) {
        int j = lower_bound(A.begin(), A.end(), rem[remInd++]) - A.begin();
        events.emplace_back(j, last[j]); int temp = events[last[j]].second;
        events[last[j]].second = i; last[j] = temp;
      } else events.emplace_back(queryInd++, i);
    }
    function<void(int, int)> dc = [&] (int l, int r) {
      if (l == r) {
        if (events[l].second == l)
          ans.push_back(s.query(queries[events[l].first]));
        return;
      }
      int m = l + (r - l) / 2; s.saveOnStack(); for (int i = m + 1; i <= r; i++)
        if (events[i].second < l) s.add(A[events[i].first]);
      dc(l, m); s.rollback(); s.saveOnStack(); for (int i = l; i <= m; i++)
        if (events[i].second > r) s.add(A[events[i].first]);
      dc(m + 1, r); s.rollback();
    };
    if (E > 0) dc(0, E - 1);
  }
};

struct S {
  using T = pair<int, int>; using R = ll;
  struct Q { int v; };
  WeightedUnionFindUndo<ll, plus<ll>> uf; vector<int> stk;
  S(const vector<ll> &W) : uf(W) {}
  void add(const T &v) { uf.join(v.first, v.second); }
  void saveOnStack() { stk.push_back(uf.history.size()); }
  void rollback() {
    while (int(uf.history.size()) > stk.back()) uf.undo();
    stk.pop_back();
  }
  R query(const Q &q) { return uf.getWeight(q.v); }
};
struct edge{
	int x,y,w;
};
bool comp(edge a, edge b){
	return a.w<b.w;
}
int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> A(n,1LL);
  SetDivAndConq<S> s;
  /*
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int v, w;
      cin >> v >> w;
      if (v > w) swap(v, w);
      s.addElement(make_pair(v, w));
    } else if (t == 1) {
      int v, w;
      cin >> v >> w;
      if (v > w) swap(v, w);
      s.removeElement(make_pair(v, w));
    } else if (t == 2) {
      int v;
      ll x;
      cin >> v >> x;
      A.push_back(x);
      s.addElement(make_pair(v, N++));
    } else {
      S::Q q;
      cin >> q.v;
      s.addQuery(q);
    }
  }
  s.solveQueries(A);
  for (ll a : s.ans) cout << a << nl;
  */
  vector<edge>edges(n-1);
  set<int>st;
  for(int i = 0; i<n-1; i++){
  	int x,y,w;
  	cin >> x >> y >> w;
  	x--; y--;
  	edges[i] = {x,y,w};
  	s.addElement(make_pair(x,y));
  	st.insert(w);
  }
  vector<vector<pair<int,int>>>vals(n+5);
  for(edge nxt: edges){
  	int x = nxt.x; int y = nxt.y; int w = nxt.w;
  	vals[w].push_back({x,y});

  }
  for(int i = 1; i<=n; i++){
  	for(pair<int,int>nxt: vals[i]){
  		s.removeElement(make_pair(nxt.first,nxt.second));
  	}
  	for(pair<int,int>nxt: vals[i]){
  		if(true){
  			S::Q q;
  			q.v = nxt.first;
  			s.addQuery(q);
  		}
  		if(true){
  			S::Q q;
  			q.v = nxt.second;
  			s.addQuery(q);
  		}
  	}
  	for(pair<int,int>nxt: vals[i]){
  		s.addElement(make_pair(nxt.first,nxt.second));
  	}
  }
  ll ans = 0;
  s.solveQueries(A);
  vector<ll>arr;
  for(ll a : s.ans){
  	arr.push_back(a);
  }
  for(int i = 1; i<arr.size(); i+=2){
  	ans+=arr[i-1]*arr[i];
  }
  cout << ans << "\n";
   return 0;
}