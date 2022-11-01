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
typedef unsigned long long int lint;
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
int m;

typedef bitset<2005> B;

int n;
B basis[2005];

B eff[2005];
int h[2005];

B getit(){
  string s;cin>>s;
  reverse(ALL(s));
  B res;res.reset();

  vector<lint> X,Y;
  for(int i=0;i<s.size();i+=9){
    lint cur=0;
    for(int j=8;j>=0;--j) cur=cur*10+(i+j<s.size()?s[i+j]-'0':0);
    X.pb(cur);
  }


  int pos=0;
  lint e9=1000000000,mod=(1<<30);
  while(!X.empty()){
    Y.clear();
    lint cur=0;
    for(int i=X.size()-1;i>=0;--i){
      cur=cur*e9+X[i];
      Y.pb(cur/mod);
      cur%=mod;
    }
    REP(i,30) if(cur>>i&1){
      res.set(i+pos);
    }
    pos+=30;
    reverse(ALL(Y));
    while(!Y.empty() && Y.back()==0) Y.pop_back();
    X=Y;
  }
  return res;
}
int main(){
  cin>>m;
  REP(t,m){
    B cur=getit();

    eff[n].reset();

    eff[n].set(t);
    REP(i,n) if(cur.test(h[i])){
      cur^=basis[i];
      eff[n]^=eff[i];
    }
    if(cur.any()){
      basis[n]=cur;
      REP(i,2000) if(cur.test(i)){
        h[n]=i;
        break;
      }
      ++n;
      puts("0");
    }else{
      vector<int> res;
      REP(i,t) if(eff[n].test(i)){
        res.pb(i);
      }
      printf("%d",(int)res.size());
      REP(i,res.size()) printf(" %d",res[i]);
      putchar('\n');
    }
  }


  return 0;
}