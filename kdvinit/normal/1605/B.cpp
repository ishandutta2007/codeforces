/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1], cnt0=0;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i]=x-'0';
        if(a[i]==0) cnt0++;
    }

    vector<int> ans;
    for(int i=1; i<=n; i++)
    {
        if(i<=cnt0 && a[i]==1) ans.push_back(i);
        if(i>cnt0 && a[i]==0) ans.push_back(i);
    }

    if(ans.size()==0) { cout<<0<<endl; return; }

    cout<<1<<endl;
    cout<<ans.size()<<" ";
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}