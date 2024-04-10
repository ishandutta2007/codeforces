/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353

int Power(int a,int b)
{
    int result=1;
    a%=mod;
    while(b!=0)
    {
        if(b%2==1) result*=a;
        a*=a;
        a%=mod;
        result%=mod;b/=2;
    }
    return result;
}

int mod_inv(int a)
{
    int result=Power(a,mod-2);
    return result;
}

void solve()
{
    int n;
    cin>>n;

    int inv100=mod_inv(100);
    int p[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        p[i]*=inv100; p[i]%=mod;
    }

    int tmp=1,ans=1;
    for(int i=1;i<n;i++)
    {
        tmp*=p[i]; tmp%=mod;
        ans+=tmp; ans%=mod;
    }
    tmp*=p[n]; tmp%=mod;

    ans*=mod_inv(tmp); ans%=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}