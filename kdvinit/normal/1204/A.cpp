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
    string s;
    cin>>s;

    if(s[0]==0) { cout<<0<<endl; return; }

    int n=s.size(),m;

    int flag=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='1') flag=1;
    }

    m=(n+1)/2;
    if(n%2==1 && flag==0) m--;

    cout<<m<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}