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
    int n,k;
    cin>>n>>k;
    k--;
    int m=n/2;
    m-=k;

    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        if(x=='(') a[i]=0;
        else a[i]=1;
    }

    int cnt=0;
    while(k--)
    {
        b[++cnt]=0;
        b[++cnt]=1;
    }

    for(int i=cnt+1;i<=cnt+m;i++) b[i]=0;
    for(int i=cnt+m+1;i<=n;i++) b[i]=1;

    cnt=0;
    int ans1[n+1],ans2[n+1];

    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i]) continue;

        int j;
        for(j=i;j<=n;j++)
        {
            if(a[j]==b[i]) break;
        }

        ans1[++cnt]=i;
        ans2[cnt]=j;

        for(int k=i;k<=(i+j)/2;k++)
        {
            swap(a[k],a[j+i-k]);
        }

    }

    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++) cout<<ans1[i]<<" "<<ans2[i]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}