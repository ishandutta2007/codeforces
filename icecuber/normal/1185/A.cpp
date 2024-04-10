#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll a[3], d;
  cin >> a[0] >> a[1] >> a[2] >> d;
  sort(a,a+3);
  cout << max(0ll,d+a[1]-a[2])+max(0ll,d-a[1]+a[0]) << endl;
}