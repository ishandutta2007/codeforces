#include "bits/stdc++.h"

using namespace std;

int main()
{
   int m, s;
   scanf("%d%d", &m, &s);
   if(s==0)
   {
      if(m==1)
         puts("0 0");
      else
         puts("-1 -1");
      return 0;
   }
   if(s>9*m)
   {
      puts("-1 -1");
      return 0;   
   }
   vector <int> A = {1}, B;
   for(int i=1; i<m; i++)
      A.push_back(0);
   for(int i=0; i<m; i++)
      B.push_back(9);
   int sumaA = 1, sumaB = 9*m;
   for(int i=m-1; sumaA<s && i>=0; i--)
   {
      A[i] += min(9,s-sumaA);
      sumaA += min(9,s-sumaA);
   }
   for(int i=m-1; sumaB>s && i>=0; i--)
   {
      B[i] -= min(9,sumaB-s);
      sumaB -= min(9,sumaB-s);
   }
   for(int i=0; i<m; i++)
      printf("%d", A[i]);
   printf(" ");
   for(int i=0; i<m; i++)
      printf("%d", B[i]);  
}