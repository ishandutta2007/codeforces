#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=5e3+10;
const ll mod=1e9+7;

int dp[mn][mn];
int main(){
#ifdef LOCAL
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    s=" "+s,t=" "+t;
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){
        if(i&&j&&s[i]==t[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
        if(i)dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
        if(j)dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
    }
    int ans=0;
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)ans=max(ans,dp[i][j]);
    printf("%d\n",ans);
}