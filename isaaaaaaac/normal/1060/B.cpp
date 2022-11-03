#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long n;
int dp[50][2], tab[50];

inline int count(long long x) {
  int res = 0;
  while (x) {
    res += x % 10; x /= 10;
  }
  return res;
}

int main() {
  cin >> n;
  long long s = 0;
  while (s * 10 + 9 <= n) s = s * 10 + 9;
  printf("%d\n", count(s) + count(n - s));
  return 0;
}