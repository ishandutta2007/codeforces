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
    vector<int> a;
    for (int i=(k+1)/2; i<k; i++) a.push_back(i);
    for (int i=k+1; i<=n; i++) a.push_back(i);

    cout << a.size() << '\n';
    for (int x : a) cout << x << ' ';
    cout << "\n";
  }
}