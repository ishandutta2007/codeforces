#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long n,a[200005],i,b[200005],c=-1e9;
    cin>>n;
    for(i=0;i<n;++i)
    {cin>>a[i];
    b[i]=1e9;}
    for(i=0;i<n;++i)
    {
        if(a[i]==0) c=i;
        b[i]=min(b[i],i-c);
    }
    c=1e9;
    for(i=n-1;i>=0;--i)
    {
        if(a[i]==0) c=i;
        b[i]=min(b[i],c-i);
    }
    for(i=0;i<n;++i)
    cout<<b[i]<<" ";
    return 0;
}