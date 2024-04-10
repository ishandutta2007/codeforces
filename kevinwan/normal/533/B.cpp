#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
vector<int>g[mn];
ll v[mn],dp[mn][2];
void dfs(int x){
    dp[x][1]=-inf;
    for(int y:g[x]){
        dfs(y);
        ll a=max(dp[x][0]+dp[y][0],dp[x][1]+dp[y][1]),b=max(dp[x][0]+dp[y][1],dp[x][1]+dp[y][0]);
        dp[x][0]=a,dp[x][1]=b;
    }
    dp[x][1]=max(dp[x][1],dp[x][0]+v[x]);
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int p;
        cin>>p>>v[i];
        if(i>1)g[p].push_back(i);
    }
    dfs(1);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
}