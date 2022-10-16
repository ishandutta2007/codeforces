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

    int strt0[n];
    if(s[0]=='0') strt0[0]=1;
    else strt0[0]=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='0') strt0[i]=strt0[i-1]+1;
        else strt0[i]=strt0[i-1];
    }

    int lst1[n];
    if(s[n-1]=='1') lst1[n-1]=1;
    else lst1[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]=='1') lst1[i]=lst1[i+1]+1;
        else lst1[i]=lst1[i+1];
    }

    /*
    for(int i=0;i<n;i++) cout<<strt0[i]<<" ";
    cout<<endl;

    for(int i=0;i<n;i++) cout<<lst1[i]<<" ";
    cout<<endl;
    */

    int mx=0,tmp;
    for(int i=n-1;i>=0;i--)
    {
        tmp=strt0[i]+lst1[i];
        if(s[i]=='1' && tmp>mx) s[i]='0';
        mx=max(mx,tmp);
    }

    cout<<s<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}