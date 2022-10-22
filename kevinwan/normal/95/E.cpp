#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=1e5+10;
bool vis[mn];
vector<int>g[mn];
int num[mn];
int dfs(int x){
    int s=vis[x]=1;
    for(int y:g[x])if(!vis[y])s+=dfs(y);
    return s;
}
int dp[mn];
deque<pii>q[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(!vis[i])num[dfs(i)]++;
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)if(num[i]){
        for(int j=0;j<i;j++)q[j].push_back({dp[j],0});
        for(int j=i;j<=n;j++){
            int d=j/i,m=j%i;
            while(q[m].front().second<d-num[i])q[m].pop_front();
            int pro=q[m].front().first-q[m].front().second+d;
            while(q[m].size()&&dp[j]-d<=q[m].back().first-q[m].back().second)q[m].pop_back();
            q[m].push_back({dp[j],d});
            dp[j]=min(dp[j],pro);
        }
        for(int j=0;j<i;j++)q[j].clear();
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        bool val=1;
        for(int j=i;j;j/=10)val&=(j%10==4||j%10==7);
        if(val)ans=min(ans,dp[i]);
    }
    printf("%d",ans==0x3f3f3f3f?-1:(ans-1));
}