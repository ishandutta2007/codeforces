#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=4e5+10;
int n,q,qid[maxn],ans[maxn];char T[maxn];

struct Trie{
  int pos[maxn],ch[maxn][26],now,dfn[maxn],sz[maxn];
  void dfs(int u){
    dfn[u]=++now,sz[u]=1;
    rep(i,0,25){
      int x=ch[u][i];if(x)dfs(x),sz[u]+=sz[x];
    }
  }
}tr;
struct AC{
  vi vec[maxn],E[maxn];vector<pii>vp[maxn];
  int tot,ch[maxn][26],fail[maxn],Q[maxn],now,dfn[maxn],su[maxn],sz[maxn];
  void ins(char*str,int id){
    int cur=0;
    rep(i,1,strlen(str+1)){
      int&x=ch[cur][str[i]-'a'];
      cur=x?x:x=++tot;
    }
    vec[cur].push_back(id);
  }
  void dfs1(int u){
    dfn[u]=++now,sz[u]=1;
    for(int v:E[u])dfs1(v),sz[u]+=sz[v];
  }
  void build(){
    int l=1,r=0;
    rep(i,0,25)if(ch[0][i])Q[++r]=ch[0][i];
    while(l<=r){
      int u=Q[l++];
      rep(i,0,25){
        int&v=ch[u][i],k=ch[fail[u]][i];
        v?fail[v]=k,Q[++r]=v:v=k;
      }
    }
    rep(i,1,tot)E[fail[i]].push_back(i);
    dfs1(0);
  }
}ac;
struct chairman{
  int tot,rt[maxn],ls[maxn*20],rs[maxn*20],su[maxn*20];
  void ins(int&k,int rt,int l,int r,int x){
    su[k=++tot]=su[rt]+1,ls[k]=ls[rt],rs[k]=rs[rt];
    if(l==r)return;int mid=(l+r)>>1;x<=mid?ins(ls[k],ls[rt],l,mid,x):ins(rs[k],rs[rt],mid+1,r,x);
  }
  int query(int k,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr)return su[k];int mid=(l+r)>>1,res=0;
    if(ql<=mid)res=query(ls[k],l,mid,ql,qr);
    if(qr>mid)res+=query(rs[k],mid+1,r,ql,qr);
    return res;
  }
}ct_x,ct_y;

void dfs1(int u,int cur){
  ac.su[cur]++,ac.vp[ac.dfn[cur]].push_back({tr.dfn[u],tr.dfn[u]+tr.sz[u]-1});
  rep(i,0,25){
    int v=tr.ch[u][i];
    if(v)dfs1(v,ac.ch[cur][i]);
  }
}
void dfs2(int u){
  for(int v:ac.E[u]){
    dfs2(v),ac.su[u]+=ac.su[v];
  }
  for(int id:ac.vec[u]){
    ans[id]=ac.su[u];
    int l=ac.dfn[u],r=l+ac.sz[u]-1;
    if(qid[id]>1){
      ans[id]-=ct_y.query(ct_y.rt[r],1,tr.now,1,qid[id]-1)-ct_y.query(ct_y.rt[l-1],1,tr.now,1,qid[id]-1);
    }
    if(qid[id]<tr.now){
      ans[id]-=ct_x.query(ct_x.rt[r],1,tr.now,qid[id]+1,tr.now)-ct_x.query(ct_x.rt[l-1],1,tr.now,qid[id]+1,tr.now);
    }
//    rep(i,l,r){
//      for(pii p:ac.vp[i])ans[id]-=p.second<qid[id]||p.first>qid[id];
//    }
  }
}

void solve(){
  cin>>n;
  rep(i,1,n){
    int op=read(),j=0;char c;
    if(op==2)j=read();
    scanf("%s",&c);
    int&x=tr.ch[tr.pos[j]][c-'a'];
    if(!x)x=i;
    tr.pos[i]=x;
  }
  tr.dfs(0);
  cin>>q;
  rep(i,1,q){
    qid[i]=tr.dfn[tr.pos[read()]],scanf("%s",T+1),ac.ins(T,i);
  }
  ac.build();
  dfs1(0,0);
  rep(i,1,ac.now){
    ct_x.rt[i]=ct_x.rt[i-1],ct_y.rt[i]=ct_y.rt[i-1];
    for(pii p:ac.vp[i]){
      ct_x.ins(ct_x.rt[i],ct_x.rt[i],1,tr.now,p.first);
      ct_y.ins(ct_y.rt[i],ct_y.rt[i],1,tr.now,p.second);
    }
  }
  dfs2(0);
  rep(i,1,q)printf("%d\n",ans[i]);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}