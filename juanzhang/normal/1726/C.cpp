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

const int maxn=2e5+10;
int n;
char S[maxn];
int A[maxn];

int par[maxn];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}
void unite(int x,int y){
  par[find(x)]=find(y);
}

int lg[maxn],st[19][maxn];
int rmq(int l,int r){
  int k=lg[r-l+1];
  return min(st[k][l],st[k][r-(1<<k)+1]);
}

void solve(){
  scanf("%d%s",&n,S+1);
  rep(i,2,n+n)lg[i]=lg[i>>1]+1;
  rep(i,1,n+n)st[0][i]=A[i]=A[i-1]+(S[i]=='('?1:-1),par[i]=i;
  rep(i,1,18){
    rep(j,1,n+n-(1<<i)+1){
      st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
  }
  map<int,int>lst;
  map<int,int>lst2;
  lst[0]=0;
  rep(i,1,n+n){
    auto it=lst2.find(A[i]);
    if(it!=lst2.end()){
      int p=it->second+1;
      if(rmq(p,i)>=A[i]){
        unite(p,i);
      }
    }
    it=lst.find(A[i]);
    if(it!=lst.end()){
      int p=it->second+1;
//      printf("#(%d %d)\n",p,i);
      if(rmq(p,i)>=A[i]){
        unite(p,i);
//        printf("(%d %d)\n",p,i);
      }
      lst2[A[i]]=it->second;
    }
    lst[A[i]]=i;
  }
  int ans=0;
  rep(i,1,n+n)ans+=find(i)==i;
  cout<<ans<<endl;
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
  int T;cin>>T;while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}