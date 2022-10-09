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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    ll s[2] = {0, 0};

    for (int i=0; i<n; i++) {
      s[i%2] += a[i];
    }

    for (int i=0; i<n; i++) {
      cout << (((i%2) ^ (s[0] > s[1])) ? a[i] : 1) << " \n"[i == n-1];
    }
  }
}