#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll a, b;
  cin >> a >> b;
  int n = 0;
  while (a <= b) {
    a *= 3;
    b *= 2;
    n++;
  }
  cout << n << endl;
}