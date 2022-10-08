//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  if((2LL * n * m) % k) {
    puts("NO");
    return 0;
  }
  if(k&1) {
    int d = __gcd(n, k);
    int x = n/d, y = m/(k/d);
    if(x < n) x *= 2;
    else y *= 2;
    cout << "YES\n";
    cout << 0 << " " << 0 << "\n";
    cout << x << " " << 0 << "\n";
    cout << 0 << " " << y << "\n";
  } else {
    k /= 2;
    int d = __gcd(n, k);
    int x = n/d, y = m/(k/d);
    cout << "YES\n";
    cout << 0 << " " << 0 << "\n";
    cout << x << " " << 0 << "\n";
    cout << 0 << " " << y << "\n";
  }
}