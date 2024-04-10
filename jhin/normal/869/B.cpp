#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x,y,a,b,c=1;cin>>x>>y;
    if(y-x>=10)cout<<0;
    else if(y==x)cout<<1;
    else
    {c=(x+1)%10;
      for(long long i=x+2;i<=y;i++)
      {
          b=(i)%10;
          c=(c*b)%10;
      }
      cout<<c;
    }

    return 0;
}