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

  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;
    int ret = 0;
    for (int i = 0; i < (int)S.size(); ++i) {
      bool need = false;
      if (i > 0 && S[i] == S[i - 1]) need = true;
      if (i - 1 > 0 && S[i] == S[i - 2]) need = true;

      if (need) {
        S[i] = '0';
        ret++;
      }
    }
    cout << ret << '\n';
  }

  return 0;
}