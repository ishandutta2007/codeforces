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
int bas,P;
int n,m,A[maxn],B[maxn],mpB[maxn],ans[maxn];

int pro[maxn<<2],ha[maxn<<2];
void ins(int k,int l,int r,int x,int v1,int v2){
  if(l==r)return pro[k]=v1,ha[k]=v2,void();int mid=(l+r)>>1;
  x<=mid?ins(k<<1,l,mid,x,v1,v2):ins(k<<1|1,mid+1,r,x,v1,v2);
  ha[k]=(1ll*ha[k<<1]*pro[k<<1|1]+ha[k<<1|1])%P,pro[k]=1ll*pro[k<<1]*pro[k<<1|1]%P;
}

void steins(){
  set<int>S;
  rep(i,1,m)ins(1,1,m,i,1,0);
  rep(i,1,n){
    S.insert(mpB[i]);
  }
  int lst=-1;
  for(auto x:S){
    if(lst!=-1)ins(1,1,m,x,bas,B[x]-B[lst]+n);
    lst=x;
  }
  int zzh=0;
  rep(i,2,n)zzh=(1ll*zzh*bas+A[i]-A[i-1]+n)%P;
  rep(i,1,m-n+1){
    ans[i-1]&=zzh==ha[1];
    if(i==m-n+1)break;
    auto it=S.find(mpB[i]);
    ins(1,1,m,*it,1,0);
    auto nx=it;++nx;
    if(nx!=S.end()){
      if(it==S.begin())ins(1,1,m,*nx,1,0);
      else --it,ins(1,1,m,*nx,bas,B[*nx]-B[*it]+n);
    }
    S.erase(mpB[i]);
    it=S.insert(mpB[i+n]).first;
    nx=it;++nx;
    if(nx!=S.end())ins(1,1,m,*nx,bas,B[*nx]-B[*it]+n);
    if(it!=S.begin()){
      auto pr=it;--pr;
      ins(1,1,m,*it,bas,B[*it]-B[*pr]+n);
    }
  }
}

void solve(){
  cin>>n>>m;
  rep(i,1,n)A[i]=read();rep(i,1,m)B[i]=read(),mpB[B[i]]=i;
  rep(i,0,m-n)ans[i]=1;
  bas=19491001,P=1e9+7,steins();
//  bas=19260817,P=1e9+9,steins();
  int res=0;
  rep(i,0,m-n)res+=ans[i];
  cout<<res<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}