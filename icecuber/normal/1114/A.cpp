#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x, y, z;
  cin >> x >> y >> z;
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a >= x && a+b >= x+y && a+b+c >= x+y+z ? "YES" : "NO") << endl;
}