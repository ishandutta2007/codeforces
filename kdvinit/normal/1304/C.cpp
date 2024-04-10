/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    int l=m,h=m,prv_time=0,x,y,t,d,flag=1;;
    for(int i=1;i<=n;i++)
    {
        cin>>t>>x>>y;
        d=t-prv_time;
        prv_time=t;
        h+=d;
        l-=d;
        h=min(h,y);
        l=max(l,x);
        if(l>h) flag=0;
    }

    if(flag==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}