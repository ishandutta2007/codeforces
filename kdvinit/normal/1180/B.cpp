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
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        if(a[i]>=0) a[i]=-a[i]-1;
    }

    if(n%2==1)
    {
        int mn=0;
        for(int i=1;i<=n;i++) mn=min(mn,a[i]);
        for(int i=1;i<=n;i++)
        {
            if(a[i]==mn) { a[i]=-a[i]-1; break; }

        }
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}