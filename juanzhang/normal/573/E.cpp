#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[11];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int maxn=1e5+10;
int n,A[maxn];

struct line{
  ll k,b;
  void operator+=(const line&o){
    k+=o.k,b+=o.b;
  }
};
struct tnode{
  int sz,ls,rs,rnd;ll val,lst;line tag;
}T[maxn];int tot,rt;
int newnode(ll v=0){
  return ++tot,T[tot].val=T[tot].lst=v,T[tot].sz=1,T[tot].rnd=Rnd(),tot;
}
void maintain(int k){
  T[k].sz=T[T[k].ls].sz+T[T[k].rs].sz+1,T[k].lst=T[k].rs?T[T[k].rs].lst:T[k].val;
}
void pushtag(int k,line l){
  T[k].tag+=l,T[k].val+=l.b+l.k*(T[T[k].ls].sz+1),T[k].lst+=l.b+l.k*T[k].sz;
}
void pushdown(int k){
  line&l=T[k].tag;
  if(l.k||l.b){
    pushtag(T[k].ls,l);
    l.b+=l.k*(T[T[k].ls].sz+1);
    pushtag(T[k].rs,l);
    l.k=l.b=0;
  }
}
void split(int k,int s,int&x,int&y){
  if(!k)return x=y=0,void();
  pushdown(k);
  if(s<=T[T[k].ls].sz){
    y=k,split(T[k].ls,s,x,T[y].ls);
  }else{
    x=k,split(T[k].rs,s-T[T[k].ls].sz-1,T[x].rs,y);
  }
  maintain(k);
}
int merge(int x,int y){
  if(!x||!y)return x|y;
  int res;
  if(T[x].rnd<T[y].rnd){
    pushdown(res=x),T[x].rs=merge(T[x].rs,y);
  }else{
    pushdown(res=y),T[y].ls=merge(x,T[y].ls);
  }
  return maintain(res),res;
}
ll ask(int cur,int id){
  while(1){
    int x=T[T[cur].ls].sz+1;
    if(id==x)return T[cur].val;
    pushdown(cur);
    if(id<x){
      cur=T[cur].ls;
    }else{
      id-=x,cur=T[cur].rs;
    }
  }
}

ll ans;
void print(int k){
  if(k){
    pushdown(k);
    print(T[k].ls);
    chkmax(ans,T[k].val);
//    printf("%lld ",T[k].val);
    print(T[k].rs);
  }
}

int pos;int gg;

void dfs(int k,int dt,ll pr){
  if(!k)return;
  pushdown(k);
  ll tp=pr;
  if(T[k].ls)tp=T[T[k].ls].lst;
  int orz=dt+T[T[k].ls].sz;
  tp+=1ll*orz*gg;
  if(!orz||T[k].val>tp){
    pos=++orz;
    dfs(T[k].rs,orz,T[k].val);
  }else{
    dfs(T[k].ls,dt,pr);
  }
}

void solve(){
  n=read();
  rep(i,1,n)A[i]=read();
  rt=newnode();
  rep(i,1,n){
    pos=1;
    if(i>1){
      gg=A[i],dfs(rt,0,0);
//      int l=2,r=i;
//      while(l<=r){
//        int mid=(l+r+1)/2;
//        ll x=ask(rt,mid);
//        ll y=ask(rt,mid-1)+1ll*(mid-1)*A[i];
//        x<=y?r=mid-1:l=(pos=mid)+1;
//      }
    }
//    printf("#%d\n",pos);
    {
      int x,y;
      split(rt,pos,x,y);
      ll tp=ask(x,T[x].sz);
//      ll tp=T[x].lst;
      y=merge(newnode(tp),y);
//      putchar('#');print(y);puts("");
      pushtag(y,{A[i],1ll*(pos-1)*A[i]});
//      putchar('#');print(y);puts("");
      rt=merge(x,y);
    }
//    print(rt);puts("");
  }
  print(rt);
  cout<<ans<<endl;
}

signed main(){
//  int T;cin>>T;
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}