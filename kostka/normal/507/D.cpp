//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN  = 1007;
const int MAXK = 107;
bool done[MAXN][MAXK][2];
long long tab[MAXN][MAXK][2], e[MAXN], f[MAXN];
int n, k, m;

long long dp(int a, int b, bool c)
{
  if(done[a][b][c])
    return tab[a][b][c];
  done[a][b][c] = true;
  long long &t = tab[a][b][c];
  if(b==0 and c)
    return t = e[n-a];
  if(a==n)
    return t = 0;
  t = 0;
  for(int i=0; i<10; i++)
  {
    t += dp(a+1, (b+f[a]*i)%k, (c or i));
    t %= m;
  }
  return t%m;
}

int main()
{
  cin >> n >> k >> m;
  e[0] = 1%m;
  e[1] = 9%m;
  for(int i=2; i<=n; i++)
    e[i] = (e[i-1]*10)%m;
  f[0] = 1;
  for(int i=1; i<=n; i++)
    f[i] = (f[i-1]*10)%k;
  cout << dp(0,0,false) << "\n";
  return 0;
}