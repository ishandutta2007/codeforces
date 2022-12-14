#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;

using r32 = double;
using r64 = long double;

template <class T>
inline bool relax(T &a, const T &b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool tense(T &a, const T &b) {
  return b < a ? a = b, true : false;
}

const int MaxN = 1500000;

int n;
int a[MaxN + 1], b[MaxN + 1];

vector<int> pa, pb;

inline void shit(int a, vector<int> &p) {
  for (int i = 2; i * i <= a; ++i) {
    if (a % i == 0) {
      p.push_back(i);
      while (a % i == 0) {
        a /= i;
      }
    }
  }
  if (a > 1) {
    p.push_back(a);
  }
}

inline bool solve(vector<int> &p) {
  for (int i : p) {
    bool flag = true;
    for (int j = 2; j <= n; ++j) {
      if (a[j] % i && b[j] % i) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << i << endl;
      return true;
    }
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }

  shit(a[1], pa);
  shit(b[1], pb);

  if (!solve(pa) && !solve(pb)) {
    cout << -1 << endl;
  }

  return 0;
}