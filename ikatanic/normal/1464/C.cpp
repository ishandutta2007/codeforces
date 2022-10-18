#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

int a[111];

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  i64 T;
  cin >> n >> T;

  string S;
  cin >> S;

  vector<i64> c(62);
  for (int i = 0; i < n; ++i) {
    int x = S[i] - 'a';
    if (i == n - 1) {
      T -= 1 << x;
      continue;
    }
    if (i == n - 2) {
      T += 1 << x;
      continue;
    }
    c[x]++;
  }

  for (int i = 0; i < 26; ++i) {
    T += c[i] * (1 << i);
  }

  if (T % 2 || T < 0) {
    cout << "No\n";
    return 0;
  }

  T /= 2;

  for (int i = 0; i < 61; ++i) {
    if (T % 2 && c[i] == 0) {
      cout << "No\n";
      return 0;
    }
    if (T % 2) c[i]--;
    c[i + 1] += c[i] / 2;
    T /= 2;
  }

  if (T) {
    cout << "No\n";
    return 0;
  }

  cout << "Yes\n";
  return 0;
}