#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

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

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int n;
pii dat[maxn];

struct node{
  int i,j,v;
  bool operator<(const node&o)const{
    return v<o.v;
  }
  void print(){
    printf("%d %d %d\n",i,j,v);
  }
}ans;

int bit[30][30];
int calc(int x,int lev){
  if(!x)return 0;
  int res=0,lw=-1,y=x&-x;
  rep(i,0,29)if(x>>i&1){
    lw=i;break;
  }
  per(i,29,lev)if(x>>i&1){
    res++;
    if(x==y)break;
    x^=bit[max(lw+1,lev)][i];
//    per(j,i,lev)x^=1<<j;
  }
  return res;
} // dis(0,x)
int calc2(int x,int y){
//  printf("(%d %d)\n",x,y);
  int res=0;
  while(x||y){
    if((x&-x)==(y&-y)){
      x&=x-1;
      y&=y-1;
    }else{
      return res+__builtin_popcount(x)+__builtin_popcount(y);
    }
  }
  return res;
//  if(!x||!y)return 0;
//  vi X,Y;
//  per(i,29,0)if(x>>i&1){
//    X.push_back(i);
//    x^=bit[0][i];
//  }
//  per(i,29,0)if(y>>i&1){
//    Y.push_back(i);
//    y^=bit[0][i];
//  }
//  reverse(Y.begin(),Y.end());
//  while(!X.empty()&&!Y.empty()&&X.back()==Y.back())X.pop_back(),Y.pop_back();
//  return X.size()+Y.size();
} // dis(0,x)

int get(int x){
  int res=0,s=0;
  per(i,29,0)if((x>>i&1)!=s)res|=1<<i,s^=1;
  return res;
}

void divide(vector<pii>vec,int lev){
  if(vec.empty()||lev>29)return;
  vector<pii>lef,rig;
  for(pii p:vec)if(~p.first>>lev&1)lef.push_back(p);
  else rig.push_back(p);
  pii x(-1,-1),y(-1,-1);
  for(pii p:lef)if(x==pii(-1,-1)||(calc(p.first,lev)>calc(x.first,lev)))x=p;
  for(pii p:rig)if(y==pii(-1,-1)||(calc(p.first,lev)>calc(y.first,lev)))y=p;
//    printf("(%d %d (%d)) (%d %d (%d))\n",x.first,calc(x.first,(lev)),x.first>>lev,y.first,calc(y.first,(lev)),y.first>>lev);
  if(x!=pii(-1,-1)&&y!=pii(-1,-1))chkmax(ans,{x.second,y.second,calc(x.first,lev)+calc(y.first,lev)});
  lev++;
  divide(lef,lev);
  if(y!=pii(-1,-1)){
    if(rig.size()<50u){
      vector<pii>ano;
      for(pii p:rig)ano.push_back({get(p.first>>lev),p.second});
      rep(i,0,ano.size()-1)rep(j,i+1,ano.size()-1){
        chkmax(ans,{ano[i].second,ano[j].second,calc2(ano[i].first,ano[j].first)});
      }
      return;
    }
    x=y=pii(-1,-1);
    for(pii p:rig)if(y==pii(-1,-1)||(calc(p.first,(lev))>calc(y.first,(lev))))y=p;
    for(pii p:rig)if(p!=y&&(x==pii(-1,-1)||(calc(p.first,(lev))>calc(x.first,(lev)))))x=p;
    if(x!=pii(-1,-1)&&y!=pii(-1,-1))chkmax(ans,{x.second,y.second,calc(x.first,(lev))+calc(y.first,(lev))});
  }
}

void solve(){
  rep(i,0,29)rep(j,i,29)rep(k,i,j)bit[i][j]^=1<<k;
  n=read();
  vector<pii>vec;
  rep(i,1,n)dat[i]={read(),i},vec.push_back(dat[i]);
  divide(vec,0);
//  cout<<ans.v<<endl;
  ans.print();
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}