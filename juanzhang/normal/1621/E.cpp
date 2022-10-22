#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int val[maxn<<2],tag[maxn<<2];
void pushtag(int k,int x){
  tag[k]+=x;val[k]+=x;
}
void pushdown(int k){
  int&x=tag[k];
  if(x){
    pushtag(k<<1,x);
    pushtag(k<<1|1,x);
    x=0;
  }
}
void maintain(int k){
  val[k]=min(val[k<<1],val[k<<1|1]);
}
void build(int k,int l,int r){
  tag[k]=0;
  if(l==r){
    val[k]=l;
  }else build(lson),build(rson),maintain(k);
}
void add(int k,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr){
    pushtag(k,x);
    return;
  }
  pushdown(k);
  if(ql<=mid)add(lson,ql,qr,x);
  if(qr>mid)add(rson,ql,qr,x);
  maintain(k);
}

#undef mid
#undef lson
#undef rson

int n,m,A[maxn];

vi vec[maxn];

int find(ll su,ll sz){
  int l=1,r=n,ans=0;
  while(l<=r){
    int mid=(l+r)/2;
    A[mid]*sz>=su?l=(ans=mid)+1:r=mid-1;
  }
  return ans;
}

ll sum[maxn],cnt[maxn];
int tmp[maxn];

void solve(){
  n=read(),m=read();
  rep(i,1,n)A[i]=read();
  sort(A+1,A+n+1,greater<int>());
  build(1,0,n);
  rep(i,1,m){
    vec[i].clear();
    int k=read();
    ll su=0;
    rep(_,1,k){
      int x=read();
      vec[i].push_back(x);
      su+=x;
    }
    int pos=find(su,k);
//    printf("!%d\n",pos);
    add(1,0,n,pos,n,-1);
    sum[i]=su,cnt[i]=k,tmp[i]=pos;
  }
//  printf("#%d\n",val[1]);
  rep(i,1,m){
    add(1,0,n,tmp[i],n,1);
    for(int x:vec[i]){
      ll su=sum[i]-x;
      ll sz=cnt[i]-1;
      int pos=find(su,sz);
      add(1,0,n,pos,n,-1);
      if(val[1]<0){
        putchar('0');
      }else{
        putchar('1');
      }
      add(1,0,n,pos,n,1);
    }
    add(1,0,n,tmp[i],n,-1);
  }
  puts("");
}

signed main(){
  int T;cin>>T;
  while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}