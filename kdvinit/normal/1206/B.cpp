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

    int x,ans=0,cntp=0,cntn=0,cntz=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x>=1) { ans+=(x-1); cntp++; }
        else if(x<=-1) { ans+=(-1-x); cntn++; }
        else { ans++; cntz++; }
    }

    if(cntz==0 && cntn%2==1) ans+=2;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}