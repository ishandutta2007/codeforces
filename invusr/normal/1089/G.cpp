#include <bits/stdc++.h>
using namespace std;

const int N = 7;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    int exist[N], sum = 0;
    for (int i = 0; i < N; ++i) {
      cin >> exist[i];
      sum += exist[i];
    }

    int answer = numeric_limits<int>::max();
    for (int i = 0; i < N; ++i) {
      int remain = k, result = 0;
      for (int j = i; remain && j < N; ++j) {
        remain -= exist[j];
        ++result;
      }
      if (!remain || remain % sum) {
        result += remain / sum * N;
        remain %= sum;
      } else {
        result += (remain / sum - 1) * N;
        remain = sum;
      }
      for (int j = 0; remain; ++j) {
        remain -= exist[j];
        ++result;
      }
      answer = min(answer, result);
    }
    cout << answer << endl;
  }

  return 0;
}