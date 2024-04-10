#include <iostream>

using namespace std;

long long l,r,n,m,k;

bool check(long long x)
{
    long long ans=0;
    for(long long i=1;i<=n;i++)
    {
        long long t=(x-1)/i;
        ans+=min(t,m);
    }
    if(ans<k)
        return true;
    return false;
}

int main()
{
    cin>>n>>m>>k;
    l=1;r=n*m;
    while(l<r)
    {
        long long mid=(l+r+1)/2;
        if(check(mid))
            l=mid;
        else
            r=mid-1;
    }
    cout<<l<<endl;
}