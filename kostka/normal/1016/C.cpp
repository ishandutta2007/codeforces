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

const int MAXN = 300007;
int tab[2][MAXN];
ll pref[2][MAXN], lew[2][MAXN], pra[2][MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=0; i<2*n; i++) cin >> tab[i/n][i%n];
  for(int i=0; i<2; i++) {
    for(int j=n-1; j>=0; j--) {
      pref[i][j] = tab[i][j] + pref[i][j+1];
      lew[i][j] = 1LL * (j+1) * tab[i][j] + lew[i][j+1];
      pra[i][j] = 1LL * (n-j) * tab[i][j] + pra[i][j+1];
    }
  }
  ll ret = 0, akt = 0;
  int i = 0;
  for(int j=0; j<n; j++) {
    ret = max(ret, akt + lew[i][j] + 1LL * j * pref[i][j] + pra[1-i][j] + 1LL * (j+n) * pref[1-i][j] - pref[0][0] - pref[1][0]);
    akt += 1LL * (2*j+1) * tab[i][j] + 1LL * (2*j+2) * tab[1-i][j];
    i = 1-i;
  }
  cout << ret << "\n";
  return 0;
}