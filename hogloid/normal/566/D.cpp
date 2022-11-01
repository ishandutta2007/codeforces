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
struct uf{
  static const int MAXN=200005;
  int par[MAXN];
  int size[MAXN];
  void init(){
    memset(par,-1,sizeof(par));
    REP(i,MAXN) size[i]=1;
  }
  int root(int a){
    if(par[a]==-1) return a;
    return par[a]=root(par[a]);
  }
  void unite(int a,int b){
    a=root(a);b=root(b);
    if(a==b) return;
    if(size[a]<size[b]) swap(a,b);

    par[b]=a;
    size[a]+=size[b];
  }
  bool same(int a,int b){
    return root(a)==root(b);
  }
};


//const int INF=5e8;

set<int> gap;
uf u;
int n,q;
int R[200005];
int main(){
  cin>>n>>q;
  REP(i,n-1) gap.insert(i+1);
  u.init();
  REP(i,q){
    int t,x,y;
    scanf("%d%d%d",&t,&x,&y);--x;--y;
    if(t==1){
      u.unite(x,y);
    }else if(t==2){
      auto it=gap.lower_bound(x+1);
      while(it!=gap.end()){
        if((*it)>y) break;
        u.unite((*it),(*it)-1);
        gap.erase(it++);
      }
    }else{
      puts(u.same(x,y)?"YES":"NO");
    }
  }

  return 0;
}