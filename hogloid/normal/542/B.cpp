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

const int INF=1e9+6000;
struct segtree_dyn{
  struct node{
    int lazy;
    int val;
    node* lch,*rch;
    node(int lazy,int val):lazy(lazy),val(val){
      lch=rch=NULL;
    }
    node(){
      lch=rch=NULL;
      lazy=val=0;
    }
  };
  node pool[500000*31];
  int cnt;
  node* root;
  node* set(int lazy,int val){
    pool[cnt]=node(lazy,val);
    return &pool[cnt++];
  }
  void init(){
    root=set(0,0);
  }
  void push(node* i){
    if(i->lch==NULL){
      i->lch=set(i->lazy,i->lazy);
      i->rch=set(i->lazy,i->lazy);
    }else{
      i->lch->lazy+=i->lazy;
      i->lch->val+=i->lazy;
      i->rch->lazy+=i->lazy;
      i->rch->val+=i->lazy;
    }
    i->lazy=0;
  }
  void add(int a,int b,node* i,int l,int r,int v){
    if(a<=l && r<=b){
      i->lazy+=v;
      i->val+=v;
      return;
    }
    if(b<=l || r<=a) return;
    push(i);
    int md=(l+r)>>1;
    add(a,b,i->lch,l,md,v);
    add(a,b,i->rch,md,r,v);
    i->val=min(i->lch->val,i->rch->val);
  }
  int query(int a,int b,node* i,int l,int r){
    if(a<=l && r<=b) return i->val;
    if(b<=l || r<=a) return INF;
    push(i);
    int md=(l+r)>>1;
    return min(query(a,b,i->lch,l,md),query(a,b,i->rch,md,r));
  }
  int query2(int a,node* i,int l,int r,int lb){
    if(r<=a || i->val>=lb) return -1;
    if(r-l==1) return l;
    int md=(l+r)>>1;
    push(i);
    int L=query2(a,i->lch,l,md,lb);
    if(L!=-1) return L;
    return query2(a,i->rch,md,r,lb);
  }
  int query2(int a){
    int Lmin=query(-INF,a,root,-INF,INF);
    if(query(a,INF,root,-INF,INF)<Lmin){
      return query2(a,root,-INF,INF,Lmin);
    }
    return -1;
  }
};
segtree_dyn seg;
int n;
int R;
pi range[200005];
bool cmp(const pi& a,const pi& b){
  return a.sc<b.sc;
}

int main(){
  cin>>n>>R;
  int ans=0;
  priority_queue<int,vector<int>,greater<int> >pq;
  REP(i,n){
    scanf("%d%d",&range[i].fr,&range[i].sc);
    chmax(range[i].fr,0);
    if(range[i].sc<0){
      range[i]=mp(-1,-1);
      ++ans;
      continue;
    }
    pq.push(range[i].sc);
    pq.push(range[i].sc+1);
  }
  //REP(i,500000) pq.push(i);
  sort(range,range+n,cmp);
  seg.init();
  int seek=0;
  while(range[seek].sc==-1) ++seek;

  int last=0;

  int prev=-114514;
  while(!pq.empty()){
    int p=pq.top();pq.pop();
    if(prev>=p) continue;
    prev=p;
    int val=seg.query(-INF,p-R+1,seg.root,-INF,INF);
    seg.add(p,INF,seg.root,-INF,INF,val-last);
    last=val;

    while(seek<n && range[seek].sc==p){
      seg.add(-INF,range[seek].fr,seg.root,-INF,INF,1);

      int p2=seg.query2(range[seek].fr);
      if(p2!=-1) pq.push(p2+R);
      ++seek;
    }
  }
  int res=seg.root->val;
  cout<<n-res-ans<<endl;
  return 0;
}