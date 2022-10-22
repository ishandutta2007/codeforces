#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  int c = 0;
  while (s) {
    s -= min(s,n);
    c++;
  }
  cout << c << endl;
}