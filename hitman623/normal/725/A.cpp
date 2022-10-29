#include <iostream>

using namespace std;

int main()
{
    long n,i,m=0,f=0;
    cin>>n;
    char a[200000];
    cin>>a;
    if(a[0]=='<')
    {   m++;
        for(i=1;i<n;++i)
        if(a[i]==a[i-1])
          ++m;
          else {f=i; break;}
    }
     if(a[n-1]=='>')
     {++m;
      for(i=n-2;i>=f;--i)
            if(a[i]==a[i+1])++m;
             else break;}
             cout<<m;
   return 0;
}