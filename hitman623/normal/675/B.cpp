#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,a,b,c,d,ans=0,mns,mxs,i;
    cin>>n>>a>>b>>c>>d;
    for(i=1;i<=n;++i)
    {
        mxs=n+a+b+i;
        mns=1+a+b+i;
        if(mxs-a-i-c>n) mxs=n+a+c+i;
        if(mxs-i-c-d>n) mxs=n+c+d+i;
        if(mxs-i-b-d>n) mxs=n+b+d+i;
        if(mns-a-i-c<1) mns=1+a+c+i;
        if(mns-i-c-d<1) mns=1+c+d+i;
        if(mns-i-b-d<1) mns=1+b+d+i;
        if(mxs>=mns)
        ans+=(mxs-mns)+1;
    }
    cout<<ans;
    return 0;
}