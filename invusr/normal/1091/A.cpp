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
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(a, min(b - 1, c - 2)) * 3 + 3 << endl;;

  return 0;
}