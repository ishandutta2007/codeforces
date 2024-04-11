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
  vector <ll> A(n+7);
  vi B(n+7);
  for(int i=1; i<=n; i++) cin >> A[i];
  for(int i=1; i<=n; i++) B[i] = __builtin_popcountll(A[i]);
  vector <int> SB = B;
  partial_sum(SB.begin(), SB.end(), SB.begin());
  vi R = {1, 0};
  // vi R[2];
  // R[0].push_back(0);
  ll ret = 0;
  int parz = 0;
  for(int i=1; i<=n; i++) {
    if(B[i]&1) parz ^= 1;
    ret += R[parz];
    // ret += SZ(R[parz]);
    int mb = B[i];
    for(int j=i; j>=max(1, i-256); j--) {
      mb = max(mb, B[j]);
      int sb = SB[i] - SB[j-1];
      // cerr << sb << " " << mb << "\n";
      if(sb % 2 == 0 and mb > sb / 2) ret--;
    }
    R[parz]++;
    // R[parz].push_back(i);
  }
  cout << ret << "\n";
  return 0;
}