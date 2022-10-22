#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=2e5+10;
vector<int>g[mn];
ll dp[mn][2];
void dfs(int x,int p){
    ll sum=0,dif1=0x3f3f3f3f,dif2=0x3f3f3f3f;
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        sum+=dp[y][0];
        ll dif=dp[y][1]-dp[y][0];
        if(dif<dif1)dif2=dif1,dif1=dif;
        else if(dif<dif2)dif2=dif;
    }
    dp[x][0]=sum+min(1LL,dif1+dif2-1);
    dp[x][1]=sum+min(1LL,dif1);
    dp[x][0]=min(dp[x][0],dp[x][1]);
}
int main(){
    int n,i;
    ll xx,yy;
    scanf("%d%lld%lld",&n,&xx,&yy);
    for(i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(yy<=xx){
        for(i=1;i<=n;i++){
            if(g[i].size()==n-1){
                printf("%lld",xx+yy*(n-2));
                return 0;
            }
        }
        printf("%lld",yy*(n-1));
        return 0;
    }
    dfs(1,0);
    ll num=dp[1][0]-1;
    printf("%lld",num*yy+(n-1-num)*xx);
}