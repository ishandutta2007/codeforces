// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[105];
bitset<200005> d[105];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  int z = accumulate(a, a+n, 0);

  d[0][0] = 1;
  for (int i=0; i<n; i++) {
    d[i+1] = d[i] | (d[i] << a[i]);
  }

  if (z % 2 || !d[n][z/2]) {
    cout << "0\n";
    return 0;
  }

  cout << "1\n";
  cout << min_element(a, a+n, [](int x, int y) { return __builtin_ctz(x) < __builtin_ctz(y); }) - a + 1 << '\n';
}