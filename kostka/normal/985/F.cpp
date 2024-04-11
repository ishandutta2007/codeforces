//Bartek Kostka
//  You are not prepared!

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int MAXN = 2e5+1;

const int ILE = 26;

int tab1[MAXN][ILE], tab2[MAXN][ILE];
int A1[ILE], B1[ILE], A2[ILE], B2[ILE];

const int P1 = 17, P2 = 23;
const int MOD1 = 1000000007, MOD2 = 1000000009;
int pow1[MAXN], pow2[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  string x;
  cin >> x;
  pow1[0] = pow2[0] = 1;
  for(int i=1; i<=n; i++) {
    pow1[i] = (1LL*pow1[i-1]*P1)%MOD1;
    pow2[i] = (1LL*pow2[i-1]*P2)%MOD2;
  }
  for(int i=1; i<=n; i++) {
    tab1[i][x[i-1]-'a'] += pow1[i];
    tab2[i][x[i-1]-'a'] += pow2[i];
  }
  for(int i=1; i<=n; i++) {
    for(int j=0; j<ILE; j++) {
      tab1[i][j] = (tab1[i][j] + tab1[i-1][j]) % MOD1;
      tab2[i][j] = (tab2[i][j] + tab2[i-1][j]) % MOD2;
    }
  }
  while(q--) {
    int a, b, len;
    cin >> a >> b >> len;
    for(int i=0; i<ILE; i++) {
      A1[i] = (1LL * (tab1[a+len-1][i] - tab1[a-1][i] + MOD1) * pow1[n-a-len+1] % MOD1 + MOD1) % MOD1;
      B1[i] = (1LL * (tab1[b+len-1][i] - tab1[b-1][i] + MOD1) * pow1[n-b-len+1] % MOD1 + MOD1) % MOD1;
      A2[i] = (1LL * (tab2[a+len-1][i] - tab2[a-1][i] + MOD2) * pow2[n-a-len+1] % MOD2 + MOD2) % MOD2;
      B2[i] = (1LL * (tab2[b+len-1][i] - tab2[b-1][i] + MOD2) * pow2[n-b-len+1] % MOD2 + MOD2) % MOD2;
    }
    sort(A1, A1+ILE);
    sort(B1, B1+ILE);
    sort(A2, A2+ILE);
    sort(B2, B2+ILE);
    bool ok = true;
    for(int i=0; i<ILE; i++) {
      if(A1[i] != B1[i] or A2[i] != B2[i]) {
        ok = false;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}