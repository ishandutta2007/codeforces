#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (a==d && (!c||a)) << endl;
}