#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e5 + 50;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  a += 2; b += 1;
  printf("%d\n", min(min(a, b), c) * 3 - 3);
  return 0;
}