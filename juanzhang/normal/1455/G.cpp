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
const int maxn=2e5+10;
int n,S,valsz=200000;char str[10];

int k,tot,rt[maxn],ls[maxn*30],rs[maxn*30];ll tag[maxn*30],val[maxn*30];

void pushtag(int k,ll x){
  if(k)tag[k]+=x,val[k]+=x,chkmin(val[k],(ll)1e18);
}
void pushdown(int k){
  ll&x=tag[k];
  if(k&&x)pushtag(ls[k],x),pushtag(rs[k],x),x=0;
}
void ins(int&k,int l,int r,int x,ll v){
  if(!k)k=++tot;
  if(l==r)return val[k]=v,void();int mid=(l+r)/2;pushdown(k);
  x<=mid?ins(ls[k],l,mid,x,v):ins(rs[k],mid+1,r,x,v),val[k]=min(val[ls[k]],val[rs[k]]);
}
ll query(int k,int l,int r,int x){
  if(l==r)return val[k];
  int mid=(l+r)/2;pushdown(k);
  return x<=mid?query(ls[k],l,mid,x):query(rs[k],mid+1,r,x);
}
int merge(int x,int y,int l,int r){
  if(!x||!y)return x|y;
  if(l==r)return chkmin(val[x],val[y]),x;
  pushdown(x),pushdown(y);int mid=(l+r)/2;
  ls[x]=merge(ls[x],ls[y],l,mid);
  rs[x]=merge(rs[x],rs[y],mid+1,r);
  val[x]=min(val[ls[x]],val[rs[x]]);
  return x;
}

void dfs(int u){
  while(~scanf("%s",str)){
    if(*str=='e')break;
    int x=read();
    if(*str=='s'){
      int y=read();
      ll tp=val[rt[u]];pushtag(rt[u],y);
      if(x!=S&&tp<1e18)ins(rt[u],0,valsz,x,tp);
//      printf("#%lld\n",val[rt[u]]);
    }else{
      ll tp=query(rt[u],0,valsz,x);
      if(tp<1e18){
        int v=++k;
//        printf("#%lld\n",tp);
        ins(rt[v],0,valsz,x,tp),dfs(v),rt[u]=merge(rt[u],rt[v],0,valsz),ins(rt[u],0,valsz,x,query(rt[v],0,valsz,x));
      }else{
        int cur=1;
        while(cur){
          scanf("%s",str);
          if(*str=='s')scanf("%*d%*d");
          else if(*str=='i')cur++,scanf("%*d");
          else cur--;
        }
      }
    }
  }
}

void solve(){
  cin>>n>>S;
  memset(val,0x3f,sizeof val);
  k=1,ins(rt[1],0,valsz,0,0),dfs(1);
  cout<<val[rt[1]]<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}