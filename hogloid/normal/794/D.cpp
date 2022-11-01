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

//const int INF=5e8;
int n,m;
vector<int> g[300005];
void ng(){
  puts("NO");
  exit(0);
}

int mark[300005],perm[300005];
vector<int> g2[300005];
vector<int> vs[300005];

bool done[300005];
int main(){
  cin>>n>>m;
  REP(i,m){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  if(m==n*(lint)(n-1)/2){
    puts("YES");
    REP(i,n) printf("%d\n",1);
    return 0;
  }

  REP(i,n){
    g[i].pb(i);
    sort(ALL(g[i]));
  }
  int cnt=0;
  REP(i,n) perm[i]=i;
  sort(perm,perm+n,[&](int a,int b){
    return g[a]<g[b];
  });
  REP(i,n){
    int j=i;
    while(g[perm[j]]==g[perm[i]]){
      mark[perm[j]]=cnt;
      ++j;
    }
    ++cnt;
    i=j-1;
  }
  REP(i,n) vs[mark[i]].pb(i);
  REP(i,n) for(auto to:g[i]) if(mark[i]!=mark[to]){
    g2[mark[i]].pb(mark[to]);
  }
  REP(i,cnt){
    sort(ALL(g2[i]));
    g2[i].erase(unique(ALL(g2[i])),g2[i].end());
  }
  if(cnt==1) ng();
  int A=-1,B=-1;
  REP(i,cnt){
    if(g2[i].size()==1){
      if(A==-1) A=i;
      else if(B==-1) B=i;
      else ng();
    }
    if(g2[i].size()>2) ng();
  }
  if(B==-1) ng();

  vector<int> perm2,rev(cnt);
  while(A!=B){
    done[A]=1;
    perm2.pb(A);
    for(auto to:g2[A]) if(!done[to]){
      A=to;
      break;
    }
  }
  perm2.pb(B);
  if(perm2.size()!=cnt) ng();
  REP(i,cnt) rev[perm2[i]]=i;
  REP(i,cnt){
    REP(d,2){
      if(i+d>=cnt) continue;
      for(auto v:vs[perm2[i]]) for(auto u:vs[perm2[i+d]]){
        if(binary_search(ALL(g[v]),u)==false) ng();
      }
    }
  }
  puts("YES");
  REP(i,n) printf("%d\n",rev[mark[i]]+1);
  return 0;
}