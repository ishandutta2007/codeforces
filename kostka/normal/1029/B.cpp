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
  int n;
  cin >> n;
  vi A(n);
  for(int i=0; i<n; i++) cin >> A[i];
  int r = 0, res = 0;
  for(int l=0; l<n; l++) {
    while(r < n and (l == r or A[r] <= 2 * A[r-1])) r++;
    res = max(res, r-l);
  }
  cout << res << "\n";
  return 0;
}