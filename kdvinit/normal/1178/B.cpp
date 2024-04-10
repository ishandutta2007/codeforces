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

    int n=s.size();
    int a[n],b[n],cnt=0,add=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='o') { a[i]=add; cnt=0; }
        else
        {
            if(cnt==0) { cnt=1; continue; }
            add++;
        }
    }

    cnt=0; add=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='o') { b[i]=add; cnt=0; }
        else
        {
            if(cnt==0) { cnt=1; continue; }
            add++;
        }
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='o') ans+=(a[i]*b[i]);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}