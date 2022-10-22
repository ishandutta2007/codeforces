#pragma GCC optimize(3)

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
const int maxn=1e5+10,P=998244353;
int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int &x,int y){x+=y;if(x>=P)x-=P;}
void Sub(int &x,int y){x-=y;if(x<0)x+=P;}
int n,k,A[maxn],lev[maxn],dp[maxn],vp[maxn],lst[maxn];int bsz,bl[maxn];

int ns,tag[505];
int buf_top,buf_st[maxn*100],nxt[maxn*100],key[maxn*100],val[maxn*100];
struct hashmap{
  int ct,h[1009];
  int find(int x){
    for(int i=h[(x+114514)%1009];i;i=nxt[i])if(key[i]==x)return i;
    return -1;
  }
  int query(int x){int tp=find(x);return tp==-1?0:val[tp];}
  void add(int x,int v){
    int tp=find(x);
    if(tp!=-1){
      Add(val[tp],v);
    }else{
      int&p=h[(x+114514)%1009];
      tp=buf_st[buf_top--],nxt[tp]=p,p=tp,key[tp]=x,val[tp]=v,ct++;
    }
  }
  void clear(){
    rep(x,0,1008){
      int&i=h[x];
      while(i){
        key[i]=val[i]=0,buf_st[++buf_top]=i;
        int&tp=nxt[i];i=tp,tp=0;
      }
    }
  }
}ump[505];
void pushdown(int ps){
  int l=(ps-1)*bsz+1,r=min(n,ps*bsz);
  ump[ps].clear();
  rep(i,l,r){
    ump[ps].add(lev[i]+=tag[ps],dp[i-1]);
  }
  tag[ps]=0;
}
void upd(int l,int r,int x){
  int ps=bl[l],&tp=tag[ps];
  if(ump[ps].ct>1000)pushdown(ps);
  rep(i,l,r){
    if(lev[i]+tp==-1&&x==1)Add(ns,dp[i-1]);
    if(lev[i]+tp==0&&x==-1)Sub(ns,dp[i-1]);
    if(dp[i-1])ump[ps].add(lev[i],P-dp[i-1]);
    ump[ps].add(lev[i]+=x,dp[i-1]);
  }
}
void add(int l,int r,int x){
  if(bl[l]==bl[r]){
    upd(l,r,x);return;
  }
  upd(l,bl[l]*bsz,x);
  upd((bl[r]-1)*bsz+1,r,x);
  rep(ps,bl[l]+1,bl[r]-1){
    if(x==1){
      Add(ns,ump[ps].query(-1-tag[ps]));
    }else{
      Sub(ns,ump[ps].query(-tag[ps]));
    }
    tag[ps]+=x;
  }
}
void ins(int x,int v){
  pushdown(bl[x]);
  if(lev[x]>=0)Add(ns,v);
}

void solve(){
  buf_top=maxn*100-1;
  rep(i,1,maxn*100-1)buf_st[i]=i;
  cin>>n>>k;
  bsz=200;
  rep(i,1,n)lev[i]=k,A[i]=read(),bl[i]=(i-1)/bsz+1;
  dp[0]=1;
  rep(i,1,n){
    int&p=lst[i];p=vp[A[i]],vp[A[i]]=i;
    if(p)add(lst[p]+1,p,1);
    add(p+1,i,-1),ins(i,dp[i-1]),dp[i]=ns;
  }
  cout<<dp[n]<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}