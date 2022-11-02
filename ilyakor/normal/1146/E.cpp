#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <functional>
#include <sstream>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef long long intbuben;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

template<class T> T abs(T x) { return x >= 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

typedef unsigned long long uint64;

constexpr int maxn = 101000;
constexpr int buben = 64;
constexpr int maxm = maxn / buben;

struct Vals {
  uint64 a[maxm];

  void set(int from, int what) {
    //cerr << "set " << from << " " << what << "\n";
    uint64 val = 0;
    if (what == 1) val = (uint64)-1;
    int s = (from / buben + 1) * buben;
    for (int i = from; i < s; ++i) {
      if (what == 1)
        a[i / buben] |= (((uint64)1) << (uint64) (i % buben));
      else
        a[i / buben] &= ~(((uint64)1) << (uint64) (i % buben));
    }
    for (int i = s / buben; i < maxm; ++i)
      a[i] = val;
  }

  void flip(int to) {
    int s = to - to % buben;
    for (int i = s; i <= to; ++i) {
      a[i / buben] ^= (((uint64)1) << (uint64) (i % buben));
    }
    for (int i = 0; i < s / buben; ++i)
      a[i] = ~a[i];
  }

  bool get(int pos) {
    return (a[pos / buben] >> ((uint64) (pos % buben))) & ((uint64) 1);
  }
};

void dump(Vals& pos, Vals& neg) {
  for (int i = -10; i <= 10; ++i) {
    int x = 0;
    if (i < 0) x = neg.get(-i) ? -1 : 1;
    if (i > 0) x = pos.get(i) ? -1 : 1;
    cerr << x << " ";
  }
  cerr << "\n";
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vi a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  Vals pos, neg;
  char buf[10];
  for (int i = 0; i < q; ++i) {
    int x;
    scanf("%s%d", buf, &x);
    if (buf[0] == '<') {
      if (x <= 0) {
        neg.set(-x + 1, 1);
        pos.set(-x + 1, 0);
      } else {
        neg.set(x, 1);
        pos.set(x, 0);
        neg.flip(x - 1);
        pos.flip(x - 1);
      }
    } else {
      if (x >= 0) {
        pos.set(x + 1, 1);
        neg.set(x + 1, 0);
      } else {
        pos.set(-x, 1);
        neg.set(-x, 0);
        pos.flip(-x - 1);
        neg.flip(-x - 1);
      }
    }
    //dump(pos, neg);
  }
  for (int i = 0; i < n; ++i) {
    int x = 0;
    if (a[i] > 0)
      x = a[i] * (pos.get(a[i]) ? -1 : 1);
    else if (a[i] < 0)
      x = a[i] * (neg.get(-a[i]) ? -1 : 1);
    printf("%d ", x);
  }
  printf("\n");
  return 0;
}