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

    int m=n/2;

    if(n%2==0)
    {
        m++;
        m*=m;
        cout<<m<<endl;
    }
    else
    {
        int ans=2*(m+1)*(m+2);
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}