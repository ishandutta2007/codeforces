/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int M = 1e4+10;
int s[12][M];
int xp[12];
int ans_per[M];

int n, m;
int cur;

void eval(int bt)
{
    int par[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        par[i]=bt%2;
        bt/=2;
    }

    int scr[m+1]={0};

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i][j]==0) continue;
            if(par[i]==1) scr[j]++;
            else scr[j]--;
        }
    }

    vector<pair<int, int>> sp;
    for(int i=1; i<=m; i++) sp.push_back({scr[i], i});
    sort(sp.begin(), sp.end());

    int per[m+1];
    for(int i=0; i<m; i++) per[sp[i].second]=i+1;

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        int res=0;
        for(int j=1; j<=m; j++)
        {
            if(s[i][j]==0) continue;
            res+=per[j];
        }
        ans += abs(res-xp[i]);
    }

    if(ans>cur)
    {
        cur=ans;
        for(int i=1; i<=m; i++) ans_per[i]=per[i];
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>xp[i];
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            s[i][j]=x-'0';
        }
    }

    int mx = 1<<n;

    cur=-1;
    for(int i=0; i<mx; i++) eval(i);

    for(int i=1; i<=m; i++) cout<<ans_per[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}