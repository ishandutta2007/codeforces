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

    int Xor[n+m+1]={0};

    int x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>x;
            Xor[i+j]^=x;
        }
    }

    bool flag=1;
    for(int i=1;i<=n+m;i++)
    {
        if(Xor[i]!=0) flag=0;
    }

    if(flag==1) cout<<"Jeel"<<endl;
    else cout<<"Ashish"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}