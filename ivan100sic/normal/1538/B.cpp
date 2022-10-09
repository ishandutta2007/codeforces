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
    for (int& x : a) {
      cin >> x;
    }

    ll s = accumulate(begin(a), end(a), 0ll);

    if (s % n) {
      cout << "-1\n";
      continue;
    }

    cout << count_if(begin(a), end(a), [=](int x) { return x > s/n; }) << "\n";
  }
}