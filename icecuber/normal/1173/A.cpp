#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x, y, z;
  cin >> x >> y >> z;
  if (x-y-z > 0) cout << '+' << endl;
  else if (x-y+z < 0) cout << '-' << endl;
  else if (x==y && z == 0) cout << '0' << endl;
  else cout << '?' << endl;
}