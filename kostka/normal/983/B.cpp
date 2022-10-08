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

const int MAXN = 5007;
int bin[MAXN][MAXN], dp[MAXN][MAXN];

void binom(int n) {
  for(int i=0; i<=n; i++) {
    bin[i][0] = 1;
    for(int j=1; j<=i; j++) bin[i][j] = (bin[i-1][j-1] + bin[i-1][j]) % 2;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  // binom(n);
  vi a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) dp[i][0] = a[i];
  for(int e=1; e<n; e++) {
    for(int i=0; i<n-e; i++) {
      dp[i][e] = (dp[i][e-1] ^ dp[i+1][e-1]);
    }
  }
  for(int e=1; e<n; e++) {
    for(int i=0; i<n-e; i++) {
      dp[i][e] = max(dp[i][e], max(dp[i][e-1], dp[i+1][e-1]));
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int e, f;
    cin >> e >> f;
    e--; f--;
    cout << dp[e][f-e] << "\n";
  }
}