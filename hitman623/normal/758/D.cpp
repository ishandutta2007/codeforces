#include <bits/stdc++.h>

using namespace std;
long long calc(char a[],long long f,long long l)
{
    long i;
    long long x=0;
    for(i=f;i<=l;++i)
    {
        x=x*10+(a[i]-'0');
    }
    return x;
}
long long le(long long t)
{
    long i;
    long long x;
    if(!t) return 0;
    for(i=1;i<=10;++i)
    {
        x=(pow(10,i));
        if(t/x==0) return i;
    }
    return 0;
}
int main()
{
    long long n,i,m,t=0,l=0,k;
    long double s=0;
    char a[100];
    cout<<setprecision(100);
    cin>>n>>a;
    m=strlen(a);
    k=le(n);
    for(i=m-1;i>=k-1;--i)
    {
       t=calc(a,i-k+1,i);
       if(t>=n)
       {
           t=calc(a,i-k+2,i);
           s+=t*pow(n,l++);
           i=i-le(t)+1-!t;
          // cout<<t<<endl;
       }
       else
       {
           s+=t*pow(n,l++);
           i=i-le(t)+1-!t;
       }
      // cout<<t<<endl;
    }
    cout<<ceil(calc(a,0,i)*pow(n,l)+s);
    return 0;
}