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

char s[100005];
int main(){
  scanf("%s",s);
  int n=strlen(s);

  int last;
  for(int i=n-1;i>=0;--i) if(s[i]=='#'){
    last=i;
    break;
  }


  bool fail=false;
  int high=0;
  vector<int> res;
  REP(i,n){
    if(s[i]=='(') ++high;
    else if(s[i]==')') --high;
    else --high;
    if(high<0) fail=true;
  }
  int tot=high;
  high=0;

  if(tot<0) fail=true;

  REP(i,n){
    if(s[i]=='(') ++high;
    else if(s[i]==')') --high;
    else{
      --high;
      if(i==last){
        high-=tot;
        res.pb(tot+1);
      }else res.pb(1);
    }
    if(high<0) fail=true;
  }
  if(fail) puts("-1");
  else{
    for(auto v:res) printf("%d\n",v);
  }

  return 0;
}