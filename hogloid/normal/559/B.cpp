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
char s[200005],s2[200005];
int n;
void fix(char* s,int l,int r){
  int len=r-l;
  if(len&1) return;
  int md=(l+r)>>1;
  fix(s,l,md);
  fix(s,md,r);

  bool sign=false;
  REP(i,md-l) if(s[l+i]!=s[md+i]){
    if(s[l+i]>s[md+i]) sign=true;
    break;
  }
  if(sign){
    REP(i,md-l) swap(s[l+i],s[md+i]);
  }
}

int main(){
  scanf("%s%s",s,s2);
  n=strlen(s);
  fix(s,0,n);
  fix(s2,0,n);
  REP(i,n) if(s[i]!=s2[i]){
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}