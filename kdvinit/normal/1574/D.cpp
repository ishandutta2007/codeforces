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

    vector<int> a[n+1];

    map<int, vector<int>> mp;
    map<vector<int>, bool> vis;

    int cnt=1, tmp=0;
    for(int i=1; i<=n; i++)
    {
        int c; cin>>c;
        mp[1].push_back(c);
        a[i].push_back(-1);
        for(int j=1; j<=c; j++) { int x; cin>>x; a[i].push_back(x); }
        tmp+=a[i][c];
    }

    map<vector<int>, bool> ban;

    int m; cin>>m;
    while(m--)
    {
        vector<int> b(n);
        for(int i=0; i<n; i++) cin>>b[i];
        ban[b]=1;
    }

    vis[mp[1]]=1;
    priority_queue< pair<int, int> > pq;

    pq.push({tmp, 1});

    while(1)
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        int cost = cur.first;
        int ind = cur.second;

        vector<int> b = mp[ind];
        if(!ban[b])
        {
            for(int x: b) cout<<x<<" ";
            cout<<endl;
            return;
        }

        for(int i=0; i<n; i++)
        {
            int j = b[i];
            if(j==1) continue;

            b[i]--;
            if(vis[b]) { b[i]++; continue; }

            vis[b]=1;   mp[++cnt]=b;

            cost+=(a[i+1][j-1]-a[i+1][j]);
            pq.push({cost, cnt});
            cost-=(a[i+1][j-1]-a[i+1][j]);

            b[i]++;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}