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

    int a[n+1],p[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int mx_gap[n+1]={0};
    int lst_pos[n+1]={0};

    for(int i=1;i<=n;i++)
    {
        int x=i-lst_pos[a[i]];
        mx_gap[a[i]]=max(mx_gap[a[i]],x);
        lst_pos[a[i]]=i;
    }

    for(int i=1;i<=n;i++)
    {
        int x=n+1-lst_pos[i];
        mx_gap[i]=max(mx_gap[i],x);
    }

    int cnt=n;
    for(int i=1;i<=n;i++)
    {
        while(mx_gap[i]<=cnt) p[cnt--]=i;
    }

    while(cnt>0) p[cnt--]=-1;

    for(int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}