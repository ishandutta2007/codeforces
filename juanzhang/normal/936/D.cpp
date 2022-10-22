#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

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
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

//const int P=1e9+7;
const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=6e6+10;
int lim,a,b,k;

int n,pos[maxn];bool hav[maxn][2];

int dp[maxn][2],pre[maxn][2];

int len,dat[maxn];
int gg,zzh[maxn][2];
int chk[maxn];
void outp(int i,int j){
  chk[i]=j;
  if(!i){
    if(j)dat[++len]=0;
    return;
  }
  if(pre[i][j]==j){
    outp(i-1,j);
  }else{
    outp(i-1,j^1);
    if(i<n)dat[++len]=pos[i];
  }
}

void solve(){
  cin>>lim>>a>>b>>k;
  vi va(a),vb(b);
  for(int&x:va){
    x=read();
  }
  for(int&x:vb){
    x=read();
  }
  for(int i=0,j=0;i<a||j<b;){
    int x=i<a?va[i]:lim+1;
    int y=j<b?vb[j]:lim+1;
//    printf("%d %d : %d %d\n",i,j,x,y);
    if(x<y){
      if(pos[n]<x-1)pos[++n]=x-1;
      if(pos[n]<x)pos[++n]=x;
      hav[n][0]=1;
      pos[++n]=x+1;
      i++;
    }else if(x>y){
      if(pos[n]<y-1)pos[++n]=y-1;
      if(pos[n]<y)pos[++n]=y;
      hav[n][1]=1;
      pos[++n]=y+1;
      j++;
    }else{
      if(pos[n]<x-1)pos[++n]=x-1;
      if(pos[n]<x)pos[++n]=x;
      hav[n][0]=1,hav[n][1]=1;
      pos[++n]=x+1;
      i++,j++;
    }
  }
  if(pos[n]<=lim)pos[++n]=lim+1;
  memset(dp,-0x3f,sizeof dp);
  dp[0][0]=dp[0][1]=0,pre[0][1]=2;
  rep(i,1,n){
    int v;
    v=dp[i-1][0]+pos[i]-pos[i-1]-hav[i][0]*k;if(v>=hav[i][0])pre[i][0]=0,dp[i][0]=v;
    v=dp[i-1][1]+pos[i]-pos[i-1]-hav[i][1]*k;if(v>=hav[i][1])pre[i][1]=1,dp[i][1]=v;
    if(dp[i][0]>=0&&!hav[i][1]){
      v=min(dp[i][0],k);
      if(dp[i][1]<v)dp[i][1]=v,pre[i][1]=2;
    }
    if(dp[i][1]>=0&&!hav[i][0]){
      v=min(dp[i][1],k);
      if(dp[i][0]<v)dp[i][0]=v,pre[i][0]=2;
    }
//    printf("%d : (%d %d)\n",i,dp[i][0],dp[i][1]);
  }
  if(max(dp[n][0],dp[n][1])>=0){
    puts("Yes");
    outp(n,dp[n][1]>=0);
    write(len),pc(10);
    rep(i,1,len)write(dat[i]),pc(32);pc(10);
    rep(i,0,n){
      int j=i;
      while(j<n&&chk[i]==chk[j+1])j++;
      int ct=0;
      rep(k,i,j)ct+=hav[k][chk[k]];
      if(pos[j]<=lim)ct+=hav[j+1][chk[i]];
      int cur=dp[i][chk[i]],o=pos[i];
      while(ct--){
        if(cur>=k){
          cur-=k;
        }else{
          o+=k-cur;
          cur=0;
        }
        gg++,zzh[gg][0]=o,zzh[gg][1]=chk[i];
      }
      i=j;
    }
    write(gg),pc(10);
    rep(i,1,gg)write(zzh[i][0]),pc(32),write(zzh[i][1]+1),pc(10);
  }else{
    puts("No");
  }
}

signed main(){
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}