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
    cout << string(k, 'a');
    for (int i=0; i<n-k; i++) {
      cout << char('a' + (i+1)%3);
    }
    cout << '\n';
  }
}