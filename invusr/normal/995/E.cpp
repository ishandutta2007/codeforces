#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const int L = 100;
const int N = 40000;

int u, v, p;

inline int modinv(int a) {
  int res = 1;
  for (int i = p - 2; i; i >>= 1) {
    if (i & 1) {
      res = (s64)res * a % p;
    }
    a = (s64)a * a % p;
  }
  return res;
}

vector<int> path[N];
map<int, int> all;

vector<int> half;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> u >> v >> p;

  srand(time(nullptr));

  for (int k = 0; k < N; ++k) {
    int x = u;
    path[k].resize(L);
    for (int i = 0; i < L; ++i) {
      int t = path[k][i] = rand() % 3 + 1;
      if (t == 1) {
        x = (x + 1) % p;
      } else {
        if (t == 2) {
          x = (x + p - 1) % p;
        } else {
          x = modinv(x);
        }
      }
    }
    all[x] = k;
  }

  half.resize(L);
  while (true) {
    int x = v;
    for (int i = L - 1; i >= 0; --i) {
      int t = half[i] = rand() % 3 + 1;
      if (t == 1) {
        x = (x + p - 1) % p;
      } else {
        if (t == 2) {
          x = (x + 1) % p;
        } else {
          x = modinv(x);
        }
      }
    }

    auto it = all.find(x);
    if (it != all.end()) {
      vector<int> &pref = path[it->second];
      ostream_iterator<int> screen(cout, "\n");
      cout << L * 2 << endl;
      copy(pref.begin(), pref.end(), screen);
      copy(half.begin(), half.end(), screen);
      cout << endl;
      break;
    }
  }

  return 0;
}