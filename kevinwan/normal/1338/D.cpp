#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=998244353;
const int mn=1e5+10;
vector<int>g[mn];
int dp[mn][2];
int ans;
void dfs(int x,int p){
    dp[x][0]=1;
    vector<pii>zero,one;
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        dp[x][0]=max(dp[x][0],dp[y][1]+1);
        dp[x][1]=max(dp[x][1],max(dp[y][0]+(int)g[x].size()-(p!=0)-1,dp[y][1]+(int)g[x].size()-(p!=0)-1));
        zero.push_back({dp[y][0],y});
        one.push_back({dp[y][1],y});
    }
    sort(zero.begin(),zero.end(),greater<pii>());
    sort(one.begin(),one.end(),greater<pii>());
    ans=max(ans,max(dp[x][0],dp[x][1]));
    if(one.size()<2)return;
    ans=max(ans,one[0].first+one[1].first+1);
    ans=max(ans,one[0].first+one[1].first+(int)g[x].size()-2);
    ans=max(ans,zero[0].first+zero[1].first+(int)g[x].size()-2);
    if(zero[0].second!=one[0].second){
        ans=max(ans,zero[0].first+one[0].first+(int)g[x].size()-2);
    }
    else{
        ans=max(ans,zero[0].first+one[1].first+(int)g[x].size()-2);
        ans=max(ans,zero[1].first+one[0].first+(int)g[x].size()-2);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(g[i].size()>=2){
        dfs(i,0);
        printf("%d",ans);
        return 0;
    }
}