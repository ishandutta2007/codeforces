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

    if(n%2==0) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;

    int a[2*n+1];
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            a[i]=(2*i-1);
            a[i+n]=(2*i);
        }
        else
        {
            a[i]=(2*i);
            a[i+n]=(2*i-1);
        }
    }

    for(int i=1;i<=2*n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}