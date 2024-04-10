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
typedef long long int64;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

template<class T> T abs(T x) { return x >= 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

typedef pair<int64, int64> pll;

int n;
int64 c;
vector<int64> a;

struct Magic {
  int64 c;
  int64 plus, minus;
  int64 best_c;
  set<pll> pm;
  set<pll> sm;

  Magic(int64 c) : c(c) {
    plus = 0;
    minus = 0;
    best_c = c;
  }

  void add(int64 x) {
    x -= plus;
    pm.insert(pll(x, -minus));
    sm.insert(pll(x + minus, -minus));
    update();
  }

  void inc(int64 x) {
    plus += x;
    update();
  }

  void dec(int64 x) {
    minus += x;
    update();
  }

  int64 max() {
//    cerr << sz(pm) << " " << sz(sm) << "\n";
//    if (sz(pm)) cerr << "top == " << pm.rbegin()->first + plus << "\n";
    int64 best = c - best_c - minus;
    if (sz(sm)) {
      int64 sum = sm.rbegin()->first;
      sum += plus;
      sum -= minus;
      best = std::max<int64>(best, sum);
    }
    return best;
  }

  void update() {
    while (sz(pm) && pm.rbegin()->first + plus >= c) {
      pll entry = *pm.rbegin();
      pm.erase(entry);
      sm.erase(pll(entry.first - entry.second, entry.second));
      best_c = min(best_c, entry.second);
    }
  }
};

int main() {
  scanf("%d", &n);
  cin >> c;
  a.resize(2 * n - 1);
  for (int i = 0; i < sz(a); ++i) {
    int x;
    scanf("%d", &x);
    a[i] = x;
  }
  Magic magic(c);
  int64 res = 0;
  for (int i = 0; i < sz(a); ++i) {
    if (i % 2 == 1) {
      magic.inc(a[i]);
      continue;
    }
    magic.add(0);
    magic.inc(a[i]);
    int64 cur = magic.max();
//    cerr << cur << "\n";
    res += cur;
    magic.dec(cur);
  }
  cout << res << "\n";
  return 0;
}