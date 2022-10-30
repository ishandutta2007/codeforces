#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int l = 1, r = n;
  while (r - l > 1) {
    int m = l + ((r - l) >> 1);
    if (m % n == 0) m--;
    cout << "+ " << n - m % n << endl;
    l += n - m % n;
    r += n - m % n;
    m += n - m %n;
    int tmp;
    cin >> tmp;
    if (tmp == r / n)
      l = m;
    else
      r = m;
  }
  cout << "! " << l << endl;
  return 0;
}