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
    int n, k;
    cin >> n >> k;
    for (int i=1; i<=k; i++) {
      cout << (i < 2*k-n ? i : 3*k-n-i) << " \n"[i == k];
    }
  }
}