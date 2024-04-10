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
typedef pair<lint,lint> pi;

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
const int B=1000001;
lint A;
bool table[1000005];
typedef vector<lint> vi;
vector<vector<int> >dp;
vi factor;
unordered_map<lint,int> conv;
vector<pi> prm;
vector<lint> facs[10005];
vector<lint> pzip;
int rec(int idx,int last){
  if(idx==0) return 1;
  if(last==pzip.size()) return 0;
  int& res=dp[idx][last];
  if(res!=-1) return res;
  res=rec(idx,last+1);
  for(auto e:facs[last]){
    if(factor[idx]%e==0) res+=rec(conv[factor[idx]/e],last+1);
  }
  return res;
}
lint root(lint p,int k){
  if(k==1) return p;
  int lb=1,ub=B;
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    lint tmp=p;
    bool over=false;
    REP(hoge,k){
      if(tmp%md) over=true;
      tmp/=md;
    }
    if(tmp>1 || (tmp==1 && over)) lb=md;
    else ub=md;
  }
  lint tmp=p;
  REP(hoge,k){
    if(tmp%ub) return -1;
    tmp/=ub;
  }
  if(tmp!=1) return -1;
  return ub;
}
bool isprime(lint a){
  if(a>B){
    for(lint i=2;i*i<=a;++i) if(a%i==0) return false;
    return true;
  }else{
    return table[a];
  }
}

int main(){
  memset(table,true,sizeof(table));
  table[0]=table[1]=0;
  for(int i=2;i*i<=1000003;++i) if(table[i]){
    for(int j=i*i;j<=1000003;j+=i) table[j]=0;
  }

  cin>>A;
  for(lint i=1;i*i<=A;++i) if(A%i==0){
    factor.pb(i);
    if(i*i!=A) factor.pb(A/i);
  }
  sort(ALL(factor));
  REP(i,factor.size()){
    lint p=factor[i]-1;
    conv[p+1]=i;
    pi ins=mp(-1,-1);
    if(p>=2){
      REPN(j,41,1){
        lint a=root(p,j);
        if(a>0 && isprime(a)){
          ins=mp(a,j);
          break;
        }
      }
    }
    if(ins.fr>=0){
      pzip.pb(ins.fr);
    }
    prm.pb(ins);
  }
  sort(ALL(pzip));
  pzip.erase(unique(ALL(pzip)),pzip.end());
  REP(i,prm.size()) if(prm[i].fr>=0){
    int a=lower_bound(ALL(pzip),prm[i].fr)-pzip.begin();
    facs[a].pb(factor[i]);
  }
  dump(factor.size());dump(prm.size());
  dp.resize(factor.size(),vector<int>(prm.size(),-1));
  int res=rec((int)factor.size()-1,0);
  cout<<res<<endl;
  return 0;
}