#include<bits/stdc++.h>
using namespace std;
const int N=1<<17;
const int inf=1<<30;
int n,k;
int id[N],top[N],cnt;
int sz[N],dep[N],dfn[N],Tm,fa[N];
int head[N],nxt[N<<1],to[N<<1],tot;
void dfs(int u,int p){
    sz[u]=1;fa[u]=p;
    for(int e=head[u];~e;e=nxt[e]){
        int v=to[e];
        if(v!=p){
            dep[v]=dep[u]+1;
            dfs(v,u);
            sz[u]+=sz[v];
        }
    }
}
void hld(int u,int p){
    int mx=-1;
    for(int e=head[u];~e;e=nxt[e]){
        int v=to[e];
        if(v!=p){
            if (!~mx||sz[mx]<sz[v])mx=v;
        }
    }
    id[u]=cnt;dfn[u]=Tm++;
    if(!~top[cnt])top[cnt]=u;
    if(~mx)hld(mx,u);
    for(int e=head[u];~e;e=nxt[e]){
        int v=to[e];
        if (v!=p&&v!=mx)++cnt,hld(v,u);
    }
}
void add(int u,int v){
    nxt[tot]=head[u];head[u]=tot;
    to[tot]=v;++tot;
}
#define PII pair<int,int>
#define MP make_pair
struct SegT{
    int mn[N<<1],cnt[N<<1],add[N<<1];
    void ini(){
        memset(mn,0,sizeof mn);
        memset(cnt,0,sizeof cnt);
        for(int i=0;i<n;++i)cnt[i+N]=1;
        for(int i=N-1;i;--i)cnt[i]=cnt[i<<1]+cnt[i<<1|1];
        memset(add,0,sizeof add);
    }
    void pd(int i,int l){
        if(add[i]){
            mn[i]+=add[i];
            if(i<N){
                add[i<<1]+=add[i];
                add[i<<1|1]+=add[i];
            }
            add[i]=0;
        }
    }
    void pu(int i,int l){
        mn[i]=min(mn[i<<1],mn[i<<1|1]);
        cnt[i]=0;
        if(mn[i<<1]==mn[i])cnt[i]+=cnt[i<<1];
        if(mn[i<<1|1]==mn[i])cnt[i]+=cnt[i<<1|1];
    }
    void upd(int i,int a,int b,int l,int r,int v){
        if(l<=a&&b<=r){
            add[i]+=v;
            pd(i,b-a);return;
        }
        pd(i,b-a);
        if(r<=a||b<=l)return;
        upd(i<<1,a,(a+b)>>1,l,r,v);
        upd(i<<1|1,(a+b)>>1,b,l,r,v);
        pu(i,b-a);
    }
    PII Merge(PII x,PII y){
        PII ans;
        ans.first=min(x.first,y.first);
        ans.second=0;
        if(x.first==ans.first)ans.second+=x.second;
        if(y.first==ans.first)ans.second+=y.second;
        return ans;
    }
    PII qry(int i,int a,int b,int l,int r){
        pd(i,b-a);
        if(l<=a&&b<=r)return MP(mn[i],cnt[i]);
        if(r<=a||b<=l)return MP(inf,0);
        PII L=qry(i<<1,a,(a+b)>>1,l,r);
        PII R=qry(i<<1|1,(a+b)>>1,b,l,r);
        PII Ans=Merge(L,R);
        // cerr<<i<<" "<<a<<" "<<b<<" "<<L.first<<" "<<L.second<<" "<<R.first<<" "<<R.second<<" "<<Ans.first<<" "<<Ans.second<<endl;
        return Ans;
    }
    void dbg(){
        for(int i=0;i<n;++i){
            PII p=qry(1,0,N,dfn[i],dfn[i]+1);
            cerr<<"("<<p.first<<","<<p.second<<")"<<endl;
        }
        cerr<<"---"<<endl;
    }
}segt;
void upd(int u,int v,int c){
    while(id[u]!=id[v]){
        if(dep[top[id[u]]]<dep[top[id[v]]])swap(u,v);
        segt.upd(1,0,N,dfn[top[id[u]]],dfn[u]+1,c);
        u=fa[top[id[u]]];
    }
    if(dep[u]>dep[v])swap(u,v);
    segt.upd(1,0,N,dfn[u],dfn[v]+1,c);
}
int qry(int u,int v){
    PII ans=MP(inf,0);
    while(id[u]!=id[v]){
        if(dep[top[id[u]]]<dep[top[id[v]]])swap(u,v);
        ans=segt.Merge(ans,segt.qry(1,0,N,dfn[top[id[u]]],dfn[u]+1));
        u=fa[top[id[u]]];
    }
    if(dep[u]>dep[v])swap(u,v);
    ans=segt.Merge(ans,segt.qry(1,0,N,dfn[u],dfn[v]+1));
    if(!ans.first)return ans.second;
    return 0;
}
int main(){
    memset(head,-1,sizeof head);
    memset(top,-1,sizeof top);
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;++i){
        int u,v;scanf("%d%d",&u,&v);
        --u,--v;add(u,v),add(v,u);
    }
    dfs(0,-1);
    hld(0,-1);
    int ans=1;
    int l=0,r=0,cur=1;
    segt.ini();
    upd(0,0,1);
    while(r+1<n){
        cur+=qry(r,r+1);
        upd(r,r+1,1);upd(r,r,-1);
        ++r;
        while(cur>k){
            upd(l,l+1,-1);upd(l+1,l+1,1);
            cur-=qry(l,l+1);
            ++l;
        }
        ans=max(ans,r-l+1);
        // cerr<<l<<" "<<r<<endl;
        // segt.dbg();
    }
    printf("%d\n",ans);
    return 0;
}