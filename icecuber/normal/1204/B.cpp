#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, l, r;
  cin >> n >> l >> r;
  cout << (1<<l)-1+n-l << ' ' << (1<<r)-1+(1<<r-1)*(n-r) << endl;
}