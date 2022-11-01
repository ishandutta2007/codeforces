#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

long long n,m,k,p,ans[10000],a[200000],b[200000];

long long bs(long long i,long long x)
{
    long long l=0,r=m-1;
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(mid*b[i]+a[i]>=x)
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

bool check(long long f)
{
   // cout<<f<<endl;
    long long t=0;
    memset(ans,0,sizeof ans);
    for(int i=0;i<n;i++)
    {
     //   cout<<i<<" "<<t<<endl;
        if(f<b[i])
            return false;
        long long x=f-b[i];
        long long y=(m-1)*b[i]+a[i];
        if(y<=x)
            continue;
        y-=x;
        t+=(y+p-1)/p;
        if(t>m*k)
            return false;
        if(y%p)
            ans[bs(i,y%p)]++;
        for(int j=1;j<=y/p;j++)
            ans[(bs(i,j*p+y%p))]++;
    }
    t=0;
    for(int i=m-1;i>-1;i--)
    {
        t+=ans[i];
        if(t>(m-i)*k)
            return false;
    }
    return true;
}

int main()
{
    cin>>n>>m>>k>>p;
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    long long l=0,r=10000000000000;
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l<<endl;
}