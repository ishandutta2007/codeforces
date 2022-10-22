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
int n,k,A[maxn];
struct node{
  int d,l;
  bool operator<(const node&o)const{
    return d<o.d;
  }
};
multiset<node>S;

namespace fhq{
const int maxn = 8e5 + 10;
int rt, tot, ch[maxn][2], ss[maxn],sz[maxn], val[maxn], key1[maxn], key2[maxn], rnd[maxn];ll sum1[maxn], sum2[maxn];

int newn(int k = 0,int v1=0,int v2=0,int s=0) {
  tot++;
  sum1[tot]=key1[tot]=v1,sum2[tot]=key2[tot]=v2;
  sz[tot]=ss[tot]= s, val[tot] = k, rnd[tot] = rand();
  return tot;
}

void mt(int k) {
  sz[k] = sz[ch[k][0]] + sz[ch[k][1]] + ss[k];
  sum1[k]=sum1[ch[k][0]]+sum1[ch[k][1]]+key1[k];
  sum2[k]=sum2[ch[k][0]]+sum2[ch[k][1]]+key2[k];
}

void split(int k, int v, int& x, int& y) {
  if (!k) {
    x = y = 0;
    return;
  }
  if (val[k] <= v) {
    x = k, split(ch[k][1], v, ch[k][1], y);
  } else {
    y = k, split(ch[k][0], v, x, ch[k][0]);
  }
  mt(k);
}

int merge(int x, int y) {
  if (!x || !y) return x | y;
  int res;
  if (rnd[x] < rnd[y]) {
    res = x, ch[x][1] = merge(ch[x][1], y);
  } else {
    res = y, ch[y][0] = merge(x, ch[y][0]);
  }
  return mt(res), res;
}

void ins(int v,int v1,int v2,int s) {
  int x, y;
  split(rt, v, x, y);
  rt = merge(merge(x, newn(v, v1, v2, s)), y);
}

void del(int v,int v1,int v2) {
  ins(v,-v1,-v2,-1);
}

ll query(int k){
  int x,y;
  split(rt,k,x,y);
  ll res=sum2[x]+1ll*sz[y]*k-sum1[y];
  rt=merge(x,y);
  return res;
}

}

void add(int d,int l,int op){
  int v=d+l;
  int v1=d,v2=l;
  if(op==1)fhq::ins(v,v1,v2,1);
  else fhq::del(v,v1,v2);
}

void solve(){
  cin>>n>>k;
  rep(i,1,n)A[i]=read();
  sort(A+1,A+n+1);
  S.insert({0,1});
  add(0,1,1);
  int res=1e9;
  per(i,n,1){
    node p=*S.begin();S.erase(S.begin());
    add(p.d,p.l,-1);
    if(p.l>1)S.insert({p.d+1,p.l-1}),add(p.d+1,p.l-1,1);
    S.insert({p.d+2,A[i]/2}),add(p.d+2,A[i]/2,1);
    S.insert({p.d+2,A[i]-A[i]/2-1}),add(p.d+2,A[i]-A[i]/2-1,1);
    int l=0,r=200001;
    while(l<r){
      int mid=(l+r)/2;
      ll res=fhq::query(mid+1);
//      printf("(%d %d) %lld\n",i,mid,res);
      res>=k?r=mid:l=mid+1;
    }
    chkmin(res,l);
  }
//  for(node p:S)printf("(%d %d)\n",p.d,p.l);
  printf("%d\n",res>2e5?-1:res);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}