#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }


// op: T * T -> T, associative
template <class T, T (*op)(const T &, const T &)> struct Queue {
  vector<T> as, aas, bs, bbs;

  void reserve(int n) {
    as.reserve(n);
    aas.reserve(n);
    bs.reserve(n);
    bbs.reserve(n);
  }
  void reduce() {
    for (; !bs.empty(); bs.pop_back(), bbs.pop_back()) {
      as.push_back(bs.back());
      aas.push_back(aas.empty() ? bs.back() : op(bs.back(), aas.back()));
    }
  }
  T get() {
    if (as.empty()) reduce();
    assert(!as.empty());
    return bbs.empty() ? aas.back() : op(aas.back(), bbs.back());
  }

  bool empty() const {
    return (as.empty() && bs.empty());
  }
  int size() const {
    return as.size() + bs.size();
  }
  T front() {
    if (as.empty()) reduce();
    assert(!as.empty());
    return as.back();
  }
  void push(const T &t) {
    bs.push_back(t);
    bbs.push_back(bbs.empty() ? t : op(bbs.back(), t));
  }
  void pop() {
    if (as.empty()) reduce();
    assert(!as.empty());
    as.pop_back();
    aas.pop_back();
  }
  void clear() {
    as.clear();
    aas.clear();
    bs.clear();
    bbs.clear();
  }
};

////////////////////////////////////////////////////////////////////////////////

int op(const int &a, const int &b) {
  return max(a, b);
}


template <class T> void bChmax(vector<T> &bit, int pos, const T &val) {
  const int bitN = bit.size();
  for (int x = pos; x < bitN; x |= x + 1) chmax(bit[x], val);
}
template <class T> T bMax(const vector<T> &bit, int pos) {
  T ret = -1;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) chmax(ret, bit[x]);
  return ret;
}


int N;
vector<int> P;

vector<int> solve() {
  vector<int> Q(N, -1);
  for (int i = 0; i < N; ++i) {
    Q[P[i]] = i;
  }
  vector<int> ls(N, -1), rs(N, N);
  {
    // left larger
    set<int> is;
    for (int j = N; --j >= 0; ) {
      const int i = Q[j];
      auto it = is.lower_bound(i);
      if (it != is.begin()) {
        --it;
        ls[i] = *it;
      }
      is.insert(i);
    }
  }
  {
    // right smaller
    set<int> is;
    for (int j = 0; j < N; ++j) {
      const int i = Q[j];
      auto it = is.lower_bound(i);
      if (it != is.end()) {
        rs[i] = *it;
      }
      is.insert(i);
    }
  }
  vector<int> bit(N, -1);
  vector<int> ret(N, -1);
  for (int j = 0; j < N; ++j) {
    const int i = Q[j];
    if (ls[i] != -1) {
      ret[i] = bMax(bit, ls[i]);
    }
    if (rs[i] != N) {
      bChmax(bit, rs[i], i);
    }
  }
// cerr<<"P = ";pv(P.begin(),P.end());
// cerr<<"ls = ";pv(ls.begin(),ls.end());
// cerr<<"rs = ";pv(rs.begin(),rs.end());
// cerr<<"ret = ";pv(ret.begin(),ret.end());
  return ret;
}

int main() {
  for (; ~scanf("%d", &N); ) {
    P.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &P[i]);
      --P[i];
    }
    
    const auto fs = solve();
    for (int i = 0; i < N; ++i) P[i] = N - 1 - P[i];
    const auto gs = solve();
    for (int i = 0; i < N; ++i) P[i] = N - 1 - P[i];
    vector<int> hs(N, -1);
    for (int i = 0; i < N; ++i) {
      hs[i] = max(fs[i], gs[i]);
    }
// cerr<<"hs = ";pv(hs.begin(),hs.end());
    
    Queue<int, op> que;
    Int ans = 0;
    for (int i = 0, j = 0; j < N; ++j) {
      que.push(hs[j]);
      for (; i <= j && i <= que.get(); ++i) {
        que.pop();
      }
// cerr<<j<<": "<<i<<endl;
      ans += (j - i + 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}