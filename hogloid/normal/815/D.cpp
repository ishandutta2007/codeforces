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
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
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
int n,P,Q,R;
pair<pi,pi> ar[500005];
pair<pi,int> br[500005];

pi cr[500005],dr[500005];
int m;
lint area=0;
lint sumY[500005];
lint getY(int y){
  int p=lower_bound(cr,cr+m,mp(y,INF))-cr;
  lint res=sumY[p]+(R-cr[p].sc)*(lint)(y-(p==0?0:cr[p-1].fr));
  return res;
}
lint sumZ[500005];
bool cmp(pi a,pi b){
  return mp(a.sc,a.fr)<mp(b.sc,b.fr);
}
lint getZ(int z){
  int p=lower_bound(dr,dr+m,mp(INF,z),cmp)-dr;
  lint res=sumZ[p]+(Q-dr[p].fr)*(lint)(z-(p==0?0:dr[p-1].sc));
  return res;
}
bool below(int y,int z){
  int p=lower_bound(cr,cr+m,mp(y,INF))-cr;
  if(p==m || cr[p].sc<=z) return true;
  return false;
}
bool mark[500005];
int main(){
  cin>>n>>P>>Q>>R;
  REP(i,n){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    ar[i]={{a,0},{b,c}};
  }
  sort(ar,ar+n);
  REP(i,n) ar[i].fr.sc=i;
  REP(i,n){
    br[i]={ar[i].sc,i};
  }
  sort(br,br+n);
  int evmax=0;
  for(int i=n-1;i>=0;--i){
    if(evmax<br[i].fr.sc){
      cr[m++]=br[i].fr;
      evmax=br[i].fr.sc;
      mark[br[i].sc]=1;
    }
  }
  REP(i,m) dr[i]=cr[i];
  reverse(cr,cr+m);
  {
    int p=m-1,lim=0;
    for(int y=Q;y>=1;--y){
      if(cr[p].fr==y){
        lim=cr[p].sc;
        --p;
      }
      area+=R-lim;
    }
  }
  dump(area);
  cr[m]=dr[m]={0,0};

  {
    REP(i,m){
      sumY[i+1]=sumY[i]+(R-cr[i].sc)*(lint)(cr[i].fr-(i==0?0:cr[i-1].fr));
    }
  }
  {
    REP(i,m){
      sumZ[i+1]=sumZ[i]+(Q-dr[i].fr)*(lint)(dr[i].sc-(i==0?0:dr[i-1].sc));
    }
  }
  int i=n-1;

  int mnY=0,mnZ=0;
  lint res=0;
  for(int x=P;x>=1;--x){
    while(ar[i].fr.fr==x){
      chmax(mnY,ar[i].sc.fr);
      chmax(mnZ,ar[i].sc.sc);
      --i;
    }
    if(!below(mnY,mnZ)){
      res+=area-getY(mnY)-getZ(mnZ);
    }else{
      res+=(Q-mnY)*(lint)(R-mnZ);
    }
  }
  cout<<res<<endl;

  return 0;
}