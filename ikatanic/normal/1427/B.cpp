#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> gaps;
    int totalL = 0, lastW = -1;
    int score = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'W') {
        if (i > 0 && s[i - 1] == 'W') {
          score += 2;
        } else {
          score += 1;
        }

        if (lastW != -1 && lastW != i - 1) {
          gaps.push_back(i - lastW - 1);
        }
        lastW = i;
      } else {
        totalL++;
      }
    }

    k = min(k, totalL);
    if (lastW == -1) {
      assert(score == 0);
      assert(gaps.size() == 0);
      score += k > 0 ? 2 * k - 1 : 0;
    } else {
      score += k * 2;
      sort(gaps.begin(), gaps.end());
      for (int g : gaps) {
        if (k >= g) {
          score++;
          k -= g;
        }
      }
    }

    cout << score << '\n';
  }
  return 0;
}