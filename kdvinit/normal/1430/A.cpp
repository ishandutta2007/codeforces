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
    int m=n/3;

    if(n==1 || n==2 || n==4) { cout<<-1<<endl; return; }
    if(n%3==0)
    {
        cout<<m<<" "<<0<<" "<<0<<endl;
    }
    else if(n%3==1)
    {
        cout<<m-2<<" "<<0<<" "<<1<<endl;
    }
    else
    {
        cout<<m-1<<" "<<1<<" "<<0<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}