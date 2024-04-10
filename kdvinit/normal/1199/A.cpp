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
    int n,x,y;
    cin>>n>>x>>y;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        int xx=x;
        int yy=y;
        int tempi=i-1;
        int temp=a[i];
        while(xx>0 && tempi>0)
        {
            temp=min(temp,a[tempi]);
            xx--;
            tempi--;
        }

        if(temp!=a[i]) continue;
        tempi=i+1;
        temp=a[i];
        while(yy>0 && tempi<=n)
        {
            temp=min(temp,a[tempi]);
            yy--;
            tempi++;
        }
        if(temp!=a[i]) continue;

        cout<<i<<endl;
        return;
    }

    cout<<"Hi"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}