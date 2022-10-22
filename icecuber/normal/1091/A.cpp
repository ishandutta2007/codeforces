#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x = min(min(a,b-1),c-2);
  cout << x*3+3 << endl;
}