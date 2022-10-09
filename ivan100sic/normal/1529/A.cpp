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
    map<int, int> a;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      a[x]++;
    }
    cout << n - a.begin()->second << '\n';
  }
}