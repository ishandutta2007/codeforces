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

//const int INF=5e8;

int n;
int h[100005];

struct query{
  int l,r,w;

  int lb,ub,md,id;

  bool operator <(const query& a)const{
    return md<a.md;
  }
};

int m1,m2;
query cur[100005],nxt[100005];

struct segtree{
  int val[400005],all[400005];
  int n;
  set<int> hole;
  void init(int n_){
    hole.clear();

    REP(i,n_) hole.insert(i);
    n=1;
    while(n<n_) n<<=1;
    REP(i,n*2) val[i]=all[i]=0;
  }

  void push(int i){
    if(all[i]){
      val[i*2+1]+=all[i];
      val[i*2+2]+=all[i];

      all[i*2+1]+=all[i];
      all[i*2+2]+=all[i];
      all[i]=0;
    }
  }
  int query(int a,int b,int i,int l,int r){//find max
    if(a<=l && r<=b) return val[i];
    if(b<=l || r<=a) return 0;
    int md=(l+r)>>1;
    push(i);
    return max(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
  }
  void add(int a,int b,int i,int l,int r,int k){
    if(a<=l && r<=b){
      all[i]+=k;
      val[i]+=k;
      return;
    }
    if(b<=l || r<=a) return;
    int md=(l+r)>>1;
    push(i);
    add(a,b,i*2+1,l,md,k);
    add(a,b,i*2+2,md,r,k);
    val[i]=max(val[i*2+1],val[i*2+2]);
  }

  void activate(int k){
    auto it=hole.lower_bound(k);
    int prev;
    if(it==hole.begin()){
      prev=-1;
    }else{
      --it;
      prev=*it;
    }

    hole.erase(k);
    int right_len=query(k+1,k+2,0,0,n);
    add(prev+1,k+1,0,0,n,right_len+1);
  }
};

segtree seg;

int res[100005];
pi h_indx[100005];
int main(){
  cin>>n;
  REP(i,n){
    scanf("%d",&h[i]);
    h_indx[i]=mp(h[i],i);
  }

  sort(h,h+n);
  int zn=unique(h,h+n)-h;

  REP(i,n){
    h_indx[i].fr=lower_bound(h,h+zn,h_indx[i].fr)-h;
  }

  sort(h_indx,h_indx+n,greater<pi>());

  cin>>m1;
  REP(i,m1){
    int l,r,w;scanf("%d%d%d",&l,&r,&w);
    --l;
    cur[i]=(query){l,r,w,0,zn,zn/2,i};
  }
  int m3=m1;

  while(m1>0){
    m2=0;
    seg.init(n);
    sort(cur,cur+m1);
    reverse(cur,cur+m1);
    
    int j=0;
    h_indx[n]=mp(-1,0);
    REP(i,n+1){
      int val=h_indx[i].fr,p=h_indx[i].sc;

      while(j<m1 && cur[j].md>val){
        int l=cur[j].l,r=cur[j].r,w=cur[j].w;
        int lb,ub;
        if(seg.query(l,r-w+1,0,0,seg.n)>=w){
          lb=cur[j].md;
          ub=cur[j].ub;
        }else{
          lb=cur[j].lb;
          ub=cur[j].md;
        }
        if(ub-lb>1){
          cur[j].lb=lb;
          cur[j].ub=ub;
          cur[j].md=(lb+ub)>>1;
          nxt[m2++]=cur[j];
        }else{
          res[cur[j].id]=h[lb];
        }
        ++j;
      }
      if(i<n) seg.activate(p);
    }
    REP(i,m2) cur[i]=nxt[i];
    m1=m2;

  }

  REP(i,m3) printf("%d\n",res[i]);

  return 0;
}