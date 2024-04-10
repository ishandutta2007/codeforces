#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=2e5+10;
int n,par[maxn];ll ans;
int find(int x){
  return !par[x]?0:par[x]==x?x:par[x]=find(par[x]);
}

#define mid ((l+r)>>1)

int tot,rt[maxn],ls[maxn<<5],rs[maxn<<5],sz[maxn<<5];ll sum[maxn<<5],val[maxn<<5];
void maintain(int k){
  sz[k]=sz[ls[k]]+sz[rs[k]],sum[k]=sum[ls[k]]+sum[rs[k]],val[k]=val[ls[k]]+val[rs[k]]+sum[ls[k]]*sz[rs[k]];
}
void ins(int&k,int l,int r,int x){
  if(!k)k=++tot;
  if(l==r){
    sum[k]=x,sz[k]=1,val[k]=0;
  }else{
    x<=mid?ins(ls[k],l,mid,x):ins(rs[k],mid+1,r,x),maintain(k);
  }
}
int merge(int x,int y){
  if(!x||!y)return x|y;
  ls[x]=merge(ls[x],ls[y]);
  rs[x]=merge(rs[x],rs[y]);
  return maintain(x),x;
}

#undef mid

int main(){
  cin>>n;
  rep(i,1,n){
    int p,v;scanf("%d%d",&p,&v),ans-=1ll*p*v;
    int x=find(p-1)|find(p);
    if(!x)x=par[p]=p;
    ans-=val[rt[x]];
    ins(rt[x],1,n,v);
    ans+=val[rt[x]]+1ll*x*v;
    int tp=x+sz[rt[x]]-1;
    if(tp<=200000){
      par[tp]=x;
      int y=find(tp+1);
      if(y){
        ans-=val[rt[x]]+val[rt[y]]+sum[rt[y]]*(y-x);
        rt[x]=merge(rt[x],rt[y]);
        par[y]=x;
        ans+=val[rt[x]];
      }
    }
    printf("%lld\n",ans);
  }
  return 0;
}