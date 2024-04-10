#include <bits/stdc++.h>
using namespace std;

void print(int x, int n) {
  for (int i = 0; i < n; ++i) {
    cout << x << ' ';
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int n1 = 0, n2 = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 1) {
      ++n1;
    } else {
      ++n2;
    }
  }
  if (!n1) {
    print(2, n);
  } else if (!n2) {
    print(1, n);
  } else {
    cout << "2 1 ";
    print(2, n2 - 1);
    print(1, n1 - 1);
  }
  cout << '\n';

  return 0;
}