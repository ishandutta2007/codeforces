/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int infi=1e5;
    int ninfi=(-1)*infi;

    int xu=infi,xd=ninfi,yu=infi,yd=ninfi;
    for(int i=1;i<=n;i++)
    {
        int x,y,a,b,c,d;
        cin>>x>>y>>a>>b>>c>>d;

        if(a==0) xd=max(xd,x);
        if(b==0) yu=min(yu,y);
        if(c==0) xu=min(xu,x);
        if(d==0) yd=max(yd,y);
    }

    if(xu<xd || yu<yd) cout<<0<<endl;
    else
    {
        cout<<1<<" "<<xu<<" "<<yu<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}