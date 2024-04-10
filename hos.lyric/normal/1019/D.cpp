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

struct Pt {
  Int x, y;
  Pt() {}
  Pt(Int x, Int y) : x(x), y(y) {}
};
struct Entry {
  int i, j;
  Pt p;
  int s;
  Entry(int i, int j, const Pt &p) : i(i), j(j), p(p) {
    s = (p.y < 0) ? 3 : (p.y > 0) ? 1 : (p.x < 0) ? 2 : 0;
  }
  friend ostream &operator<<(ostream &os, const Entry &e) {
    return os << "(" << e.i << ", " << e.j << "; " << e.p.x << ", " << e.p.y << ")";
  }
};

int N;
Int S;
Pt P[2010];

Int tri(int i, int j, int k) {
  return (P[j].x - P[i].x) * (P[k].y - P[i].y) - (P[j].y - P[i].y) * (P[k].x - P[i].x);
}

int esLen;
Entry *es[4000010];
int seq[2010], pos[2010];

int main() {
  for (; ~scanf("%d%lld", &N, &S); ) {
    for (int i = 0; i < N; ++i) {
      scanf("%lld%lld", &P[i].x, &P[i].y);
    }
    
    esLen = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      if (i != j) {
        es[esLen++] = new Entry(i, j, Pt(P[j].x - P[i].x, P[j].y - P[i].y));
      }
    }
    sort(es, es + esLen, [&](Entry *const a, Entry *const b) {
      return ((a->s != b->s) ? (a->s < b->s) : (a->p.x * b->p.y > a->p.y * b->p.x));
    });
#ifdef LOCAL
cerr<<"es = ";for(int g=0;g<esLen;++g){cerr<<*es[g]<<" ";}cerr<<endl;
#endif
    for (int i = 0; i < N; ++i) {
      seq[i] = i;
    }
    sort(seq, seq + N, [&](const int k, const int l) {
      const Int tk = tri(es[0]->i, es[0]->j, k);
      const Int tl = tri(es[0]->i, es[0]->j, l);
      return (tk != tl) ? (tk < tl) : (es[0]->p.x * (P[l].x - P[k].x) + es[0]->p.y * (P[l].y - P[k].y) > 0);
    });
    for (int h = 0; h < N; ++h) {
      pos[seq[h]] = h;
    }
    
    for (int g = 0; g < esLen; ++g) {
      const Entry &e = *es[g];
#ifdef LOCAL
cerr<<"e = "<<e<<", seq = ";pv(seq,seq+N);
#endif
      int lo = -1, hi = N;
      for (; lo + 1 < hi; ) {
        const int mid = (lo + hi) / 2;
        ((tri(e.i, e.j, seq[mid]) <= 2 * S) ? lo : hi) = mid;
      }
      if (lo >= 0 && tri(e.i, e.j, seq[lo]) == 2 * S) {
        puts("Yes");
        for (const int k : {e.i, e.j, seq[lo]}) {
          printf("%lld %lld\n", P[k].x, P[k].y);
        }
        goto found;
      }
      // swap
      assert(abs(pos[e.i] - pos[e.j]) == 1);
      swap(seq[pos[e.i]], seq[pos[e.j]]);
      swap(pos[e.i], pos[e.j]);
    }
    puts("No");
   found:{}
  }
  return 0;
}