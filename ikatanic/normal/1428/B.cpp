#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    string s;
    int n;
    cin >> n;
    cin >> s;

    bool isCycleForward = true;
    bool isCycleBackward = true;
    for (int i = 0; i < n; ++i) {
      isCycleForward &= s[i] != '<';
      isCycleBackward &= s[i] != '>';
    }
    bool isCycle = isCycleForward || isCycleBackward;

    int ret = 0;
    for (int i = 0; i < n; ++i) {
      bool isReturnable = [&]() {
        char prev = s[(i - 1 + n) % n];
        char next = s[i];
        if (prev == '-' || next == '-') return true;
        if (prev != next) return false;
        return isCycle;
      }();

      if (isReturnable) ret++;
    }

    cout << ret << '\n';
  }

  return 0;
}