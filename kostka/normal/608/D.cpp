//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 507;
int tab[MAXN];
int mem[MAXN][MAXN];

int dp(int a, int b)
{
  if(a >= b)
    return 0;
  if(mem[a][b] != -1)
    return mem[a][b];
  int res = 1 + dp(a+1, b);
  if(tab[a] == tab[a+1])
    res = min(res, 1 + dp(a+2, b));
  for(int i=a+2; i<b; i++)
    if(tab[i] == tab[a])
      res = min(res, dp(a+1, i) + dp(i+1, b));
  return mem[a][b] = res;
}

int main()
{
  memset(mem, -1, sizeof(mem));
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> tab[i];
  cout << dp(0,n) << "\n";
  return 0;
}