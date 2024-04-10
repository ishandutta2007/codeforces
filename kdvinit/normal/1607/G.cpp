/*
K.D. Vinit  /,,/
Dont stalk my code : )
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+1], b[n+1], aa[n+1], bb[n+1];
    for(int i=1; i<=n; i++) cin>>a[i]>>b[i];

    int del=0;
    for(int i=1; i<=n; i++) del+=(b[i]-a[i]);

    for(int i=1; i<=n; i++) { aa[i]=a[i]; bb[i]=b[i]; }

    int pos=0;
    int tmp[n+1];
    for(int i=1; i<=n; i++)
    {
        int ma = min(a[i], m);
        int lb = m - ma;
        del+=(ma-lb);
        aa[i] -= ma;
        bb[i] -= lb;

        tmp[i] = min(ma, b[i]-lb);
        pos += (2*tmp[i]);
    }

    int mb;

    if(del<=0 || pos<=0)
    {
        mb = abs(del);
        cout<<mb<<endl;
        for(int i=1; i<=n; i++) cout<<a[i]-aa[i]<<" "<<b[i]-bb[i]<<endl;
        return;
    }

    mb = (del - pos);
    if(mb<0) mb = mb%2;

    cout<<abs(mb)<<endl;
    del/=2;

    for(int i=1; i<=n; i++)
    {
        int x = min(del, tmp[i]);
        del-=x;
        aa[i]+=x;
        bb[i]-=x;
    }

    for(int i=1; i<=n; i++) cout<<a[i]-aa[i]<<" "<<b[i]-bb[i]<<endl;
    cout<<endl;
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}