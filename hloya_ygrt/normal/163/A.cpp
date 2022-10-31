#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define f first
#define fast_io ios_base::sync_with_stdio(0)
#define s second
#define pb push_back
#define ll long long

    const int maxn = 5e3+3, base  = 1e9+7;
    int dp[maxn][maxn];
int main()
{
    fast_io;
    string s,t;
    cin>>s>>t;
    int n = s.size(), m = t.size();

    memset(dp,0,sizeof(dp));

    for (int posx = n-1;posx>=0;posx--)
        for (int posy = m-1;posy>=0;posy--){
            dp[posx][posy] = dp[posx][posy+1];
            if (s[posx] == t[posy])
            {
                dp[posx][posy]  += dp[posx + 1][posy + 1] +1;
                dp[posx][posy]%=base;
            }
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        ans += dp[i][0];
        ans%=base;
    }
    cout<<ans;
    return 0;
}