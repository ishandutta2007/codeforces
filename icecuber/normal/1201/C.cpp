#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  a[n] = 1e10;
  ll count = 1;
  for (int i = n/2; i < n; i++) {
    ll need = (a[i+1]-a[i])*count;
    if (need <= k) {
      k -= need;
    } else {
      cout << k/count+a[i] << endl;
      return 0;
    }
    count++;
  }
}