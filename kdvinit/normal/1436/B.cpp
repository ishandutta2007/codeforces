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
    int n;
    cin>>n;

    int prime[201]={0};
    for(int i=2;i<=200;i++)
    {
        prime[i]=1;
        for(int j=2;j<i;j++)
        {
            if(i%j==0) prime[i]=0;
        }
    }

    int x;
    for(int i=n;i<=200;i++)
    {
        if(prime[i]==1 && prime[i-n+1]==0)
        {
            x=i-n+1;
            break;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) cout<<x<<" ";
            else cout<<1<<" ";
        }
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}