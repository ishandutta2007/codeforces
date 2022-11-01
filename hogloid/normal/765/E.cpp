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
int n;
vector<int> g[200005];

int len[200005];
bool mrg[200005];

bool mrgP[200005];
int lenP[200005];

int par[200005];
void dfs(int v,int p){
  len[v]=0;
  par[v]=p;
  for(auto to:g[v]){
    if(to==p) continue;
    dfs(to,v);
    chmax(len[v],len[to]+1);
  }
  mrg[v]=true;
  for(auto to:g[v]){
    if(to==p) continue;
    if(len[v]!=len[to]+1 || !mrg[to]) mrg[v]=false;
  }
}
void dfs4(int v,int p){
  pi maxi={0,-1},sec={0,-1};
  if(v) maxi={lenP[v],-1};
  for(auto to:g[v]){
    if(to==p) continue;
    int val=len[to]+1;
    pi p={val,to};
    if(p>maxi){
      sec=maxi;
      maxi=p;
    }else if(p>sec){
      sec=p;
    }
  }
  dump(v);dump(maxi);dump(sec);
  for(auto to:g[v]){
    if(to==p) continue;
    dump(to);dump(maxi);dump(sec);
    if(to==maxi.sc){
      lenP[to]=sec.fr+1;
    }else{
      lenP[to]=maxi.fr+1;
    }
    dfs4(to,v);
  }
}
void dfs2(int v,int p){
  map<int,int> lencnt;
  for(auto to:g[v]){
    if(to==p) continue;
    lencnt[len[to]]++;
  }
  if(~p){
    lencnt[lenP[v]-1]++;
  }
  if(lencnt.size()>2){
    return;
  }
  if(lencnt.size()==2){
    auto it=lencnt.begin();
    pi A=*it;++it;
    pi B=*it;
    REP(t,2){
      if(A.sc==1){
        int wlen=A.fr,othlen=B.fr;
        bool fail=false;
        for(auto to:g[v]){
          if(to==p) continue;
          if(len[to]!=wlen && !mrg[to]) fail=true;
        }
        if(!fail){
          for(auto to:g[v]){
            if(to==p) continue;
            if(len[to]==wlen){
              mrgP[to]=1;
              dump(to);
              dump(lenP[to]);
              assert(lenP[to]==othlen+2);
              lenP[to]=othlen+2;
              dfs2(to,v);
            }
          }
        }
      }
      swap(A,B);
    }
  }else if(p==-1 || mrgP[v]){
    int cnt=0,ng=0,ngwho=-1;
    for(auto to:g[v]){
      if(to==p) continue;
      if(mrg[to]) ++cnt;
      else{
        ++ng;
        ngwho=to;
      }
    }
    for(auto to:g[v]){
      if(to==p) continue;
      if(ng==0 || to==ngwho){
        mrgP[to]=1;
        dfs2(to,v);
      }
    }
  }
}


map<pi,bool> ok;
map<pi,int> len2;


int main(){
  cin>>n;
  REP(i,n-1){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0,-1);
  dfs4(0,-1);
  debug(lenP,lenP+n);
  dfs2(0,-1);

  REP(i,n) if(i!=0){
    ok[{par[i],i}]=mrg[i];
    len2[{par[i],i}]=len[i];
    ok[{i,par[i]}]=mrgP[i];
    len2[{i,par[i]}]=lenP[i]-1;
  }
  debug(par,par+n);

  int res=INF;
  REP(i,n){
    map<int,vector<int> >vs;
    for(auto to:g[i]){
      int len=len2[mp(i,to)]+1;
      vs[len].pb(to);
    }
    bool fail=false;
    int sum=0;
    for(auto& E:vs){
      const vector<int>& A=E.sc;
      for(auto v:A) if(!ok[{i,v}]) fail=true;
      sum+=E.fr;
    }
    while(sum%2==0) sum/=2;
    if(vs.size()<=2 && !fail) chmin(res,sum);
  }
  if(res==INF) res=-1;
  dump(res);
  while(res%2==0) res/=2;
  cout<<res<<endl;
  return 0;
}