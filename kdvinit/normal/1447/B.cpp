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
    int n,m;
    cin>>n>>m;

    int x,mn=1000,sum=0,neg=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>x;
            if(x<0) neg++;
            x=abs(x);
            sum+=x;
            mn=min(mn,x);
        }
    }
    mn*=2;
    if(neg%2==1) sum-=mn;
    cout<<sum<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}