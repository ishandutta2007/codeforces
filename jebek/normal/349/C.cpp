#include <iostream>

using namespace std;

long long n,a[100100];

int check(long long k)
{
    long long ans;
    for(int i=0;i<n;i++)
    {
        ans+=k-a[i];
        if(ans>=k)
            return 1;
    }
    return 0;
}

long long binary(long long l,long long r)
{
    //cout<<l<<" "<<r<<endl;
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
        {
           // cout<<"*"<<r<<endl;
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}

int main()
{
    long long MAX=1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        MAX=max(MAX,a[i]);
     //   sum+=a[i];
    }
    cout<<binary(MAX,1000000000*100000000)<<endl;
}