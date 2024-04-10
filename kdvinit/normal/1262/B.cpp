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

    int q[n+1];
    for(int i=1;i<=n;i++) cin>>q[i];

    int a[n+1],done[n+1]={0};
    int mx=0,mn=1;

    for(int i=1;i<=n;i++)
    {
        if(q[i]<mx) { cout<<-1<<endl; return; }
        if(q[i]>mx)
        {
            if(done[q[i]]==1) { cout<<-1<<endl; return; }
            done[q[i]]=1;
            a[i]=q[i];
            mx=q[i];
        }
        else
        {
            while(done[mn]==1) mn++;

            if(mn>mx) { cout<<-1<<endl; return; }
            a[i]=mn;
            done[mn]=1;
        }
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}