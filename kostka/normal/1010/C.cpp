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
  int n, k;
  cin >> n >> k;
  vi A(n);
  for(int i=0; i<n; i++) {
    cin >> A[i];
    A[i] %= k;
  }
  int gcd = A[0];
  for(int i=1; i<n; i++) gcd = __gcd(gcd, A[i]);
  vector <int> ret;
  int r = gcd;
  for(int i=0; i<k; i++) {
    ret.push_back(r);
    r += gcd;
    r %= k;
  }
  sort(ALL(ret));
  ret.resize(distance(ret.begin(), unique(ALL(ret))));
  cout << SZ(ret) << "\n";
  for(auto rr : ret) cout << rr << " ";
  cout << "\n";
  return 0;
}