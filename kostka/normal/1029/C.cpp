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
  vector <int> X(n+7), Y(n+7);
  X[0] = 0;
  X[n+1] = 0;
  Y[0] = 1e9;
  Y[n+1] = 1e9;
  for(int i=1; i<=n; i++) {
    cin >> X[i] >> Y[i];
  }
  vector <int> LX = X, LY = Y, RX = X, RY = Y;
  for(int i=2; i<=n; i++) {
    LX[i] = max(LX[i-1], X[i]);
    LY[i] = min(LY[i-1], Y[i]);
  }
  for(int i=n-1; i>=1; i--) {
    RX[i] = max(RX[i+1], X[i]);
    RY[i] = min(RY[i+1], Y[i]);
  }
  int res = 0;
  for(int i=1; i<=n; i++) {
    // cerr << min(LY[i-1], RY[i+1]) << " " << max(LX[i-1], RX[i+1]) << "\n";
    res = max(res, min(LY[i-1], RY[i+1]) - max(LX[i-1], RX[i+1]));
  }
  cout << res << "\n";
  return 0;
}