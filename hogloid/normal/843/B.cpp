
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


#ifdef DEB
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

//const int INF=5e8;

pi ar[50005];

int n,S,x;
int perm[50005];
const int M=300;
pi ask(int x){
#ifdef DEB
  return ar[x];
#else
  printf("? %d\n",x+1);
  fflush(stdout);
  int v,p;
  scanf("%d%d",&v,&p);
  if(p>=0) --p;
  return {v,p};
#endif
}

void answer(int p){
  printf("! %d\n",p);
  fflush(stdout);
  exit(0);
}
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif

  srand(time(NULL));
  cin>>n>>S>>x;
  --S;

#ifdef DEB
  REP(i,n){
    cin>>ar[i].fr>>ar[i].sc;
    if(ar[i].sc>=0) --ar[i].sc;
  }
#endif

  REP(i,n) perm[i]=i;

  random_shuffle(perm,perm+n);
  vector<int> cand;
  vector<pair<pi,int> > info;
  REP(i,min(n,M-1)) cand.pb(perm[i]);

  cand.pb(S);
  sort(ALL(cand));
  cand.erase(unique(ALL(cand)),cand.end());
  for(auto e:cand){
    info.pb({ask(e),e});
  }
  sort(ALL(info));
  int lastless=-1;
  REP(i,info.size()){
    if(info[i].fr.fr<x){
      lastless=i;
    }
  }
  if(lastless==-1){
    answer(ask(S).fr);
  }
  int cur=info[lastless].sc;
  while(cur!=-1){
    pi tmp=ask(cur);
    if(tmp.fr>=x){
      answer(tmp.fr);
    }else{
      cur=tmp.sc;
    }
  }
  answer(-1);

  return 0;
}