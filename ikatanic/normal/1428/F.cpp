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

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;

  cin >> s;
  i64 ret = 0;
  i64 sum = 0;

  vector<int> next(n + 1, n);
  i64 ones = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      if (i + 1 < n && s[i + 1] == '1') {
        for (int j = i + 1; j < n && s[j] == '1'; ++j) {
          next[j - i] = j;
        }
      }
      ones = 0;
    } else {
      ones++;
      sum += next[ones] - i;
    }
    ret += sum;
  }

  cout << ret << '\n';
  return 0;
}