#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m;
  cin >> n >> m;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    cout << (sum+a)/m-sum/m << ' ';
    sum += a;
  }
  cout << endl;
}