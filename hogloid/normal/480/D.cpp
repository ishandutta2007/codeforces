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

int n,S;

struct pack{
  int in,out,w,s,v;
};
pack par[505];

bool cmp(const pack& a,const pack& b){
  return mp(a.in,-a.out)<mp(b.in,-b.out);
}

int tmp[1005][1005];

int dp[505][1005];

void renew(int i,int base){
  int lim=min(S,par[base].w+par[base].s);
  REP(j,lim){
    chmax(tmp[i][j+1],tmp[i][j]);
  }
}

void update(pack p,int id,int base){
  int l=p.in,r=p.out;
  renew(l,base);
  
  int lim=min(S,par[base].w+par[base].s);
  

  REPN(i,lim+1,par[base].w) if(tmp[l][i]>=0 && dp[id][i-par[base].w]>=0){
    chmax(tmp[r][i],tmp[l][i]+dp[id][i-par[base].w]);
  }
}
void bring(int i,int base){
  renew(i,base);
  int lim=min(S,par[base].w+par[base].s);
  REP(j,lim+1){
    chmax(tmp[i+1][j],tmp[i][j]);
  }
}



int main(){
  cin>>n>>S;
  REP(i,n){
    cin>>par[i].in>>par[i].out>>par[i].w>>par[i].s>>par[i].v;
  }
  par[n]=(pack){0,2*n,0,S+1,0};
  ++n;

  sort(par,par+n,cmp);
  memset(dp,-1,sizeof(dp));
  
  int res=0;
  for(int i=n-1;i>=0;--i){
    pack p=par[i];
    int l=par[i].in,r=par[i].out;

    REPN(j,r+1,l) REP(k,S+1) tmp[j][k]=-1;

    tmp[l][p.w]=p.v;
    renew(l,i);
    
    int cur=l;
    REPN(j,n,i+1){
      if(l<=par[j].in && par[j].out<=r){
        while(cur<par[j].in){
          bring(cur,i);
          ++cur;
        }
        update(par[j],j,i);
      }
    }
    while(cur<r){
      bring(cur,i);
      ++cur;
    }
    renew(r,i);

    int lim=min(S,p.w+p.s);
    REP(j,lim+1){
      dp[i][j]=tmp[r][j];
      chmax(res,tmp[r][j]);
    }

    REP(j,S) chmax(dp[i][j+1],dp[i][j]);
  }
  cout<<res<<endl;




  return 0;
}