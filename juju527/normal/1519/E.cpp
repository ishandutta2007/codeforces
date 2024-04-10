#include<bits/stdc++.h>
#define double long double
#define ll long long
using namespace std;
const int maxn=2e5+5;
const double eps=1e-10;
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
struct num{
    ll b,a;
    num unit(){
        ll g=gcd(a,b);
        return (num){b/g,a/g};
    }
    bool operator <(num i)const{
        double x=1.0*b/a,y=1.0*i.b/i.a;
        if(fabs(x-y)>eps)return x-y<eps;
        ll g1=gcd(a,i.a),g2=gcd(b,i.b);
        return b/g2*(i.a/g1)<i.b/g2*(a/g1);
    }
};
struct node{
    int id;
    num data;
    bool operator <(node i)const{
        return data<i.data;
    }
}A[2*maxn];
int p[maxn],q[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct Edge{
    int to,w,nxt;
}e[2*maxn];
int cnt;
int head[2*maxn];
void add(int u,int v,int w){
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
    return ;
}
bool vis[2*maxn];
int dep[2*maxn];
struct ans{int x,y;};
vector<ans>res;
int dfs(int x,int fa){
    vis[x]=1;
    dep[x]=dep[fa]+1;
    int son=0,ed=-1;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to,id=-1;
        if(tmp==fa)continue;
        if(!vis[tmp])id=dfs(tmp,x);
        if(vis[tmp]&&dep[tmp]<dep[x])continue;
        if(id!=-1)res.push_back((ans){e[i].w,id});
        else{
            if(son&1)res.push_back((ans){e[i].w,ed});
            son++;ed=e[i].w;
        }
    }
    return (son&1)?ed:-1;
}
int main(){
    int n,s,t;
    n=read();
    s=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        ll a,b,c,d;
        a=read();b=read();c=read();d=read();
        A[i]=(node){i,(num){1ll*b*c,1ll*d*(a+b)}.unit()};
        A[i+n]=(node){-i,(num){1ll*b*(c+d),1ll*d*a}.unit()};
    }
    sort(A+1,A+2*n+1);
    int w=0;
    A[0].data=(num){0,1};
    for(int i=1;i<=2*n;i++){
        if(A[i-1].data<A[i].data)w++;
        if(A[i].id>0)p[A[i].id]=w;
        else q[-A[i].id]=w;
    }
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)add(p[i],q[i],i),add(q[i],p[i],i);
//    for(int i=1;i<=n;i++)printf("%d %d\n",p[i],q[i]);
    for(int i=1;i<=w;i++)if(!vis[i])dfs(i,0);
    printf("%d\n",res.size());
    for(int i=0;i<res.size();i++)printf("%d %d\n",res[i].x,res[i].y);
    return 0;
}