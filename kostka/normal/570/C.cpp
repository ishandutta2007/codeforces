//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int DRZ = 524288;
int drz[2*DRZ];

void wstaw(int a, int b)
{
  a += DRZ;
  drz[a] = b;
  do
  {
    a /= 2;
    drz[a] = drz[2*a] + drz[2*a+1];
  }
  while(a != 1);
}

int main()
{
  int n, q;
  cin >> n >> q;
  string x;
  cin >> x;
  for(int i=1; i<n; i++)
    if(x[i-1] == '.' and x[i] == '.')
      wstaw(i,1);
  while(q--)
  {
    int a;
    char b;
    cin >> a >> b;
    a--;
    x[a] = b;
    if(a != 0)
    {
      if(x[a-1] == '.' and x[a] == '.')
        wstaw(a,1);
      else
        wstaw(a,0);
    }
    if(a != n-1)
    {
      if(x[a+1] == '.' and x[a] == '.')
        wstaw(a+1, 1);
      else
        wstaw(a+1, 0);
    }
    cout << drz[1] << "\n";
  }
  return 0;
}