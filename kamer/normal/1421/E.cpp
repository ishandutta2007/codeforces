#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void) {
  ll n;
  cin >> n;
  const ll MIN_VAL = - ((ll) 1000000000) * n * ((ll) 2);
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << a[0] << "\n";
    return 0;
  }
  ll alt_plus = a[0];
  ll alt_minus = -a[0];
  ll sums[3];
  for (int i = 0; i < 3; i++) sums[i] = MIN_VAL;
  for (int i = 1; i < n; i++) {
    ll temp_sums[3];
    for (int j = 0; j < 3; j++) temp_sums[j] = MIN_VAL;
    for (int j = 0; j < 3; j++) {
      temp_sums[j] = max(temp_sums[j], sums[(j + 1) % 3] + a[i]);
      temp_sums[j] = max(temp_sums[j], sums[(j + 2) % 3] - a[i]);
    }
    if (i % 2 == 1) {
      temp_sums[1] = max(temp_sums[1], alt_plus + a[i]);
      temp_sums[2] = max(temp_sums[2], alt_minus - a[i]);
      alt_plus -= a[i];
      alt_minus += a[i];
    } else {
      temp_sums[1] = max(temp_sums[1], alt_plus - a[i]);
      temp_sums[2] = max(temp_sums[2], alt_minus + a[i]);
      alt_plus += a[i];
      alt_minus -= a[i];
    }
    for (int j = 0; j < 3; j++) sums[j] = temp_sums[j];
  }
  cout << sums[2] << "\n";
  return 0;

}