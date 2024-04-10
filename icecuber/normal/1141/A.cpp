#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ok = !(m%n);
  m /= n;
  int ans = 0;
  while (m%2==0) ans++, m /= 2;
  while (m%3==0) ans++, m /= 3;
  ok &= m==1;
  cout << (ok ? ans : -1) << endl;
}