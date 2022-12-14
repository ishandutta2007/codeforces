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

int main() {
  int n;
  cin >> n;

  auto solve = [&](int n, int d) {
    s64 a = 1, b = n - (d - 1);
    s64 k = n / d;
    return (a + b) * k / 2ll;
  };

  vector<s64> answer;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      answer.push_back(solve(n, i));
      if (i != n / i) {
        answer.push_back(solve(n, n / i));
      }
    }
  }
  sort(answer.begin(), answer.end());
  for (s64 i : answer) {
    printf("%lld ", i);
  }

  return 0;
}