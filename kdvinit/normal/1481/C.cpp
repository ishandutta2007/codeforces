/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    int a[n+1],b[n+1],c[m+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=m;i++) cin>>c[i];

    vector<int> need[n+1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i]) continue;
        need[b[i]].push_back(i);
    }

    int some[n+1];
    for(int i=1;i<=n;i++) some[i]=-1;
    
    for(int i=1;i<=n;i++)
    {
        some[b[i]]=i;
    }

    int ans[m+1];
    vector<int> extra;
    for(int i=1;i<=m;i++)
    {
        int x=c[i];
        if(need[x].size()==0)
        {
            if(some[x]==-1) extra.push_back(i);
            else
            {
                ans[i]=some[x];
                while(extra.size()!=0)
                {
                    int y=extra.back();
                    extra.pop_back();
                    ans[y]=some[x];
                }
            }
        }
        else
        {
            int y=need[x].back();
            need[x].pop_back();
            ans[i]=y;

            while(extra.size()!=0)
            {
                int z=extra.back();
                extra.pop_back();
                ans[z]=y;
            }
        }
    }

    if(extra.size()!=0) { cout<<"NO"<<endl; return; }
    for(int i=1;i<=n;i++)
    {
        if(need[i].size()!=0) { cout<<"NO"<<endl; return; }
    }

    cout<<"YES"<<endl;

    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}