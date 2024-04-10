#include <bits/stdc++.h>

using namespace std;

int main()
{
   unsigned long long a,b;
   cin>>a>>b;
   unsigned long long v= __gcd(a,b);
   unsigned long long x= a/v,y=b/v;
unsigned long long ans=0;
while(x%2==0)
{
    x/=2;
    ans++;
}

    while(x%3==0)
{
    x/=3;
    ans++;
}
     while(x%5==0)
{
    x/=5;
    ans++;
}
 if(x!=1){cout<<"-1";return 0;}
 while(y%2==0)
{
    y/=2;
    ans++;
}

    while(y%3==0)
{
    y/=3;
    ans++;
}
     while(y%5==0)
{
    y/=5;
    ans++;
}
 if(y!=1){cout<<"-1";return 0;}

 cout<<ans;

       return 0;
}