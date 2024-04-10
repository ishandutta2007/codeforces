#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
   int r,c,a;
   long long sol;
   scanf("%d %d %d",&r,&c,&a);
   sol=((long long)(r+a-1))/a*((long long)(c+a-1)/a);
   cout << sol << endl;
   return 0;
}