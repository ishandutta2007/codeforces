#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+100;
int c[maxn];
ll dp[maxn][2];
string s[maxn];
string rs[maxn];
#define sd(t) scanf("%d",&(t))

int main()
{
    int n;
    sd(n);
    for(int i = 1;i<=n;i++)
        sd(c[i]);
    for(int i = 1;i<=n;i++){
        cin>>s[i];
        rs[i] = s[i];
        reverse(rs[i].begin(),rs[i].end());    
    }
    dp[1][0] = 0;
    dp[1][1] = c[1];
    for(int i = 2;i<=n;i++)
        dp[i][1] = dp[i][0] = (1LL<<55);
    for(int i = 2;i<=n;i++)
    {
        if(s[i]>=s[i-1])
            dp[i][0] = min(dp[i][0],dp[i-1][0]);
        if(s[i]>=rs[i-1])
            dp[i][0] = min(dp[i][0],dp[i-1][1]);
        if(rs[i]>=s[i-1])
            dp[i][1] = min(dp[i][1],dp[i-1][0]+c[i]);
        if(rs[i]>=rs[i-1])
            dp[i][1] = min(dp[i][1],dp[i-1][1]+c[i]);
    }
    ll ans = min(dp[n][1],dp[n][0]);
    if(ans==(1LL<<55)){
        cout<<-1;
        return 0;
    }
    cout<<ans;
}