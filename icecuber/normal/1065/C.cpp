#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll h[200000];

int main() {
  ll n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> h[i];
  sort(h, h+n);

  ll r = k, cuts = 0, last = 1e9;
  for (int i = n-1; i >= 0; i--) {
    ll cost = last-h[i];
    while (cost*(n-1-i) > r) {
      cost -= r/(n-1-i);
      cuts++;
      r = k;
    }
    r -= cost*(n-1-i);
    last = h[i];
  }
  if (r != k) cuts++;
  cout << cuts << endl;
}