#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;
using r32 = double;
using r64 = long double;

template <class T>
inline bool relax(T &a, T b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool tense(T &a, T b) {
  return b < a ? a = b, true : false;
}

const int N = 333333;

int n, a[N];

int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);

  cin >> n;
  s64 answer = 0;
  int remain = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);/*
    answer += x / 3;
    x %= 3;
    if (x == 2 && remain) {
      --remain, x = 0;
      ++answer;
    }
    remain += x;*/
    int l = min(remain, x / 2);
    x -= l * 2;
    remain -= l;
    answer += l + x / 3;
    remain += x % 3;
  }
  cout << answer << endl;

  return 0;
}