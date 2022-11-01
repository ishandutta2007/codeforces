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
struct uf{
  static const int MAXN=300005;
  int par[MAXN];
  pi range[MAXN];
  int size[MAXN];
  void init(){
    memset(par,-1,sizeof(par));
    REP(i,MAXN) size[i]=1,range[i]=mp(i,i+1);
  }
  int root(int a){
    if(par[a]==-1) return a;
    return par[a]=root(par[a]);
  }
  void unite(int a,int b){
    a=root(a);b=root(b);
    if(a==b) return;
    par[b]=a;
    chmin(range[a].fr,range[b].fr);
    chmax(range[a].sc,range[b].sc);
    size[a]+=size[b];
  }
  bool same(int a,int b){
    return root(a)==root(b);
  }
};

uf u;
int n,k;
int ar[300005];
pi pos[300005];

int L[300005],R[300005];
vector<int> posar[1000005];

int sum[300005];
bool done[300005];

int gett(int l,int r,int val){
  return lower_bound(ALL(posar[val]),r)-lower_bound(ALL(posar[val]),l);
}
int main(){
  u.init();
  cin>>n>>k;
  REP(i,n) scanf("%d",&ar[i+1]),pos[i]=mp(ar[i+1],i+1);
  REP(i,n+2) sum[i+1]=(sum[i]+ar[i])%k;
  for(int i=1;i<=n+1;++i){
    posar[sum[i]].pb(i);
    L[i]=i;
    R[i]=i+1;
  }

  sort(pos,pos+n);

  lint res=0;
  REP(i,n){
    int p=pos[i].sc;
    done[p]=1;
    int l=L[p-1],r=R[p+1];
    if(!done[p-1]) l=p;
    if(!done[p+1]) r=p+1;

    if(r-p<p-l){
      for(int j=p;j<r;++j) res+=gett(l,p+1,(sum[j+1]-pos[i].fr%k+k)%k);
    }else{
      for(int j=l;j<=p;++j) res+=gett(p+1,r+1,(pos[i].fr+sum[j])%k);
    }
    R[l]=r;
    L[r-1]=l;
  }
  res-=n;
  cout<<res<<endl;
  return 0;
}