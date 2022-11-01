#include<cstdio>
#include<algorithm>

#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;

#ifndef ONLINE_JUDGE
#include<iostream>
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif
template<class T> void chmin(T& a,const T& b) { a=min(a,b);}
typedef unsigned int uint;
#define INF (1e9+10)

typedef pair<int,int> pi;
int cnt=1;

#define md ((l+r)>>1)

#define mnL(i) (md-l==1?i:pool[i].mini)
#define mnR(i) (r-md==1?i:pool[i].mini)
struct node{
  unsigned long long lch:23,rch:23,mini:18;
  int copy();
  int add(int,int);
  int query(int,int);
};
#define M (7938175)
node pool[M];

int a,b;
int node::add(int l,int r){
  if(r-l==1) return (this-pool)+1;

  if(cnt==M) --cnt;
  int id=cnt++;
  pool[id]=*this;
  if(a<=l && r<=b){
    ++pool[id].mini;
    return id;
  }
  int base=mini-min(mnL(lch),mnR(rch));
  if(a<md){
    pool[id].lch=pool[lch].add(l,md);
  }
  if(md<b){
    pool[id].rch=pool[rch].add(md,r);
  }
  pool[id].mini=base+min(mnL(pool[id].lch),mnR(pool[id].rch));
  return id;
}
int node::query(int l,int r){
  if(r-l==1) return (this-pool);
  if(a<=l && r<=b) return mini;
  int res=INF,base=mini-min(mnL(lch),mnR(rch));
  if(a<md){
    res=pool[lch].query(l,md);
  }
  if(md<b){
    chmin(res,pool[rch].query(md,r));
  }
  return res+base;
}

int n,m;

pi ar2[200001];

#define OFF (1)
int main(){
  scanf("%d%d",&n,&m);
  REP(i,n){
    int a;scanf("%d",&a);
    ar2[i]=mp(a,i);
  }
  sort(ar2,ar2+n);

  int root=cnt++;

  int len=n-m+1+OFF;
  REP(i,n){
    a=max(0,ar2[i].sc-m+1),b=min(ar2[i].sc+1,len);
    a+=OFF;b+=OFF;
    if(a<=OFF) a=0;
    ar2[i].sc=pool[root].add(0,len);
    root=ar2[i].sc;
  }

  int q;
  scanf("%d",&q);

  int prev=0;
  while(q--){
    int l,r,x;
    scanf("%d%d%d",&l,&r,&x);
    if(cnt==M){
      puts("0");
      continue;
    }
    --l;
    x^=prev;

    l+=OFF;r+=OFF;

    int lb=lower_bound(ar2,ar2+n,mp(x,-1))-ar2;
    int res;
    a=l;b=r;
    if(lb==0) res=0;
    else res=pool[ar2[lb-1].sc].query(0,len);
    prev=res;
    printf("%d\n",res);
  }
  return 0;
}