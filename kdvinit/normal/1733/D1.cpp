/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, x, y;
    cin>>n>>x>>y;

    int a[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i]=x-'0';
    }

    vector<int> pos;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        int y = x-'0';
        a[i]=(a[i]+y)%2;
        if(a[i]==1) pos.push_back(i);
    }

    int m = pos.size();

    if(m%2==1) { cout<<-1<<endl; return; }

    if(m==0) { cout<<0<<endl; return; }

    int ans = (m/2)*y;

    if(m>2) { cout<<ans<<endl; return; }

    if(pos[0]+1!=pos[1]) { cout<<ans<<endl; return; }

    ans = x;
    if(n>pos[1]+1) ans = min(ans, 2*y);
    if(1<pos[0]-1) ans = min(ans, 2*y);
    if(1<pos[0] && pos[1]<n) ans = min(ans, 3*y);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}