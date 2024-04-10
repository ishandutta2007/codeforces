// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll p[10] = {0, 2, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};
ll q[10] = {0, 3, 13, 211, 2003, 20011, 200003, 2000003, 20000003, 200000033};
ll e[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    ll x = p[a-c+1] * e[c-1];
    ll y = q[b-c+1] * e[c-1];

    cout << x << ' ' << y << '\n';
  }
}