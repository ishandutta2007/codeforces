#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        vector<int>a(n);
        for(int i=0;i<n;++i) a[i]=s[i]-'0';
        vector<vector<vector<pair<int,int>>>>dp(n,vector<vector<pair<int,int>>>(2,vector<pair<int,int>>(2,make_pair(n*10,n*10))));
        dp[0][a[0]][1]={0,1};
        dp[0][a[0]^1][1]={1,1};
        for(int i=0;i<n-1;++i)
            for(int j=0;j<=1;++j)
            for(int k=0;k<=1;++k)
            {
                for(int h=0;h<=1;++h)
                {
                    if(k&&h!=j) continue;
                    auto x=dp[i][j][k];
                    x.first+=(h!=a[i+1]);
                    x.second+=h!=j;
                    if(h==j) dp[i+1][h][k^1]=min(dp[i+1][h][k^1],x);
                    else dp[i+1][h][1]=min(dp[i+1][h][1],x);
                }
            }
        auto ans=min(dp[n-1][0][0],dp[n-1][1][0]);
        cout<<ans.first<<' '<<ans.second<<'\n';
    }
}