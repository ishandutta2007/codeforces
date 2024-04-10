#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll d = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    sum += a;
    if (a%2) {
      d += i%2 ? 1 : -1;
    }
  }
  cout << (sum-abs(d))/2 << endl;
}