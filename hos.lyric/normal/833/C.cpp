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


Int TEN[20];

Int L, R;

int lsLen, rsLen;
int ls[20], rs[20];

int fs[10], gs[10];
bool check(int n, Int minVal) {
  if (n > lsLen) {
    return (minVal <= R);
  } else if (lsLen + 1 < rsLen) {
    return true;
  } else {
    {
      const Int a = minVal / TEN[n - 1];
      if (minVal % TEN[n - 1] + a * TEN[lsLen] <= R) {
        return true;
      }
    }
    copy(fs, fs + 10, gs);
    gs[0] += (lsLen - n);
    Int val = 0;
    if (lsLen < rsLen) {
      for (int a = 10; a--; ) {
        for (int _ = 0; _ < gs[a]; ++_) {
          val = val * 10 + a;
        }
      }
      return (L <= val);
    }
    for (int i = lsLen; i--; ) {
      const int l = ls[i];
      for (int a = l + 1; a < 10; ++a) {
        if (gs[a] > 0) {
          --gs[a];
          Int v = val * 10 + a;
          for (int b = 0; b < 10; ++b) {
            for (int _ = 0; _ < gs[b]; ++_) {
              v = v * 10 + b;
            }
          }
          ++gs[a];
          if (v <= R) {
            return true;
          }
          break;
        }
      }
      if (gs[l] > 0) {
        --gs[l];
        val = val * 10 + l;
      } else {
        return false;
      }
    }
    return (val <= R);
  }
}

int ans;
void dfs(int n, int last, Int val) {
  if (n > 0) {
    if (check(n, val)) {
      ++ans;
    }
  }
  if (n < 18) {
    for (int a = last; a < 10; ++a) {
      ++fs[a];
      dfs(n + 1, a, val * 10 + a);
      --fs[a];
    }
  }
}

int main() {
  TEN[0] = 1;
  for (int i = 1; i <= 18; ++i) {
    TEN[i] = TEN[i - 1] * 10;
  }
  
  for (; ~scanf("%lld%lld", &L, &R); ) {
    lsLen = rsLen = 0;
    for (Int l = L; l > 0; l /= 10) ls[lsLen++] = l % 10;
    for (Int r = R; r > 0; r /= 10) rs[rsLen++] = r % 10;
    fill(fs, fs + 10, 0);
    ans = 0;
    if (L == TEN[18]) {
      ans = 1;
    } else {
      dfs(0, 1, 0);
    }
    printf("%d\n", ans);
#ifdef LOCAL
    if (R - L <= 1'000'000) {
      set<Int> brt;
      for (Int x = L; x <= R; ++x) {
        vector<Int> xs;
        for (Int xx = x; xx > 0; xx /= 10) {
          xs.push_back(xx % 10);
        }
        sort(xs.begin(), xs.end());
        Int val = 0;
        for (const Int x : xs) {
          val = val * 10 + x;
        }
        brt.insert(val);
      }
      cerr << "brt = " << brt.size() << endl;
      assert((int)brt.size() == ans);
    }
#endif
  }
}