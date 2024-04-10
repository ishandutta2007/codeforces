#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a[1000000], b[1000000];
vector<ll> wa[1000000], wb[1000000];

typedef unsigned long long ull;

ull mod = (1ll<<55)-55;

ll mul(ull a, ull b) {
  ll r = a*b-ull((long double)a*b/mod)*mod;
  while (r < 0) r += mod;
  while (r >= mod) r -= mod;
  return r;
}

int h, w;
void ways(string*a, vector<ll>*dp) {
  for (int i = 0; i < h; i++)
    dp[i].resize(w,0);
  dp[0][0] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') continue;
      if (i+1 < h) {
	dp[i+1][j] += dp[i][j];
	if (dp[i+1][j] >= mod) dp[i+1][j] -= mod;
      }
      if (j+1 < w) {
	dp[i][j+1] += dp[i][j];
	if (dp[i][j+1] >= mod) dp[i][j+1] -= mod;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> a[i];
    b[h-1-i] = a[i];
    reverse(b[h-1-i].begin(), b[h-1-i].end());
  }
  ways(a, wa);
  if (!wa[h-1][w-1]) {
    cout << 0 << endl;
    return 0;
  }
  ways(b, wb);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] != '#' && i+j && i+j != w+h-2 && mul(wa[i][j], wb[h-1-i][w-1-j]) == wa[h-1][w-1]) {
	cout << 1 << endl;
	return 0;
      }
    }
  }
  cout << 2 << endl;
}