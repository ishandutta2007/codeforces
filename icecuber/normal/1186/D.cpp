#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll r = 0;
  for (int i = 0; i < n; i++) {
    double fa;
    cin >> fa;
    ll a = round(fa*100000);
    ll b = a+50000-r;
    b -= (b%100000+100000)%100000;
    r += b-a;
    cout << int(b/100000) << endl;
  }
}