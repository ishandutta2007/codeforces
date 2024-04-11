#include "bits/stdc++.h"

using namespace std;

vector <int> A;

long long silnia(int a)
{
  if(a==0)
    return 1;
  return 1LL*a*silnia(a-1);
}

void faktoryzuj(long long x, int a)
{
  for(int i=2; x!=1LL; i++)
    while(x % i == 0)
    {
      A[i] += a;
      x /= i;
    }
}

int main()
{
  A.resize(10);
  int n;
  cin >> n;
  string x;
  cin >> x;
  for(int i=0; i<n; i++)
    faktoryzuj(silnia(x[i]-'0'),1);
  for(int i=9; i>=2; i--)
    while(A[i])
    {
       faktoryzuj(silnia(i),-1);
       cout << i;
    }
  return 0;
}