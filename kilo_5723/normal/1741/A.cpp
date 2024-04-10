#include <cstdio>
#include <iostream>
using namespace std;
int size(string s) {
  if (s.back() == 'L') return s.size();
  if (s.back() == 'S') return -(int)s.size();
  return 0;
}
int sign(int n) { return (n > 0) - (n < 0); }
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string a, b;
    cin >> a >> b;
    switch (sign(size(a) - size(b))) {
      case -1:
        puts("<");
        break;
      case 0:
        puts("=");
        break;
      case 1:
        puts(">");
        break;
    }
  }
  return 0;
}