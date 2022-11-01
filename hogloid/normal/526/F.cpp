#include<bits/stdc++.h>
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
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

lint readL(){
  lint res;
#ifdef ONLINE_JUDGE
  scanf("%I64d",&res);
#else
  scanf("%lld",&res);
#endif
  return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
  printf("%I64d",res);
#else
  printf("%lld",res);
#endif
}

const int INF=5e8;
int n;
int row[300005],col[300005];

struct segtree{
  int val[1100000],cnt[1100000],lazy[1100000];
  int n;
  void merge(int i){
    val[i]=min(val[i*2+1],val[i*2+2]);
    cnt[i]=0;
    lazy[i]=0;
    REP(t,2) if(val[i]==val[i*2+1+t]) cnt[i]+=cnt[i*2+1+t];
  }
  void push(int i){
    if(lazy[i]){
      val[i*2+1]+=lazy[i];
      val[i*2+2]+=lazy[i];
      lazy[i*2+1]+=lazy[i];
      lazy[i*2+2]+=lazy[i];
    }
  }
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    CLR(lazy);
    CLR(cnt);
    REP(i,n*2) val[i]=INF;
    REP(i,n_) cnt[i+n-1]=1;
    for(int i=n-2;i>=0;--i){
      merge(i);
    }
  }
  void add(int a,int b,int i,int l,int r,int v){
    if(a<=l && r<=b){
      val[i]+=v;
      lazy[i]+=v;
      return;
    }
    if(b<=l || r<=a) return;
    int md=(l+r)>>1;
    push(i);
    add(a,b,i*2+1,l,md,v);
    add(a,b,i*2+2,md,r,v);
    merge(i);
  }
  int query(){
    return cnt[0];
  }
};
segtree seg;


int main(){
  cin>>n;
  REP(i,n){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    row[a]=b;
    col[b]=a;
  }
  lint res=0;
  seg.init(n);

  stack<int> up,down;
  up.push(n);
  down.push(n);
  for(int i=n-1;i>=0;--i){
    int h=row[i];
    seg.add(i,n,0,0,seg.n,-1);
    seg.add(i,i+1,0,0,seg.n,-INF+1);
    while(up.size()>1 && row[up.top()]<h){
      int cur=up.top();up.pop();
      int nxt=up.top();
      seg.add(cur,nxt,0,0,seg.n,h-row[cur]);
    }
    up.push(i);
    while(down.size()>1 && row[down.top()]>h){
      int cur=down.top();down.pop();
      int nxt=down.top();
      seg.add(cur,nxt,0,0,seg.n,row[cur]-h);
    }
    down.push(i);
    res+=seg.query();
  }
  cout<<res<<endl;
  return 0;
}