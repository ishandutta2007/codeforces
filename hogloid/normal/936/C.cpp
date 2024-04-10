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

int n;
string s,t;
bool same(string S,string T){
  sort(ALL(S));sort(ALL(T));
  return S==T;
}

int main(){
  cin>>n;
  cin>>s>>t;
  if(same(s,t)==false){
    puts("-1");
    return 0;
  }

  int L=n/2,R=n/2;//[L..R)
  int dir=1;
  vector<int> res;
  auto add=[&](int K){
    res.pb(n-K);
    string S=s.substr(K);reverse(ALL(S));
    S+=s.substr(0,K);
    s=S;
  };
  while(L>0 || R<n){
    int len=R-L;
    auto doit=[&](char c){
      int from=-1;
      REPN(i,n,len) if(s[i]==c){
        from=i;
        break;
      }
      assert(from!=-1);
      add(from+1);
      add(n-1-from+len);
      add(n-len);
    };
    if(dir==1){
      doit(t[R]);
      ++R;
    }else{
      doit(t[L-1]);
      --L;
    }
    dir^=1;
  }
  if(dir){
    add(0);
  }
  dump(s);
  cout<<res.size()<<endl;
  for(auto e:res) printf("%d\n",e);
  return 0;
}