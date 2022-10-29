#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long long n,a[1000005]={0},i,x,j,m=0,ans=0,c,po[1000005],h=1e9+7,f[1000005]={0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    po[0]=1;
    for(i=1;i<=1e6;++i)
    po[i]=(po[i-1]*2)%h;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x;
        a[x]++;
        m=max(m,x);
    }
    for(i=1;i<=m;++i)
    {
        c=0;
        for(j=i;j<=m;j+=i)
        c+=a[j];
        f[i]=(c*po[c-1])%h;
    }
    for(i=m;i>=1;i--)
    {
        for(j=2*i;j<=m;j+=i)
        f[i]=(f[i]-f[j]+h)%h;
    }
    for(i=2;i<=m;++i)
    ans=(ans+i*f[i])%h;
    cout<<ans;
    return 0;
}