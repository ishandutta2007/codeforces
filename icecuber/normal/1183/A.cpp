#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a;
  cin >> a;
  while (1) {
    int m = a, r = 0;
    while (m) {
      r += m%10;
      m /= 10;
    }
    if (r%4 == 0) {
      cout << a << endl;
      return 0;
    }
    a++;
  }
}