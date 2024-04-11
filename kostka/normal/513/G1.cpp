#include "bits/stdc++.h"

using namespace std;

int perm[107];
int n, k, ile = 0;
long long wyn = 0;

void go(int a)
{
  if(a==k)
  {
    int inw = 0;
    for(int i=0; i<n; i++)
      for(int j=i+1; j<n; j++)
        if(perm[i] > perm[j])
          inw++;
    ile++;
    wyn += inw;
    return;
  }
  for(int i=0; i<n; i++)
    for(int j=i; j<n; j++)
    {
      reverse(perm+i, perm+j+1);
      go(a+1);
      reverse(perm+i, perm+j+1);
    }
} 

int main()
{
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++)
    scanf("%d", &perm[i]);
  go(0);
  printf("%.50lf\n", (double)wyn/ile);
}