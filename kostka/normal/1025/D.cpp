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

const int MAXN = 707;
bool dzieli[MAXN][MAXN];
bool lef[MAXN][MAXN], rig[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vi A(n);
  for(int i=0; i<n; i++) cin >> A[i];
  for(int i=0; i<n; i++) for(int j=i; j<n; j++) {
    dzieli[i][j] = dzieli[j][i] = (__gcd(A[i], A[j]) > 1);
  }
  for(int i=0; i<n; i++) lef[i][i] = rig[i][i] = true;
  for(int i=1; i<n; i++) {
    for(int j=0; j<n-i; j++) {
      for(int k=0; k<=i; k++) {
        if(dzieli[j+k][j+i] and lef[j][j+k] and rig[j+k][j+i-1]) lef[j][j+i] = true;
        if(dzieli[j][j+k] and lef[j+1][j+k] and rig[j+k][j+i]) rig[j][j+i] = true;
      }
    }
  }
  for(int i=0; i<n; i++) if(lef[0][i] and rig[i][n-1]) {
    puts("Yes");
    return 0;
  }
  puts("No");
  return 0;
}