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
    set<int> s;
    for (int i=0; i<n; i++) {
      for (int j=i+1; j<n; j++) {
        s.insert(a[j] - a[i]);
      }
    }
    cout << s.size() << '\n';
  }
}