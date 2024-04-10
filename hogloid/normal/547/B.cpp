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

int evermx,curval;
int res[200005];
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
    while(evermx<size[a]){
      ++evermx;
      res[evermx]=curval;
    }
  }
  bool same(int a,int b){
    return root(a)==root(b);
  }
};
uf u;
int n;
pi ar[200005];
int val[200005];
int main(){
  cin>>n;
  u.init();
  REP(i,n){
    scanf("%d",&ar[i].fr);
    val[i]=ar[i].fr;
    ar[i].sc=i;
  }
  sort(ar,ar+n,greater<pi>());
  res[1]=ar[0].fr;
  evermx=1;
  REP(i,n){
    int p=ar[i].sc;
    curval=val[p];
    if(p>0 && val[p-1]>=val[p]){
      u.unite(p-1,p);
    }
    if(p+1<n && val[p+1]>=val[p]){
      u.unite(p,p+1);
    }
  }
  for(int i=1;i<=n;++i) printf("%d\n",res[i]);
  return 0;
}