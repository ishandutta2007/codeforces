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
    int N;
    cin >> N;
    vector<int> pos, neg, zero;
    int sumPos = 0, sumNeg = 0;
    for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      if (x > 0) {
        pos.push_back(x);
        sumPos += x;
      } else if (x < 0) {
        neg.push_back(x);
        sumNeg += -x;
      } else {
        zero.push_back(x);
      }
    }

    if (sumPos == sumNeg) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      if (sumPos < sumNeg) swap(pos, neg);
      for (int x : pos) cout << x << ' ';
      for (int x : neg) cout << x << ' ';
      for (int x : zero) cout << x << ' ';
      cout << '\n';
    }
  }
  return 0;
}