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

const int N = 700;

int n;
int a[N + 1];

bool ok[N + 2][N + 2];

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

bool le[N + 2][N + 2];
bool ri[N + 2][N + 2];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ok[i][j] = gcd(a[i], a[j]) > 1;
    }
  }

  for (int i = 1; i <= n; ++i) {
    le[i][i + 1] = ok[i][i + 1];
    ri[i][i - 1] = ok[i][i - 1];
  }

  bool answer = false;
  for (int len = 2; len <= n; ++len) {
    for (int i = 1; i + len - 1 <= n; ++i) {
      int j = i + len - 1;
      for (int k = i; k <= j; ++k) {
        if ((le[i][k] || i == k) && (ri[j][k] || j == k)) {
          le[i][j + 1] |= ok[k][j + 1];
          ri[j][i - 1] |= ok[k][i - 1];
          if (len == n) {
            answer = true;
          }
        }
      }
    }
  }

  cout << (answer ? "Yes" : "No") << endl;

  return 0;
}