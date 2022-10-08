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
  vi A(n);
  for(int i=0; i<n; i++) cin >> A[i];
  auto foo = [&](int x) -> ll {
    map <int, int> M;
    M[0] = 1;
    int wsk = 0;
    ll ret = 0, tmp = 0;
    for(int i=0; i<n; i++) {
      if(A[i] < x) tmp -= M[--wsk];
      else tmp += M[wsk++];
      ret += tmp;
      M[wsk]++;
    }
    return ret;
  };
  cout << foo(m) - foo(m+1) << "\n";
  return 0;
}