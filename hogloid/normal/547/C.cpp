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
int n,q;
vector<int> fact[200005];

int cnt[500005];
int ar[200005];

bool table[500005];
int prm[500005];
bool mark[200005];
int main(){
  memset(table,1,sizeof(table));
  table[0]=table[1]=0;
  for(int i=2;i*i<=500000;++i) if(table[i]){
    for(int j=i*i;j<=500000;j+=i) table[j]=0;
  }
  int pcnt=0;
  REP(i,500001) if(table[i]) prm[pcnt++]=i;

  cin>>n>>q;
  REP(i,n){
    scanf("%d",&ar[i]);

    int tmp=ar[i];
    for(int j=0;j<pcnt && prm[j]*prm[j]<=tmp;++j) if(tmp%prm[j]==0){
      fact[i].pb(prm[j]);
      while(tmp%prm[j]==0) tmp/=prm[j];
    }
    if(tmp>1) fact[i].pb(tmp);
  }
  lint res=0;
  REP(hoge,q){
    int x;scanf("%d",&x);--x;

    int m=fact[x].size();
    REP(i,(1<<m)){
      int sum=1,c=__builtin_popcount(i);
      REP(j,m) if(i>>j&1) sum*=fact[x][j];

      if(mark[x]){
        --cnt[sum];
        res-=cnt[sum]*((c&1)?-1:1);
      }else{
        res+=cnt[sum]*((c&1)?-1:1);
        ++cnt[sum];
      }
    }
    mark[x]^=1;
    printL(res);
    putchar('\n');
  }
  return 0;
}