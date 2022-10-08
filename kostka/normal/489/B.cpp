#include "bits/stdc++.h"

using namespace std;

const int MAXN = 107;
int a[MAXN], b[MAXN];

int main()
{
   int n, m;
   scanf("%d", &n);
   for(int i=0; i<n; i++)
      scanf("%d", a+i);
   scanf("%d", &m);
   for(int i=0; i<m; i++)
      scanf("%d", b+i);
   sort(a, a+n);
   sort(b, b+m);
   int i = 0, j = 0, res = 0;
   while(true)
   {
      while(j<m && a[i]-1 > b[j])
         j++;
      while(i<n && a[i] < b[j]-1)
         i++;
      if(i==n || j==m)
         break;
      if(abs(a[i]-b[j])<=1)
      {
         cerr << a[i] << " " << b[j] << "\n";
         i++;
         j++;
         res++;      
      }
   }
   printf("%d\n", res);
         
}