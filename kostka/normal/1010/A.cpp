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
  int n, m;
  cin >> n >> m;
  vi A(2*n);
  for(int i=0; i<2*n; i+=2) cin >> A[i];
  for(int i=1; i<2*n; i+=2) cin >> A[i];
  double mass = m;
  for(int i=0; i<2*n; i++) {
    if(A[i] == 1) {
      cout << -1 << "\n";
      return 0;
    }
    mass += mass / (A[i] - 1);
  }
  cout << fixed << setprecision(20) << mass - m << "\n";
  return 0;
}