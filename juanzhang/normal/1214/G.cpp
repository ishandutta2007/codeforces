#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

//inline char nc(){
//  static char buf[1000000],*p1=buf,*p2=buf;
//  return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
//}

//char out_buf[1<<23|5],*ouf=out_buf; // size
//inline void pc(const char&c){*ouf=c,++ouf;}

#define nc() getchar()
#define pc(x) putchar(x)

inline int read(){
  bool f=0;int x=0;char c=nc();
  while(c<48)f|=c=='-',c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return f?-x:x;
}

void write$(int x){
  if(x>9)write$(x/10);
  pc(x%10|48);
}
void write(int x){
  if(x<0)x=-x,pc('-');
  write$(x);
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

int n,m,q;

bitset<2010>A[2010],pre[2010];

int ct[2010];

set<pii>row;

map<pii,pii>mp;

void del(int i,int j){
  if(i>j)swap(i,j);
  auto it=mp.find({i,j});
  if(it!=mp.end())mp.erase(it);
}
void ins(int i,int j){
  if(i>j)swap(i,j);
  auto tmp=A[i]^A[j],ee=tmp&A[i];
  int x=ee._Find_first();
  tmp^=ee;
  int y=tmp._Find_first();
  if(x<=m&&y<=m){
    mp[{i,j}]={x,y};
  }
}

void solve(){
  n=read(),m=read(),q=read();
  rep(i,1,m)pre[i]=pre[i-1],pre[i].set(i);
  rep(i,1,n)row.insert({0,i});
  while(q--){
    int x=read(),l=read(),r=read();
    A[x]^=pre[r],A[x]^=pre[l-1];
    auto it=row.find({ct[x],x});
    auto pr=it;
    bool flg=1;
    if(it!=row.begin()){
      --pr;
      del(pr->second,x);
    }else flg=0;
    auto nx=it;++nx;
    if(nx!=row.end()){
      del(nx->second,x);
    }else flg=0;
    row.erase(it);
    if(flg)ins(pr->second,nx->second);
    ct[x]=A[x].count();
    it=row.insert({ct[x],x}).first;
    flg=1;
    pr=it;
    if(it!=row.begin()){
      --pr;
      ins(pr->second,x);
    }else flg=0;
    nx=it;++nx;
    if(nx!=row.end()){
      ins(nx->second,x);
    }else flg=0;
    if(flg)del(pr->second,nx->second);
    if(mp.empty()){
      puts("-1");
    }else{
      auto it=mp.begin();
      pii p=it->first,q=it->second;
      int x1=p.first,x2=p.second,y1=q.first,y2=q.second;
      if(x1>x2)swap(x1,x2);
      if(y1>y2)swap(y1,y2);
//      rep(i,1,n){
//        rep(j,1,m){
//          putchar(int(A[i][j])|48);
//        }
//        puts("");
//      }
      printf("%d %d %d %d\n",x1,y1,x2,y2);
//      assert(A[x1][y1]==A[x2][y2]&&A[x1][y2]==A[x2][y1]&&A[x1][y1]!=A[x1][y2]);
    }
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
//  fwrite(out_buf,1,ouf-out_buf,stdout);
  return 0;
}