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

    int a[n+1];

    for(int i=2;i<=n;i++)
    {
        cout<<"XOR "<<1<<" "<<i<<endl;
        cin>>a[i];
    }

    int x,y,z;
    cout<<"AND "<<1<<" "<<2<<endl;
    cin>>x;
    cout<<"AND "<<2<<" "<<3<<endl;
    cin>>y;
    cout<<"AND "<<1<<" "<<3<<endl;
    cin>>z;

    x*=2; x+=a[2];
    y*=2; y+=(a[2]^a[3]);
    z*=2; z+=a[3];

    a[1]=(x+z-y)/2;
    for(int i=2;i<=n;i++) a[i]=a[i]^a[1];

    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}