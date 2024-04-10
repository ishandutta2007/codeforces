/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 998244353;

const int N = 3e5 + 10;
int out[N]={0}, in[N]={0}, nxt[N], dp[N], mp[N];

void solve()
{
    int n, m, k;
    cin>>n>>m>>k;

    for(int i=0; i<=k; i++) in[i]=0, out[i]=0, mp[i]=0;

    for(int i=1; i<=n; i++)
    {
        int c; cin>>c;
        int lst; cin>>lst;

        for(int j=2; j<=c; j++)
        {
            int cur; cin>>cur;
            if(out[lst]==1 && nxt[lst]==cur) { lst=cur; continue; }
            out[lst]++;
            nxt[lst]=cur;
            in[cur]++;
            lst = cur;
        }
    }

    vector<int> len;

    for(int i=1; i<=k; i++)
    {
        if(in[i]!=0) continue;
        int cl=1, pos=1, cur=i;
        while(1)
        {
            if(out[cur]>1 || in[cur]>1) { pos=0; break; }
            if(out[cur]==0) break;
            cur = nxt[cur];
            cl++;
        }
        if(pos==0) continue;
        if(mp[cl]==0) len.push_back(cl);
        mp[cl]++;
    }
    
    sort(len.begin(), len.end());

    dp[0]=1;
    for(int i=1; i<=m; i++)
    {
        dp[i]=0;
        for(int x: len)
        {
            int j = i-x;
            if(j<0) break;
            dp[i] += ((dp[j]*mp[x])%mod);
            dp[i] %= mod;
        }
    }

    cout<<dp[m]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}