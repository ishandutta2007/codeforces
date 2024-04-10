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
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }


char buf[110];

int N;

bool Ask(const vector<int> &xs) {
  printf("? %d", (int)xs.size());
  for (const int x : xs) {
    printf(" %d", x);
  }
  puts("");
  fflush(stdout);
  scanf("%s", buf);
  return (buf[0] == 'Y');
}
void Answer(int x, int y) {
  printf("! %d\n", x);
  fflush(stdout);
  scanf("%s", buf);
  if (buf[1] == ')') return;
  printf("! %d\n", y);
  fflush(stdout);
  scanf("%s", buf);
  if (buf[1] == ')') return;
#ifdef LOCAL
cerr<<"WA"<<endl;
#endif
  return;
}

int main() {
  scanf("%d", &N);
  
  vector<int> xs(N);
  for (int i = 0; i < N; ++i) {
    xs[i] = i + 1;
  }
  for (; ; ) {
    const int len = xs.size();
    if (len <= 2) {
      break;
    }
    vector<int> yss[3];
    for (int i = 0; i < len; ++i) {
      yss[i % 3].push_back(xs[i]);
    }
    int bad = -1;
    if (Ask(yss[0])) {
      if (Ask(yss[1])) {
        bad = 2;
      } else {
        bad = 1;
      }
    } else {
      if (Ask(yss[0])) {
        if (Ask(yss[1])) {
          bad = 2;
        } else {
          bad = 1;
        }
      } else {
        bad = 0;
      }
    }
    xs.clear();
    for (int h = 0; h < 3; ++h) if (bad != h) {
      xs.insert(xs.end(), yss[h].begin(), yss[h].end());
    }
  }
  
  Answer(xs[0], xs[1]);
  
  return 0;
}