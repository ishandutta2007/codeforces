/**
 *    author:  tourist
 *    created: 01.04.2020 17:50:41       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a;
  cin >> a;
  vector<int> b(6);
  for (int i = 0; i < 6; i++) {
    b[i] = (a >> i) & 1;
  }
  vector<int> c(6);
  c[4] = b[0];
  c[1] = b[1];
  c[3] = b[2];
  c[2] = b[3];
  c[0] = b[4];
  c[5] = b[5];
  int d = 0;
  for (int i = 0; i < 6; i++) {
    d |= (c[i] << i);
  }
  cout << d << '\n';
  return 0;
}