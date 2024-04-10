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
    for (int& x : a) cin >> x;
    
    int l = 0, r = n - 1, i = 0;
    while (l <= r) {
        if (i == 0) {
            cout << a[l++];
        } else {
            cout << a[r--];
        }
        cout << ' ';
        i ^= 1;
    }
    cout << '\n';
  }
}