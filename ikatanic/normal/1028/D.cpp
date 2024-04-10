#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int inf = 1e9;

const int mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }

inline int sub(int a, int b) { return a >= b ? a - b : a - b + mod; }

inline int mul(int a, int b) { return llint(a) * b % mod; }

struct Order {
  bool is_add;
  int p;
  int dir;
};

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<Order> a(N);
  REP(i, N) {
    string s;
    int p;
    cin >> s >> p;

    if (s[1] == 'D') {
      a[i] = {true, p, 0};
    } else {
      a[i] = {false, p, 0};
    }
  }

  int prev_acc = -1;
  REP(i, N) {
    if (!a[i].is_add) {
      FOR(j, prev_acc + 1, i) {
        assert(a[j].is_add);
        if (a[j].p < a[i].p) {
          a[j].dir = 1;
        } else if (a[j].p > a[i].p) {
          a[j].dir = -1;
        }
      }
      prev_acc = i;
    }
  }

  set<int, greater<int>> buy = {-inf};
  set<int> sell = {inf};

  int ret = 1;
  REP(i, prev_acc + 1) {
    if (a[i].is_add) {
      if (a[i].dir > 0) {
        if (a[i].p >= *sell.begin()) {
          ret = 0;
          break;
        }
        buy.insert(a[i].p);
      } else if (a[i].dir < 0) {
        if (a[i].p <= *buy.begin()) {
          ret = 0;
          break;
        }
        sell.insert(a[i].p);
      } else {
        if (a[i].p >= *sell.begin() || a[i].p <= *buy.begin()) {
          ret = 0;
          break;
        }
        ret = mul(ret, 2);
        buy.insert(a[i].p);
      }
    } else {
      if (*buy.begin() == a[i].p)
        buy.erase(buy.begin());
      else if (*sell.begin() == a[i].p)
        sell.erase(sell.begin());
      else {
        ret = 0;
        break;
      }
    }
  }

  int cnt = 0;
  FOR(i, prev_acc + 1, N) {
    assert(a[i].is_add);
    if (a[i].p > *buy.begin() && a[i].p < *sell.begin()) {
      cnt++;
    }
  }

  ret = mul(ret, cnt + 1);

  cout << ret << "\n";
  return 0;
}