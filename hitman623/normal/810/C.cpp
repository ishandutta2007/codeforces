#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long long n,x[300005],i,p[300005],ans=1,temp=0,h=1e9+7,t,tt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    p[0]=1;
    cin>>n;
    for(i=1;i<=n;++i)
    p[i]=(p[i-1]*2)%h;
    for(i=0;i<n;i++)
    cin>>x[i];
    sort(x,x+n);
    for(i=0;i<n-1;++i)
    {
        ans=1;
        t=(p[n-1-i]-1+h)%h;
        tt=(p[i+1]-1+h)%h;
        ans=(ans*t)%h;
        ans=(ans*tt)%h;
        ans=(ans*(x[i+1]-x[i]))%h;
        temp+=ans;
        temp%=h;
    }
    cout<<temp;
    return 0;
}