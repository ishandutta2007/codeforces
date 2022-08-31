#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i ++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
int a[105],b[105];
pii c[105];
int dp[101][101][10001];
int main()
{
    int n,k;
    sd(n);
    int V = 0;
    rep(i,1,n+1)
    sd(a[i]);
    rep(i,1,n+1)
    sd(b[i]),V+=a[i];
    int ans1 = n,ans2 = 0;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            for(int k = 1;k<=i*100;k++){
                dp[i][j][k] = dp[i-1][j][k];
                if(j==1)
                {
                    int l = (k==b[i]?a[i]:0);
                    dp[i][j][k] = max(l,dp[i-1][j][k]);
                }
                else{
                if(k - b[i] >= 0 && dp[i-1][j-1][k-b[i]] > 0)
                    dp[i][j][k] = max(dp[i][j][k],a[i]+dp[i-1][j-1][k-b[i]]);
                }   
                    
                if(k >= V && j <= ans1 && dp[i][j][k]>0)
                {   
                    if(j<ans1 || V-dp[i][j][k] <ans2)
                    ans2 =  V - dp[i][j][k];
                    ans1 = j;
                    
                }
            }
    cout<<ans1<<" "<<ans2;        
}