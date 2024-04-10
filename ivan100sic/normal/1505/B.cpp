// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int x;
  cin >> x;
  x %= 9;
  if (x == 0) x = 9;
  cout << x << '\n';
}