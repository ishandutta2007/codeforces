#include "bits/stdc++.h"

using namespace std;

int tab[3007];

int main()
{
   int n;
   scanf("%d", &n);
   printf("%d\n", n);
   for(int i=0; i<n; i++)
      scanf("%d", tab+i);
   for(int i=0; i<n; i++)
   {
      int id = i;
      for(int j=i+1; j<n; j++)
         if(tab[id]>tab[j])
            id = j;
      swap(tab[id], tab[i]);
      printf("%d %d\n", i, id);
    }
    return 0;  
}