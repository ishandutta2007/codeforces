//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

long long hasz[5007], rev_hasz[5007];
const int PRI = 27;
const int MOD = 1000000007;

string x;
int n;

int pow(int a, int b)
{
  if(b == 0)
    return 1;
  int aa = pow(a, b/2);
  if(b % 2)
    return (1LL*aa*aa)%MOD*1LL*a%MOD;
  else
    return (1LL*aa*aa)%MOD;
}

int odw(int a)
{
  return pow(a, MOD-2);
}

int ooo[5007];
bool compare(int len, int x, int y)
{
  if(len == 0)
    return true;
  long long hasz1 = (hasz[x+len-1] - hasz[x-1] + MOD)%MOD * ooo[x] % MOD;
  int ry = n-y+1;
  long long hasz2 = (rev_hasz[ry+len-1] - rev_hasz[ry-1] + MOD)%MOD * ooo[ry] % MOD;
  return hasz1 == hasz2;
}

bool vis[5007][5007];
int X[5007][5007];

int deg(int a, int b)
{
  if(vis[a][b])
    return X[a][b];
  vis[a][b] = true;
  int len = (b-a+1);
  if(len == 1)
    return X[a][b] = 1;
  if(compare(len/2, a, b))
    return X[a][b] = 1 + deg(a, a+len/2-1);
  else
    return X[a][b] = 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> x;
  n = (int)x.size();
  long long e = PRI;
  for(int i=1; i<=n; i++)
    ooo[i] = odw(pow(PRI,i));
  for(int i=0; i<n; i++)
  {
    hasz[i+1] = e*x[i];
    e *= PRI;
    e %= MOD;
  }
  for(int i=0; i<n; i++)
  {
    hasz[i+1] += hasz[i];
    hasz[i+1] %= MOD;
  }
  reverse(x.begin(), x.end());
  e = PRI;
  for(int i=0; i<n; i++)
  {
    rev_hasz[i+1] = e*x[i];
    e *= PRI;
    e %= MOD;
  }
  for(int i=0; i<n; i++)
  {
    rev_hasz[i+1] += rev_hasz[i];
    rev_hasz[i+1] %= MOD;
  }
  vector <long long> w(n+1);
  for(int i=1; i<=n; i++)
    for(int j=0; j<=n-i; j++)
      w[deg(i,i+j)]++;
  for(int i=n-1; i>=0; i--)
    w[i] += w[i+1];
  for(int i=1; i<=n; i++)
    cout << w[i] << " ";
  cout << "\n";
  return 0;
}