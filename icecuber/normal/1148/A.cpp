#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll a, b, c;
  cin >> a >> b >> c;
  a = min(a,b+1);
  b = min(b,a+1);
  cout << c*2+a+b << endl;
}