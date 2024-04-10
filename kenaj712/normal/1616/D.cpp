#include<bits/stdc++.h>
using namespace std;
#define int long long
int tab[1000005];
int dp[1000005][2];
int dp_war[1000005][2];
void solve()
{
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    int b;
    cin>>b;
    for(int x=1;x<=a;x++)
        tab[x] -= b;
    for(int x=1;x<=a;x++)
    {
        dp[x][0] = max(dp[x-1][0], dp[x-1][1]);
        dp[x][1] = dp[x-1][0] + 1;
        dp_war[x][1] = tab[x];
        if(dp_war[x-1][1] + tab[x] >= 0 && ((dp[x][1] < dp[x-1][1] + 1) || (dp[x][1] == dp[x-1][1] + 1 && dp_war[x-1][1] > 0)))
        {
            dp[x][1] = dp[x-1][1] + 1;
            dp_war[x][1] = tab[x] + dp_war[x-1][1];
        }
        if(tab[x] < dp_war[x][1])
            dp_war[x][1] = tab[x];
    }
    cout<<max(dp[a][0], dp[a][1])<<'\n';
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}