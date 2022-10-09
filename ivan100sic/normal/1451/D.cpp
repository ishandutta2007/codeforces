// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    ll d, k;
    cin >> d >> k;
    ll q = 0;
    while (2*q*q <= d*d) {
      q += k;
    }
    q -= k;

    if (q*q + (q+k)*(q+k) <= d*d) {
      cout << "Ashish\n";
    } else {
      cout << "Utkarsh\n";
    }
  }
}