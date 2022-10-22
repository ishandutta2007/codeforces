#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll k;
  cin >> k;
  k--;
  int len = 1;
  ll pow10 = 1;
  while (1) {
    if (k < 9*pow10*len) {
      ll n = pow10+k/len;
      cout << to_string(n)[k%len] << endl;
      return 0;
    }
    k -= 9*pow10*len;
    pow10 *= 10;
    len++;
  }
}