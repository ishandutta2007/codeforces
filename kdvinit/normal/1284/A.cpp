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

    string s[n+1],t[m+1];
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=m;i++) cin>>t[i];

    int q; cin>>q;
    while(q--)
    {
        int y; cin>>y;

        y%=(n*m);

        int a1,a2;

        a1=y%n;
        if(a1==0) a1=n;

        a2=y%m;
        if(a2==0) a2=m;

        cout<<s[a1]<<t[a2]<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}