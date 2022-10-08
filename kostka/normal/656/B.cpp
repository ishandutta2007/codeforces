//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 20;
int M[MAXN], R[MAXN];

int lcm(int a, int b)
{
  return a/__gcd(a,b)*b;
}

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> M[i];
  for(int i=0; i<n; i++)
    cin >> R[i];
  int lc = 1;
  for(int i=0; i<n; i++)
    lc = lcm(lc, M[i]);
  int ile = 0;
  for(int i=0; i<lc; i++)
  {
    bool czy = false;
    for(int j=0; j<n; j++)
      if(i % M[j] == R[j])
        czy = true;
    if(czy)
      ile++;
  }
  cout << fixed << setprecision(20) << 1.0*ile/lc << "\n";
  return 0;
}