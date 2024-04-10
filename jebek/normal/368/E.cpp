#include <iostream>
#include<algorithm>

using namespace std;

long long n,m,q,a[200000],k,ans;

bool check(long long f)
{
    if(f%2==1)
    {
        if(f*(f-1)/2<n)
            return true;
        else
            return false;
    }
    if(f*(f-1)/2+f/2-1<n)
        return true;
    else
        return false;
}

long long bs(long long l,long long r)
{
    while(l<r)
    {
        long long mid=(l+r+1)/2;
        if(check(mid))
            l=mid;
        else
            r=mid-1;
    }
    return l;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>q>>a[i];
    sort(a,a+m);
    k=bs(1,min(n,m));
    for(int i=m-1;i>=m-k;i--)
        ans+=a[i];
    cout<<ans<<endl;
}