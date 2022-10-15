/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n,mod;
    cin>>n>>mod;

    int Factorial[n+1];

    Factorial[0]=1;
    for(int i=1;i<=n;i++) { Factorial[i]=i*Factorial[i-1]; Factorial[i]%=mod; }


    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=(n-i+1);
        tmp*=Factorial[i]; tmp%=mod;
        tmp*=Factorial[n-i]; tmp%=mod;
        tmp*=(n-i+1); tmp%=mod;
        ans+=tmp; ans%=mod;
    }

    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}