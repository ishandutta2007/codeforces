#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int k=n/3;
   k*=2;
   if(n%3)k++;
   cout<<k;
   return 0;
}