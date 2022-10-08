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
//
// int n;
// int tab[5][5];
// int res;
// void go(int a, int b) {
//   if(a == n) {
//     // for(int i=0; i<n; i++) {
//     //   for(int j=0; j<n; j++) cerr << tab[i][j] << " ";
//     //   cerr << "\n";
//     // }
//     // cerr << "---\n";
//     for(int i=0; i<n; i++) {
//       bool bad = false;
//       for(int k=0; k<n; k++) if(tab[i][0] != tab[i][k]) bad = true;
//       if(!bad) {
//         res++;
//         return;
//       }
//       bad = false;
//       for(int k=0; k<n; k++) if(tab[0][i] != tab[k][i]) bad = true;
//       if(!bad) {
//         res++;
//         return;
//       }
//     }
//     return;
//   }
//   if(b == n) {
//     go(a+1, 0);
//     return;
//   }
//   for(int i=1; i<=3; i++) {
//     tab[a][b] = i;
//     go(a, b+1);
//   }
// }

const int MOD = 998244353;
const int MAXN = 1000007;

int sil[MAXN], odw[MAXN], tri[MAXN], trin[MAXN];

int pot(int a, int b) {
  if(b==0) return 1;
  int p = pot(a, b>>1);
  int p2 = (1LL*p*p)%MOD;
  if(b&1) return (1LL*p2*a)%MOD;
  else return p2;
}

int binom(int a, int b) {
  return (1LL*sil[a] * odw[b])%MOD * odw[a-b] % MOD;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  sil[0] = 1;
  for(int i=1; i<=n; i++) sil[i] = 1LL * i * sil[i-1] % MOD;
  odw[n] = pot(sil[n], MOD-2);
  for(int i=n; i>0; i--) odw[i-1] = 1LL * i * odw[i] % MOD;
  tri[0] = 1;
  for(int i=1; i<=n; i++) tri[i] = 3LL * tri[i-1] % MOD;
  trin[0] = 1;
  for(int i=1; i<=n; i++) trin[i] = 1LL * tri[n] * trin[i-1] % MOD;
  // assert(1LL * sil[5] * odw[5] % MOD == 1);
  // assert(binom(5,4) == 5);
  // assert(tri[4] == 81);
  ll ret = 0;
  for(int i=1; i<=n; i++) {
    ret += 3LL * pot(trin[1]-3, i-1) % MOD * trin[n-i] % MOD;
    ret %= MOD;
    ret += ((i%2) ? 1LL : -1LL) * binom(n, i) % MOD * (1LL * (tri[i]-3) * trin[n-i] % MOD + (3LL * pot(tri[n-i]-1, n))) % MOD;
    ret %= MOD;
  }
  ret = ((ret % MOD) + MOD) % MOD;
  cout << ret << "\n";
  return 0;
}