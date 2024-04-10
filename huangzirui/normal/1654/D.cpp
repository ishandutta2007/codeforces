#include<bits/stdc++.h>
// #define int long long
#define pii pair<int,int>
#define ll long long
using namespace std;
const int maxn=200010,maxP=18000,mod=998244353;
struct edge{
    int next,to;ll x,y;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y,ll s1,ll s2){
    e[++len]={head[x],y,s1,s2};
    head[x]=len;
}
int i,j,k,n,m,prime[maxn],is_prime[maxn],cnt;
vector<pii>V[maxn];
void init(){
    for(int i=2;i<maxn;i++)is_prime[i]=1;
    for(int i=2;i<maxn;i++){
        if(is_prime[i])prime[++cnt]=i;
        for(int j=1;j<=cnt && prime[j]*i<maxn;j++){
            is_prime[i*prime[j]]=0;
            if(i%prime[j]==0)break;
        }
    }
    for(i=1;i<=cnt;i++)
        for(ll j=prime[i];j<maxn;j+=prime[i]){
            int NUM=0;ll TMP=j;
            while(TMP%prime[i]==0)TMP/=prime[i],++NUM;
            V[j].push_back(make_pair(i,NUM));
        }
}
ll ksm(ll sum,int num){
    ll ans=1;
    while(num){
        if(num&1)ans=ans*sum%mod;
        sum=sum*sum%mod;
        num>>=1;
    }return ans;
}
int Num[maxn],Ans[maxn];
void dfs(int now,int fa){
    // cerr<<"now="<<now<<endl;
    for(int i=head[now];i;i=e[i].next){
        int u=e[i].to;
        if(u==fa)continue;
        for(int j=0;j<V[e[i].y].size();j++)
            Num[V[e[i].y][j].first]+=V[e[i].y][j].second;
        for(int j=0;j<V[e[i].x].size();j++){
            Num[V[e[i].x][j].first]-=V[e[i].x][j].second;
            if(Num[V[e[i].x][j].first]<0){
                // cerr<<"ADD "<<V[e[i].x][j].first<<' '<<(-Num[V[e[i].x][j].first])<<endl;
                Ans[V[e[i].x][j].first]-=Num[V[e[i].x][j].first];
                Num[V[e[i].x][j].first]=0;
            }
        }
        dfs(u,now);
        for(int j=0;j<V[e[i].y].size();j++)
            Num[V[e[i].y][j].first]-=V[e[i].y][j].second;
        for(int j=0;j<V[e[i].x].size();j++)
            Num[V[e[i].x][j].first]+=V[e[i].x][j].second;
    }
}
ll tANS=0;
void dfs2(int now,int fa,ll Sum){
    tANS+=Sum;tANS%=mod;
    for(int i=head[now];i;i=e[i].next){
        int u=e[i].to;
        if(u==fa)continue;
        dfs2(u,now,Sum*e[i].y%mod*ksm(e[i].x,mod-2)%mod);
    }
}
signed main(){
    int T;
    cin>>T;
    init();
    // cerr<<"CNT="<<cnt<<endl;
    while(T--){
        len=0;memset(head,0,sizeof(head));
        cin>>n;tANS=0;
        for(i=1;i<n;i++){
            int x,y;ll a,b;
            scanf("%d%d%lld%lld",&x,&y,&a,&b);
            ll u=__gcd(a,b);a/=u;b/=u;
            add(x,y,a,b);add(y,x,b,a);
        }
        dfs(1,0);
        ll ANS=1;
        for(i=1;i<=cnt;i++){
            ANS*=ksm(prime[i],Ans[i]);
            ANS%=mod;Ans[i]=Num[i]=0;
        }
        // cerr<<"ANS="<<ANS<<endl;
        dfs2(1,0,ANS);
        printf("%lld\n",tANS);
    }
}