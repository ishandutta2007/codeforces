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

    char a[n+1][n+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];

    char w,x,y,z;
    w=a[2][1];
    x=a[1][2];
    y=a[n-1][n];
    z=a[n][n-1];

    if(w==x)
    {
        int cnt=0;
        if(y==w) cnt++;
        if(z==w) cnt++;
        cout<<cnt<<endl;
        if(y==w) cout<<n-1<<" "<<n<<endl;
        if(z==w) cout<<n<<" "<<n-1<<endl;
        return;
    }
    if(y==z)
    {
        int cnt=0;
        if(w==y) cnt++;
        if(x==y) cnt++;
        cout<<cnt<<endl;
        if(w==y) cout<<2<<" "<<1<<endl;
        if(x==y) cout<<1<<" "<<2<<endl;
        return;
    }
    cout<<2<<endl;
    cout<<2<<" "<<1<<endl;
    if(y==x) cout<<n-1<<" "<<n<<endl;
    if(z==x) cout<<n<<" "<<n-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}