/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int k; cin>>k;
    int b[k+1];
    for(int i=1; i<=k; i++) cin>>b[i];

    int ca[n+1];
    for(int i=1; i<=n; i++)
    {
        ca[i]=1;
        while(a[i]%m==0) { a[i]/=m; ca[i]*=m; }
    }

    int cb[k+1];
    for(int i=1; i<=k; i++)
    {
        cb[i]=1;
        while(b[i]%m==0) { b[i]/=m; cb[i]*=m; }
    }

    int i=1, j=1;

    while(1)
    {
        if(i>n && j>k) { cout<<"Yes"<<endl; return; }
        if(i>n || j>k) { cout<<"No"<<endl; return; }

        if(a[i]!=b[j]) { cout<<"No"<<endl; return; }

        int x = min(ca[i], cb[j]);
        ca[i]-=x;
        cb[j]-=x;

        if(ca[i]==0) i++;
        if(cb[j]==0) j++;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}