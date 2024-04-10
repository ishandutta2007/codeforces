// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

vector<int> a;
int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int p = 1;
  int n;
  cin >> n;
  for (int i=1; i<=n; i++) {
    if (gcd(i, n) == 1) {
      a.push_back(i);
      p = p * 1ll * i % n;
    }
  }

  if (p != 1) {
    a.pop_back();
  }

  cout << a.size() << '\n';
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';


}