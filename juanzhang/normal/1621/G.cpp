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


const int P=1e9+7;

template<typename T>T inverse(T a,T m){
  if((a%=m)<0)a+=m;
  T b=m,u=0,v=1;
  while(a){
    T t=b/a;
    b-=a*t,swap(a,b),u-=v*t,swap(u,v);
  }
  return u<0?u+m:u;
}

int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int &x,int y){x+=y;if(x>=P)x-=P;}
void Sub(int &x,int y){x-=y;if(x<0)x+=P;}
int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}

//int inv[maxn],fac[maxn],ifac[maxn];
//int binom(int n,int m){return n<m?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
//void init(){
//  fac[0]=ifac[0]=inv[1]=fac[1]=ifac[1]=1;
//  rep(i,2,maxn-1)inv[i]=1ll*(P-P/i)*inv[P%i]%P,fac[i]=1ll*i*fac[i-1]%P,ifac[i]=1ll*inv[i]*ifac[i-1]%P;
//}

const int maxn=2e5+10;
int n,A[maxn],suf[maxn];

int vsz,dat[maxn];

int F[maxn],G[maxn];

struct BIT{
  int clo,c[maxn],tim[maxn];
  void clear(){
    ++clo;
  }
  void add(int pos,int x){
    for(pos++;pos<maxn;pos+=pos&-pos)tim[pos]==clo?Add(c[pos],x),0:(c[pos]=x,tim[pos]=clo);
  }
  int query(int pos){
    int res=0;for(pos++;pos;pos&=pos-1)if(tim[pos]==clo)Add(res,c[pos]);return res;
  }
}Bf,Bg,bit,tr;

int dp[maxn];

void solve(){
  n=read();
  rep(i,1,n)dat[i]=A[i]=read();
  sort(dat+1,dat+n+1);
  vsz=unique(dat+1,dat+n+1)-dat-1;
  rep(i,1,n)A[i]=lower_bound(dat+1,dat+vsz+1,A[i])-dat;
  suf[n+1]=0;
  per(i,n,1)suf[i]=max(suf[i+1],A[i]);
  F[0]=0,G[0]=1;
  rep(i,1,n){
    Bf.add(A[i-1],Inc(F[i-1],G[i-1]));
    Bg.add(A[i-1],G[i-1]);
    F[i]=Bf.query(A[i]-1);
    G[i]=Bg.query(A[i]-1);
//    rep(j,0,i-1)if(A[j]<A[i]){
//      Add(G[i],G[j]);
//      Add(F[i],Inc(F[j],G[j]));
//    }
//    printf("(%d %d)\n",F[i],G[i]);
  }
  int ans=0;
  rep(i,1,n)if(A[i]<=suf[i+1]){
    if(A[i]<suf[i+1]){
      Add(ans,F[i]);
    }else{
      Add(ans,Dec(F[i],G[i]));
    }
  }
//  printf("#%d\n",ans);
  vector<pii>vec;
  per(i,n,1){
    if(A[i]>suf[i+1]){
      vec.push_back({A[i],i});
      dp[i]=1;
    }else{
      dp[i]=Dec(bit.query(vsz+4),bit.query(A[i]));
    }
//    printf("%d : %d\n",i,dp[i]);
    bit.add(A[i],dp[i]);
  }
  static int bl[maxn];
  static vi buk[maxn];
  per(i,n,1){
    bl[i]=upper_bound(vec.begin(),vec.end(),pii(A[i],A[i]>suf[i+1]?0:n+1))-vec.begin();
    if(vec[bl[i]].second<i)bl[i]--;
    buk[bl[i]].push_back(i);
  }
  rep(_,0,vec.size()-1){
    tr.clear();
    bool flg=1;
    for(int i:buk[_]){
//      printf("i %d bl %d\n",i,vec[_].second);
      int v;
      if(flg){
        v=1,flg=0;
      }else{
        v=Dec(tr.query(vsz+4),tr.query(A[i]));
      }
//      printf("!%d\n",v);
      Sub(dp[i],v);
      tr.add(A[i],v);
    }
  }
  rep(i,1,n)if(suf[i]>vec[bl[i]].first)Add(ans,1ll*G[i]*dp[i]%P);
  cout<<ans<<endl;
  Bf.clear(),Bg.clear(),bit.clear();
  rep(i,0,n)dp[i]=0,buk[i].clear();
}

signed main(){
  int T;cin>>T;
  while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}