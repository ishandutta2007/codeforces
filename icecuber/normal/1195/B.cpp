#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k;
  cin >> n >> k;
  ll x = 0;
  while (x*x+3*x < 2*(k+n)) x++;
  cout << n-x << endl;
}