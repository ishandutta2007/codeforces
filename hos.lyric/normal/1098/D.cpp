#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstdint>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template <class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template <class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

int bitN;
Int bit[500010];
void bitAdd(int pos, Int val) {
  for (int x = pos; x < bitN; x |= x + 1) {
    bit[x] += val;
  }
}
Int bitSum(int pos) {
  Int ret = 0;
  for (int x = pos - 1; x >= 0; x = ((x & (x + 1)) - 1)) {
    ret += bit[x];
  }
  return ret;
}

int Q;
char T[500010];
Int X[500010];

int xsLen;
pair<Int, int> xs[500010];
Int ord[500010];

int main() {
  for (; ~scanf("%d", &Q); ) {
    for (int q = 0; q < Q; ++q) {
      scanf(" %c%lld", &T[q], &X[q]);
    }
// cout<<"T = ";pv(T,T+Q);
// cout<<"X = ";pv(X,X+Q);
    xsLen = 0;
    for (int q = 0; q < Q; ++q) {
      if (T[q] == '+') {
        xs[xsLen++] = make_pair(X[q], q);
      }
    }
    sort(xs, xs + xsLen);
    for (int i = 0; i < xsLen; ++i) {
      ord[xs[i].second] = i;
    }
    multimap<Int, int> mp;
    for (int q = 0; q < Q; ++q) {
      if (T[q] == '+') {
        mp.emplace(X[q], ord[q]);
      } else {
        auto it = mp.find(X[q]);
        assert(it != mp.end());
        ord[q] = it->second;
        mp.erase(it);
      }
    }
// cout<<"ord = ";pv(ord,ord+Q);
    int sz = 0;
    set<int> contents;
    bitN = xsLen;
    fill(bit, bit + bitN, 0);
    for (int q = 0; q < Q; ++q) {
      if (T[q] == '+') {
        ++sz;
        contents.insert(ord[q]);
        bitAdd(ord[q], +X[q]);
      } else {
        --sz;
        contents.erase(ord[q]);
        bitAdd(ord[q], -X[q]);
      }
// cout<<"  contents = ";pv(contents.begin(),contents.end());
// cout<<"    ";for(const int i:contents)cout<<xs[i].first<<" ";cout<<endl;
      int ans = sz;
      for (auto it = contents.begin(); it != contents.end(); ) {
        if (2 * bitSum(*it) < xs[*it].first) {
          --ans;
          ++it;
        } else {
          const Int need = 2 * bitSum(*it) + 1;
          const int pos = lower_bound(xs, xs + xsLen, make_pair(need, -1)) - xs;
          it = contents.lower_bound(pos);
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}