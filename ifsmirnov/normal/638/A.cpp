#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, n;
  cin >> n >> a;
  if (a % 2 == 0)
    a = n + 1 - a;
  cout << (a + 1) / 2 << endl;
  return 0;
}