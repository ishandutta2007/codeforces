/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int inf = 1e5;

void solve()
{
    string a; cin>>a;
    int n; cin>>n;
    int m=a.size();

    string s[n+1];
    for(int i=1; i<=n; i++) cin>>s[i];

    int dp[m+2];
    for(int i=1; i<=m; i++) dp[i]=inf;
    dp[m+1]=0;

    int w[m+1];
    int nxt[m+1];

    for(int i=m; i>=1; i--)
    {
        for(int j=1; j<=n; j++)
        {
            string b = s[j];
            int l=b.size();
            int nd = i+l-1;

            if(nd>m) continue;

            string chk = a.substr(i-1, l);
            if(chk!=b) continue;

            int cur=inf;
            int cnxt;

            for(int k=1; k<=l; k++)
            {
                int jj=i+k;
                //cur=min(cur, dp[jj]);
                //continue;

                if(cur>dp[jj])
                {
                    cur=dp[jj];
                    cnxt=jj;
                }
            }

            cur++;
            if(dp[i]>=cur)
            {
                dp[i]=cur;
                w[i]=j;
                nxt[i]=cnxt;
            }
        }
    }

    int ans=dp[1];
    if(ans==inf) { cout<<-1<<endl; return; }

    cout<<ans<<endl;

    int i=1;
    while(i<=m)
    {
        cout<<w[i]<<" "<<i<<endl;
        i=nxt[i];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}