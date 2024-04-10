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
    auto b = a;
    sort(begin(b), end(b));
    cout << find_if(begin(a), end(a), [&](int x) { return x != b[1]; }) - begin(a) + 1 << '\n';
  }
}