// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll br(vector<int> a) {
  map<int, int> m;
  ll z=0;
  for (int x : a) {
    z += m[x]++;
  }
  return z;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k), b(k);
    for (int i=0; i<k; i++) cin >> a[i];
    for (int i=0; i<k; i++) cin >> b[i];

    cout << k*(k-1)/2 - br(a) - br(b) << '\n';
  }
}