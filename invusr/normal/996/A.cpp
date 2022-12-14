#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m = 0;
  cin >> n;
  m += n / 100, n %= 100;
  m += n / 20, n %= 20;
  m += n / 10, n %= 10;
  m += n / 5 + n % 5;
  cout << m << endl;

  return 0;
}