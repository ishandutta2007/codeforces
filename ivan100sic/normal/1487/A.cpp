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
    int n, c=0;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    int l = *min_element(begin(a), end(a));

    for (int x : a) {
      if (x > l) c++;
    }

    cout << c << '\n';
  }
}