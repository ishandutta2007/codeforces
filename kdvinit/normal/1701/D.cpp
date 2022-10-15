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

    int a[n+1];
    int b[n+1];
    for(int i=1; i<=n; i++) cin>>b[i];

    vector<array<int, 2>> strts[n+1];

    vector<int> big;
    for(int i=1; i<=n; i++)
    {
        if(b[i]==0) big.push_back(i);
        else
        {
            int x=b[i];     //(i/a[i]);
            int l=(i/(x+1))+1;
            int r=i/x;

            strts[l].push_back({-r, i});
        }
    }

    int vis[n+1]={0};

    priority_queue<array<int, 2>> pq;
    for(int i=1; i<=n; i++)
    {
        for(auto p: strts[i]) pq.push(p);
        if(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int j=p[1];
            a[j]=i;
            vis[i]=i;
        }
    }

    vector<int> lft;
    for(int i=1; i<=n; i++) if(!vis[i]) lft.push_back(i);

    int m=lft.size();

    for(int i=0; i<m; i++)
    {
        int j = big[i];
        int x = lft[i];
        a[j]=x;
    }

    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}