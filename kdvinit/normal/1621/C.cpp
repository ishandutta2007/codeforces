/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

int qq;
int ask(int i)
{
    cout<<"? "<<i<<endl;
    cin>>qq;
    return qq;
}

void solve()
{
    int n;
    cin>>n;

    int vis[n+1]={0}, p[n+1]={0};

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==1) continue;
        int org = ask(i);
        int cur = org;
        while(1)
        {
            int lst = cur;
            cur = ask(i);
            p[lst]=cur;
            vis[lst]=1;
            if(cur==org) break;
        }
    }

    cout<<"! ";
    for(int i=1; i<=n; i++) cout<<p[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}