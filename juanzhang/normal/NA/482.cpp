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
int n,q,A[maxn];

vi datX,datY;
int getX(int x){
  return lower_bound(datX.begin(),datX.end(),x)-datX.begin()+1;
}
int getY(int y){
  return lower_bound(datY.begin(),datY.end(),y)-datY.begin()+1;
}

void init(){
  static const int P=1e9+9;
  static struct point{
    int x,y;
  }dat[maxn];
  n=read();
  int k=read();
  rep(i,1,k)dat[i].x=read(),dat[i].y=read();
  int a=read(),b=read(),c=read(),d=read();
  rep(i,k+1,n){
    dat[i].x=(1ll*a*dat[i-1].x+b)%P;
    dat[i].y=(1ll*c*dat[i-1].y+d)%P;
  }
  datX.reserve(n);rep(i,1,n)datX.push_back(dat[i].x);sort(datX.begin(),datX.end());
  datY.reserve(n);rep(i,1,n)datY.push_back(dat[i].y);sort(datY.begin(),datY.end());
  rep(i,1,n){
    dat[i].x=getX(dat[i].x);
    dat[i].y=getY(dat[i].y);
    A[dat[i].x]=dat[i].y;
  }
}

pii ans[maxn];
int ls[maxn],rs[maxn],lef[maxn],rig[maxn];

pii merge(pii x,pii y){
  pii res;
  res.first=max(x.first,x.second)+max(y.first,y.second);
  res.second=max(x.first+max(y.first,y.second),max(x.first,x.second)+y.first)+1;
  return res;
}

void dfs(int u){
  lef[u]=rig[u]=u;
  if(ls[u])dfs(ls[u]),chkmin(lef[u],lef[ls[u]]);
  if(rs[u])dfs(rs[u]),chkmax(rig[u],rig[rs[u]]);
  ans[u]=merge(ans[ls[u]],ans[rs[u]]);
//  printf("%d : [%d %d]\n",u,ans[u].first,ans[u].second);
}

pii solve(int u,int l,int r){
  if(!u)return pii(INT_MIN,0);
  if(l<=lef[u]&&rig[u]<=r)return ans[u];
  if(u<l)return solve(rs[u],l,r);
  if(u>r)return solve(ls[u],l,r);
  pii x=solve(ls[u],l,r);
  pii y=solve(rs[u],l,r);
  return merge(x,y);
}

void solve(){
  init();
  int top=0;
  static int st[maxn];
  rep(i,1,n){
    while(top&&A[st[top]]<A[i])ls[i]=st[top--];
    if(top)rs[st[top]]=i;
    st[++top]=i;
  }
  ans[0]=pii(INT_MIN,0);
  dfs(st[1]);
  for(q=read();q--;){
    int l=read(),r=read();
    l=getX(l),r=upper_bound(datX.begin(),datX.end(),r)-datX.begin();
//    printf("(%d %d)\n",l,r);
    if(l>r){
      pc(48),pc(10);continue;
    }
    pii as=solve(st[1],l,r);
    write(max(as.first,as.second)),pc(10);
  }
}

signed main(){
//  int T;cin>>T;
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}