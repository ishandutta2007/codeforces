#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200010;
struct edge{
    int next,to;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y){
    e[++len]={head[x],y};
    head[x]=len;
}
int i,j,k,n,m,a[maxn],L[maxn],R[maxn],w[maxn],ans;
void dfs(int now,int fa){
    int tSum=0;
    for(int i=head[now];i;i=e[i].next){
        int u=e[i].to;
        if(u==fa)continue;
        dfs(u,now);
        tSum+=w[u];
    }
    if(tSum<L[now]){
        ++ans;
        w[now]=R[now];
    }else w[now]=min(R[now],tSum);
}
signed main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        for(i=1;i<n;i++){
            int x;
            scanf("%lld",&x);
            add(i+1,x);add(x,i+1);
        }
        for(i=1;i<=n;i++)scanf("%lld%lld",&L[i],&R[i]),w[i]=0;
        dfs(1,0);
        printf("%lld\n",ans);
        len=0;for(i=1;i<=n;i++)head[i]=0;
    }
    return 0;
}