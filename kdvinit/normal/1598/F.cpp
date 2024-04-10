/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 4e5 + 10;
int mp[21][N];

void solve()
{
    int n; cin>>n;
    int del[n+1], mxn[n+1];

    for(int i=1; i<=n; i++)
    {
        string s; cin>>s;
        for(int j=0; j<N; j++) mp[i][j]=0;

        int m = s.size(), pre=0;
        mxn[i]=0;
        for(int j=0; j<m; j++)
        {
            if(s[j]=='(') pre++;
            else pre--;
            if(pre<=mxn[i]) mp[i][-pre]++;
            mxn[i] = min(mxn[i], pre);
        }
        del[i]=pre;
    }

    int bmx = 1<<n;
    int dp[bmx];
    for(int i=0; i<bmx; i++) dp[i]=-1;

    dp[0]=0;
    int ans = 0;
    for(int i=0; i<bmx; i++)
    {
        if(dp[i]==-1) continue;
        int bm = i, td = 0;
        vector<int> on, off;
        for(int j=0; j<n; j++)
        {
            if((bm&(1<<j))==0) off.push_back(j+1);
            else on.push_back(j+1);
        }
        for(int j: on) td += del[j];
        for(int j: off)
        {
            int bm2 = bm+(1<<(j-1));
            int cn = td + mxn[j];
            int tmp = dp[i]+mp[j][td];
            ans = max(ans, tmp);
            if(cn<0) continue;
            dp[bm2] = max(dp[bm2], tmp);
        }
    }

    ans = max(ans, dp[bmx-1]);
    if(ans<0) ans=0;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}