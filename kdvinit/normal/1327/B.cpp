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

    vector<int> d, s;
    int vis[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        int k, mar=0;
        vector<int> opt;
        cin>>k;
        while(k--) { int x; cin>>x; opt.push_back(x); }
        for(int x: opt)
        {
            if(vis[x]) continue;
            vis[x]=1; mar=1; break;
        }
        if(!mar) d.push_back(i);
    }
    for(int i=1; i<=n; i++) if(!vis[i]) s.push_back(i);

    if(d.empty()) cout<<"OPTIMAL"<<endl;
    else
    {
        cout<<"IMPROVE"<<endl;
        cout<<d[0]<<" "<<s[0]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}