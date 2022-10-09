// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[100005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;

  int x12, x23, o12, o23, o13;

  cout << "XOR 1 2\n" << flush;
  cin >> x12;

  cout << "XOR 2 3\n" << flush;
  cin >> x23;

  cout << "OR 1 2\n" << flush;
  cin >> o12;

  cout << "OR 2 3\n" << flush;
  cin >> o23;

  cout << "OR 1 3\n" << flush;
  cin >> o13;

  int x13 = x12 ^ x23;

  int l = 31 - __builtin_clz(n);

  for (int i=0; i<l; i++) {
    int m = (1 << i);
    if ((x12 & m) == 0) {
      a[1] |= o12 & m;
      a[2] |= o12 & m;
      a[3] |= (o12 ^ x13) & m;
    } else if ((x13 & m) == 0) {
      a[1] |= o13 & m;
      a[2] |= (o13 ^ x23) & m;
      a[3] |= o13 & m;
    } else {
      a[1] |= (o23 ^ x12) & m;
      a[2] |= o23 & m;
      a[3] |= o23 & m;
    }
  }

  for (int i=4; i<=n; i++) {
    cout << "XOR 1 " << i << "\n" << flush;
    int x;
    cin >> x;
    a[i] = x ^ a[1];
  }

  cout << "! ";
  for (int i=1; i<=n; i++) {
    cout << a[i] << " \n"[i == n];
  }
  cout << flush;
}