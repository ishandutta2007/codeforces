#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=410,mod=1000000007,inv2=500000004;
struct edge{
    int next,to;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y){
    e[++len]={head[x],y};
    head[x]=len;
}
int i,j,k,n,m,F[maxn][21],deep[maxn],size[maxn],SIZE[maxn],w[maxn],dis[maxn][maxn];
long long dp[maxn][maxn],S[maxn],jc[maxn],ny[maxn];
ll ksm(ll sum,int num){
    ll ans=1;
    while(num){
        if(num&1)ans=ans*sum%mod;
        sum=sum*sum%mod;
        num>>=1;
    }return ans;
}
void dfs(int now,int fa){
    F[now][0]=fa;deep[now]=deep[fa]+1;size[now]=1;
    for(int i=head[now];i;i=e[i].next){
        int u=e[i].to;
        if(u==fa)continue;
        dfs(u,now);
        size[now]+=size[u];
    }
}
void init(){
    jc[0]=1;for(i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod;
    ny[n]=ksm(jc[n],mod-2);for(i=n-1;i>=0;i--)ny[i]=ny[i+1]*(i+1)%mod;
    for(j=1;j<=20;j++)
        for(i=1;i<=n;i++)
            F[i][j]=F[F[i][j-1]][j-1];
    for(int i=1;i<=n;i++)dp[0][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=(inv2*dp[i-1][j]+inv2*dp[i][j-1])%mod;
}
int jump(int a,int len){
    for(int j=20;j>=0;j--)
        if(len>=(1<<j))len-=(1<<j),a=F[a][j];
    return a;
}
int lca(int a,int b){
    if(deep[a]>deep[b])swap(a,b);
    for(int j=20;j>=0;j--)
        if(deep[a]<=deep[F[b][j]])b=F[b][j];
    if(a==b)return a;
    for(int j=20;j>=0;j--)
        if(F[a][j]!=F[b][j])a=F[a][j],b=F[b][j];
    return F[a][0];
}
void dfs2(int now,int fa){
    S[now]=1;SIZE[now]=1;
    for(int i=head[now];i;i=e[i].next){
        int u=e[i].to;
        if(u==fa)continue;
        dfs2(u,now);
        SIZE[now]+=SIZE[u];
    }S[now]=jc[SIZE[now]-1];
    for(int i=head[now];i;i=e[i].next){
        int u=e[i].to;
        if(u==fa)continue;
        S[now]*=ny[SIZE[u]];S[now]%=mod;
        S[now]*=S[u];S[now]%=mod;
    }
    //cout<<"DFS2.. S["<<now<<"]="<<S[now]<<' '<<SIZE[now]<<endl;
}
void dfs3(int now,int fa){
    SIZE[now]=w[now];
    for(int i=head[now];i;i=e[i].next){
        int u=e[i].to;
        if(u==fa)continue;
        dfs3(u,now);
        SIZE[now]+=SIZE[u];
        SIZE[now]%=mod;
    }
}
long long ANS=0;
int main(){
    cin>>n;
    for(i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }dfs(1,0);init();
    for(i=1;i<=n;i++){
        memset(S,0,sizeof(S));
        dfs2(i,0);w[i]=S[i];
    }dfs3(1,0);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            int z=lca(i,j);
            dis[i][j]=deep[i]+deep[j]-2*deep[z];
        }
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++){
            long long ans=0;
            for(k=1;k<=n;k++){
                int z=lca(i,j);
                //if(i==k || j==k)continue;
                //cout<<"k="<<k<<' '<<dis[k][i]<<' '<<dis[k][j]<<' '<<dis[i][j]<<' '<<w[k]<<endl;
                if(dis[k][j]+dis[i][j]==dis[k][i])ans+=ksm(n,mod-2);
                else if(dis[k][i]+dis[i][j]==dis[j][k])continue;
                else{
                    int len=dis[i][j],lend=(dis[i][k]+dis[j][k]-dis[i][j])/2;
                    ans+=dp[dis[k][j]-lend][dis[k][i]-lend]%mod*ksm(n,mod-2)%mod;
                }
                ans%=mod;
            }
            //cout<<i<<" "<<j<<" ans="<<ans<<endl;
            ANS+=ans;ANS%=mod;
        }
    cout<<ANS<<endl;
    return 0;
}