#include "bits/stdc++.h"

using namespace std;

map <pair <int, int> , int> M;

int fi;

int main()
{
  int n, m, x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for(int i=0; i<n; i++)
    if((1LL*x*i)%n==1LL)
    {
       fi = i;
       break;
    }
  while(m--)
  {
     int a, b;
     scanf("%d%d", &a, &b);
     a %= n;
     b %= n;
     b = b+(1LL*(-a)*fi*y) % n;
     b = (b+n)%n;
     cerr << b << "\n";
     M[make_pair(0,b)] += 1;
  }
  int wyn = 0;
  int res = 0;
  for(map<pair <int, int> , int>::iterator it = M.begin(); it != M.end(); it++)
     if(wyn < (*it).second)
     {
         wyn = (*it).second;
         res = (*it).first.second;
     }
  printf("0 %d\n", res);
  return 0;
}