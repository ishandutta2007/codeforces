//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int DRZ = 1<<20;
int drz[2*DRZ];

void add(int x)
{
  x += DRZ;
  while(x)
  {
    drz[x] += 1;
    x /= 2;
  }
}

int sum(int a, int b)
{
  int res = 0;
  a += DRZ;
  b += DRZ;
  while(a < b)
  {
    if(a%2==1)
      res += drz[a++];
    if(b%2==0)
      res += drz[b--];
    a /= 2;
    b /= 2;
  }
  if(a == b)
    res += drz[a];
  return res;
}

int n;
int rozloz(int a, int b)
{
  if(a < 0 and b >= n)
    return sum(0,n-1);
  if(a < 0)
    return sum(a+n, n-1) + sum(0, b);
  if(b >= n)
    return sum(a, n-1) + sum(0, b-n);
  return sum(a,b);
}

int main()
{
  int k;
  cin >> n >> k;
  if(k > n/2)
    k = n - k;
  int cur = 0;
  long long ile = 1;
  vector <pair <int, int> > X;
  for(int i=0; i<n; i++)
  {
    int nex = (cur+k)%n;
    ile += rozloz(cur-k+1, cur+k-1) + 1;
    add(cur);
    cur = nex;
    cout << ile << " ";
  }
  cout << "\n";
  return 0;
}