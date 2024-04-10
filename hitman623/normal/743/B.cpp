#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long n,k;
   cin>>n>>k;
   if(k&1==1) cout<<1;
   else
   {
      while(k!=pow(2,n-1))
        {
            if(k>pow(2,n-1))
                k=pow(2,n)-k;
                  n--;
        }
        cout<<n;
   }
    return 0;
}