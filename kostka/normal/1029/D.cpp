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
  for(int i=0; i<n; i++) cin >> A[i];
  vi dzi = {1};
  for(int i=1; i<=10; i++) {
    dzi.push_back((10LL * dzi.back()) % k);
  }
  vector <int> P[11];
  for(int j=0; j<=10; j++) {
    for(int i=0; i<n; i++) {
      P[j].push_back((1LL * dzi[j] * A[i]) % k);
    }
  }
  vector <int> R[11];
  for(int i=0; i<=10; i++) R[i] = P[i];
  for(int i=0; i<=10; i++) sort(P[i].begin(), P[i].end());
  ll ret = 0;
  for(int i=0; i<n; i++) {
    int rest = k - (A[i] % k);
    if(rest == k) rest = 0;
    int dl = to_string(A[i]).size();
    ret += upper_bound(ALL(P[dl]), rest) - lower_bound(ALL(P[dl]), rest);
    if(R[dl][i] == rest) ret--;
  }
  cout << ret << "\n";
  return 0;
}