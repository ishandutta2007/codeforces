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

    int r[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin>>r[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    int x=0,y=0;
    for(int i=1;i<=n;i++)
    {
        if(r[i]==1 && b[i]==0) x++;
        if(r[i]==0 && b[i]==1) y++;
    }

    if(x==0) cout<<-1<<endl;
    else
    {
        int z=(y/x)+1;
        cout<<z<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}