#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, h, k;
  cin >> w >> h >> k;
  int r = 0;
  for (int i = 0; i < k; i++) {
    r += w+h+w+h-4;
    w -= 4;
    h -= 4;
  }
  cout << r << endl;
}