#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

template <class T>
bool relax(T &a, T b) {
  return b > a ? a = b, true : false;
}
template <class T>
bool tense(T &a, T b) {
  return b < a ? a = b, true : false;
}

const int N = 1111;

int n;
int vx[N], vy[N], da[N], db[N];

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> vx[i] >> vy[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> da[i] >> db[i];
  }
  for (int i = 0; i < n; ++i) {
    int tx = da[0] + vx[i], ty = db[0] + vy[i];
    set<pair<int, int>> all;
    for (int j = 0; j < n; ++j) {
      int nx = tx - da[j], ny = ty - db[j];
      all.emplace(nx, ny);
    }
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (!all.count(make_pair(vx[j], vy[j]))) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << tx << ' ' << ty << endl;
      return 0;
    }
  }

  return 0;
}