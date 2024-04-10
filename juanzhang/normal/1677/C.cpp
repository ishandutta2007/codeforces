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
void write(ll x){
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

const int maxn=1e5+10;
int n,A[maxn],B[maxn],mpA[maxn],C[maxn];
bool vis[maxn];

void solve(){
  n=read();
  rep(i,1,n)A[i]=read(),mpA[A[i]]=i,vis[i]=0;
  rep(i,1,n)B[i]=read(),B[i]=mpA[B[i]];
  rep(s,1,n)if(!vis[s]){
    int cur=s;
    vi nod;
    do{
      vis[cur]=1;
      nod.push_back(cur);
      cur=B[cur];
    }while(cur!=s);
    if(nod.size()&1){
      C[nod[0]]=0;
      rep(i,1,nod.size()/2)C[nod[i]]=2;
      rep(i,nod.size()/2+1,nod.size()-1)C[nod[i]]=-2;
    }else{
      rep(i,0,nod.size()/2-1)C[nod[i]]=2;
      rep(i,nod.size()/2,nod.size()-1)C[nod[i]]=-2;
    }
  }
  sort(C+1,C+n+1);
  ll ans=0;
  rep(i,1,n)ans+=C[i]*i;
  write(ans),pc(10);
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
  int T;cin>>T;while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}