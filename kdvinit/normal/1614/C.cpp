/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin>>n>>m;

    int lrx[m+1][3];
    for(int i=1; i<=m; i++) cin>>lrx[i][0]>>lrx[i][1]>>lrx[i][2];

    int ans=0, mul=1;
    for(int i=1; i<=31; i++)
    {
        int pre[n+2]={0};
        for(int j=1; j<=m; j++)
        {
            int pos =  lrx[j][2]%2;
            lrx[j][2]/=2;
            if(pos==0) { pre[lrx[j][0]]++; pre[lrx[j][1]+1]--; }
        }

        int cnt[2]={0};
        cnt[0]=1;
        for(int j=1; j<=n; j++)
        {
            pre[j]+=pre[j-1];
            int sum = (cnt[0]+cnt[1])%mod;
            if(pre[j]==0) { cnt[0]=sum; cnt[1]=sum; }
            else { cnt[0]=(2*cnt[0])%mod; cnt[1]=(2*cnt[1])%mod; }
        }
        ans+=(cnt[1]*mul);  ans%=mod;
        mul*=2; mul%=mod;
    }

    ans%=mod; if(ans<0) ans+=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}