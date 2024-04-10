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
    int n,q,x,y;
    cin>>n>>q;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int mx=0,ind=0;
    for(int i=1;i<=n;i++) mx=max(mx,a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==mx) { ind=i; break; }
    }

    int ans[2*n][2],cnt=0,b[n+1];
    x=a[1];
    for(int i=2;i<=ind;i++)
    {
        cnt++;
        ans[cnt][0]=x;
        ans[cnt][1]=a[i];
        b[n-ind+i]=min(x,a[i]);
        x=max(x,a[i]);
    }

    for(int i=ind;i<=n;i++)
    {
        b[i-ind+1]=a[i];
    }

    while(q--)
    {
        cin>>x;
        if(x<=cnt)
        {
            cout<<ans[x][0]<<" "<<ans[x][1]<<endl;
        }
        else
        {
            x-=cnt;
            x%=(n-1);
            if(x==0) x=n-1;
            cout<<b[1]<<" "<<b[x+1]<<endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}