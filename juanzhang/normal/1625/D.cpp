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

const int maxn=3e5+10;
int n,k,A[maxn];

vi dfs(vi p,vi q,int k,int lev){
  if(p.empty()&&q.empty())return{};
  if(p.empty())return {q.back()};
  if(q.empty())return {p.back()};
  if(lev==-1)return {p.back(),q.back()};
  vi pp[2],qq[2];
  for(int x:p)pp[A[x]>>lev&1].push_back(x);
  for(int x:q)qq[A[x]>>lev&1].push_back(x);
  if(k>>lev&1){
    vi a=dfs(pp[0],qq[1],k,lev-1);
    vi b=dfs(pp[1],qq[0],k,lev-1);
    if(a.size()<b.size())return b;
    else return a;
  }else{
    if(!pp[0].empty()&&!qq[1].empty())return{pp[0].back(),qq[1].back()};
    if(!pp[1].empty()&&!qq[0].empty())return{pp[1].back(),qq[0].back()};
    return dfs(p,q,k,lev-1);
  }
}

vi divide(vi p,int k,int lev){
  if(p.empty()||lev==-1)return p;
  vi v[2];
  for(int x:p)v[A[x]>>lev&1].push_back(x);
  vi res;
  if(k>>lev&1){
//    for(int x:p)printf("(%d %d) %d\n",k,lev,A[x]);
//    puts("");
//    if(v[0].empty())return {v[1].back()};
//    if(v[1].empty())return {v[0].back()};
//    for(int x:v[0])for(int y:v[1]){
//      if((A[x]^A[y])>=k)return{x,y};
//    }
//    return {v[0].back()};
    return dfs(v[0],v[1],k,lev-1);
//    if(!v[0].empty())res.push_back(v[0].back());
//    if(!v[1].empty())res.push_back(v[1].back());
//    return res;
  }else{
    res=divide(v[0],k,lev-1);
    vi ano=divide(v[1],k,lev-1);
    for(int x:ano)res.push_back(x);
    return res;
  }
}

void solve(){
  cin>>n>>k;
  rep(i,1,n)A[i]=read();
  vi vec(n);
  rep(i,1,n)vec[i-1]=i;
  vi res=divide(vec,k,29);
  if(res.empty()||res.size()<2u){
    puts("-1");
  }else{
    cout<<res.size()<<endl;
    for(int x:res)printf("%d ",x);
  }
}

signed main(){
//  int T;cin>>T;
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}