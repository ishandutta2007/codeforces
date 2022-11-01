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


template<lint mod>
struct Int_{
  unsigned x;
  unsigned mpow(Int_ a,unsigned k){
    Int_ res=1;
    while(k){
      if(k&1) res=res*a;
      a=a*a;
      k>>=1;
    }
    return res.x;
  }
  unsigned inverse(Int_ a){
    return mpow(a,mod-2);
  }
  Int_(): x(0) { }
  Int_(long long sig) {
    int sigt=sig%mod;
    if(sigt<0) sigt+=mod;
    x=sigt;
  }
  unsigned get() const { return (unsigned)x; }
  
  Int_ &operator+=(Int_ that) { if((x += that.x) >= mod) x -= mod; return *this; }
  Int_ &operator-=(Int_ that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
  Int_ &operator*=(Int_ that) { x = (unsigned long long)x * that.x % mod; return *this; }
  Int_ &operator=(Int_ that) { x=that.x; return *this;}
  Int_ &operator/=(Int_ that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
  bool operator==(Int_ that) const { return x==that.x; }
  bool operator!=(Int_ that) const { return x!=that.x; }

  Int_ operator-() const { return Int_(0)-Int_(*this);}
  Int_ operator+(Int_ that) const { return Int_(*this) += that; }
  Int_ operator-(Int_ that) const { return Int_(*this) -= that; }
  Int_ operator*(Int_ that) const { return Int_(*this) *= that; }
  Int_ operator/(Int_ that) const { return Int_(*this) /= that; }

};

namespace std{
  template<lint mod>
  ostream &operator <<(ostream& out,const Int_<mod>& a){
    out<<a.get();
    return out;
  }
  template<lint mod>
  istream &operator >>(istream& in,Int_<mod>& a){
    in>>a.x;
    return in;
  }
};

typedef Int_<1000000007> Int;

int n,m;
vector<int> cl[100005];

bool done_l[100005];
bool done_c[100005];
int gid(int p){
  return abs(p)-1;
}

Int stat[2];
vector<int> ltoc[100005];

vector<pair<pi,int> > adj[100005];
bool arb[100005];

vector<int> path;
vector<int> vs;

int po(int a){
  assert(a!=0);
  if(a>0) return 1;
  return 0;
}

void merge(Int* a,Int* b){
  Int tmp[2]={0};
  REP(i,2) REP(j,2) tmp[i^j]+=a[i]*b[j];
  a[0]=tmp[0];
  a[1]=tmp[1];
}

bool cycle(int v,int p){
  done_c[v]=1;
  vs.pb(v);
  for(auto e2:adj[v]){
    pi e=e2.fr;
    if(e2.sc==p) continue;
    if(done_c[e.fr]){
      path.pb(e.sc);
      return true;
    }
    path.pb(e.sc);
    return cycle(e.fr,e2.sc);
  }
  return false;
}

void do_cy(vector<int> path){
  Int dp[2][2][2][2]={0};
  dp[0][1][1][0]=1;
  dp[0][0][0][0]=1;
  int cur=0,nxt=1;
  REPN(i,path.size(),1){
    REP(j,2) REP(k,2) REP(s,2) if(dp[cur][j][k][s].x){
      Int val=dp[cur][j][k][s];
      REP(t,2){
        int vertex=((path[i-1]>>1&1)^k^1)|((path[i]&1)^t^1);

        dp[nxt][j][t][s^vertex]+=val;
      }
    }
    swap(cur,nxt);
    CLR(dp[nxt]);
  }

  Int tmp[2]={0};
  REP(j,2) REP(k,2) REP(s,2) if(dp[cur][j][k][s].x){
    Int val=dp[cur][j][k][s];
    int vertex=((path[0]&1)^j^1)|((path.back()>>1&1)^k^1);
    tmp[s^vertex]+=val;
  }
  merge(stat,tmp);
}

void do_lin(vector<int> path,bool free1,bool free2){
  Int dp[2][2][2]={0};
  REP(t,2){
    if(t==1 && !free1) continue;
    dp[0][1][(path[0]&1)|t]+=1;
    dp[0][0][((path[0]&1)^1)|t]+=1;
  }
  int cur=0,nxt=1;
  REPN(i,path.size(),1){
    REP(j,2) REP(s,2) if(dp[cur][j][s].x){
      Int val=dp[cur][j][s];
      REP(t,2){
        int vertex=((path[i-1]>>1&1)^j^1)|((path[i]&1)^t^1);
        dp[nxt][t][s^vertex]+=val;
      }
    }
    swap(cur,nxt);
    CLR(dp[nxt]);
  }
  Int tmp[2]={0};
  REP(j,2) REP(s,2) if(dp[cur][j][s].x){
    Int val=dp[cur][j][s];
    REP(t,2){
      if(t && !free2) continue;
      int vertex=((path.back()>>1&1)^j^1)|t;
      tmp[s^vertex]+=val;
    }
  }
  merge(stat,tmp);
}

int ispo(int c,int l){
  for(auto v:cl[c]){
    if(abs(v)==l+1) return po(v);
  }
  assert(false);
}
int main(){
  cin>>n>>m;
  stat[0]=1;
  stat[1]=0;
  REP(i,n){
    int k;scanf("%d",&k);
    cl[i].resize(k);
    REP(j,k){
      scanf("%d",&cl[i][j]);
      ltoc[gid(cl[i][j])].pb(i);
    }

    if(k==2 && abs(cl[i][0])==abs(cl[i][1])){
      if(cl[i][0]==cl[i][1]){
        Int tmp[2]={1,1};
        merge(stat,tmp);
      }else{
        Int tmp[2]={0,2};
        merge(stat,tmp);
      }
      done_l[gid(cl[i][0])]=1;
      done_c[i]=1;
    }
  }
  REP(i,m) if(!done_l[i]){
    if(ltoc[i].size()>1){
      int a=ltoc[i][0],b=ltoc[i][1];

      int A=ispo(a,i),B=ispo(b,i);
      adj[a].pb(mp(mp(b,A|(B<<1)),i));
      adj[b].pb(mp(mp(a,B|(A<<1)),i));
    }else if(ltoc[i].empty()==false){
      arb[ltoc[i][0]]=1;
    }else{
      Int tmp[2]={2,0};
      merge(stat,tmp);
    }
  }
  REP(i,n) if(!done_c[i] && adj[i].size()==1){
    path.clear();
    vs.clear();
    if(cycle(i,-1)){
      dump("FUGE");
      do_cy(path);
    }else{
      do_lin(path,arb[vs[0]],arb[vs.back()]);
    }
  }
  REP(i,n) if(!done_c[i] && adj[i].size()>1){
    path.clear();
    vs.clear();
    if(cycle(i,-1)){
      do_cy(path);
    }else{
      dump("HOGE");
      do_lin(path,arb[vs[0]],arb[vs.back()]);
    }
  }
  REP(i,n) if(!done_c[i]){
    dump(i);
    if(cl[i].size()==1){
      Int tmp[2]={1,1};
      merge(stat,tmp);
    }else{
      Int tmp[2]={1,3};
      merge(stat,tmp);
    }
  }

  Int res=stat[1];
  cout<<res<<endl;
  return 0;
}