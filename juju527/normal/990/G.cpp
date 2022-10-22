#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n,mxv=0;
int a[maxn];
int ed[maxn][2];
vector<int>E[maxn];
int V[maxn];
ll g[maxn],f[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool bj[maxn];
int len;
int pr[maxn],mu[maxn];
void pre(){
    mu[1]=1;
    for(int i=2;i<=mxv;i++){
        if(!bj[i])pr[++len]=i,mu[i]=-1;
        for(int j=1;1ll*i*pr[j]<=mxv&&j<=len;j++){
            bj[i*pr[j]]=1;
            mu[i*pr[j]]=mu[i]*mu[pr[j]];
            if(i%pr[j]==0){mu[i*pr[j]]=0;break;}
        }
    }
    return ;
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int p[maxn],num[maxn];
int find(int x){
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        mxv=max(mxv,a[i]);
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j)continue;
            V[j]++;
            if(j*j!=a[i])V[a[i]/j]++;
        }
    }
    pre();
    for(int i=1;i<n;i++){
        int u,v,g;
        u=read();v=read();
        ed[i][0]=u;ed[i][1]=v;
        g=gcd(a[u],a[v]);
        for(int j=1;j*j<=g;j++){
            if(g%j)continue;
            E[j].push_back(i);
            if(j*j!=g)E[g/j].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)p[i]=i,num[i]=1;
    for(int i=1;i<=mxv;i++){
        ll res=V[i];
        for(int j=0;j<E[i].size();j++){
            int u=find(ed[E[i][j]][0]),v=find(ed[E[i][j]][1]);
            p[u]=v;
            res-=1ll*num[u]*(num[u]+1)/2+1ll*num[v]*(num[v]+1)/2;
            num[v]+=num[u];
            res+=1ll*num[v]*(num[v]+1)/2;
        }
        for(int j=0;j<E[i].size();j++){
            int u=ed[E[i][j]][0],v=ed[E[i][j]][1];
            p[u]=u;num[u]=1;p[v]=v;num[v]=1;
        }
        g[i]=res;
    }
    for(int i=1;i<=mxv;i++){
        ll res=0;
        for(int d=1;d<=mxv/i;d++)
            res+=mu[d]*g[i*d];
        if(res!=0)printf("%d %lld\n",i,res);
    }
    return 0;
}