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

int n,m;
char s[1000005],t[1000005];

int nxt[1000005],nxt2[1000005];

int conv[1000005],tmp[1000005];

void doit(char* s,int* conv,int k){
  REP(i,n) t[conv[i]]=s[i];
  REP(i,n) s[i]=t[(i+k)%n];
}

int main(){
  scanf("%s",s);
  n=strlen(s);
  cin>>m;

  REP(hoge,m){
    int k,d;scanf("%d%d",&k,&d);
    int cnt=0;
    REP(i,d) for(int j=i;j<k;j+=d) nxt[j]=(cnt-1+n)%n,++cnt;
    REPN(i,n,k) nxt[i]=i-1;
    REP(i,n) conv[i]=i;

    REP(i,20){
      if((n+1-k)>>i&1){
        REP(j,n) tmp[j]=nxt[conv[j]];
        REP(j,n) conv[j]=tmp[j];
      }
      REP(j,n) nxt2[j]=nxt[nxt[j]];
      REP(j,n) nxt[j]=nxt2[j];
    }

    doit(s,conv,k-1);
    printf("%s\n",s);
  }


  return 0;
}