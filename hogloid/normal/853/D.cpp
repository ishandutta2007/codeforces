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


const int INF=7e8;
int n;
int ar[300005];

int sum[300005];

vector<int> Tpos,Opos;

int solve1(int a,int b,int A,int B){
  if(B==INF) return INF;
  if(b==INF) return INF;

  int Tlen=B-b;

  int tmp=sum[b]*1000;
  int pt=sum[b]*100;
  int Trange=Tlen*2000;
  tmp+=max(0,Trange-pt);
  pt-=min(Trange,pt);
  tmp+=1000;
  pt+=100;
  int rest=(sum[n]-sum[B+1])*1000;
  tmp+=max(0,rest-pt);

  return tmp;
}


int solve2(int a,int b,int A,int B){
  if(a==-1) return INF;
  if(A==-1) return INF;
  int Tlen=a-A;
  int tmp=sum[A]*1000;
  int pt=sum[A]*100;
  tmp+=max(0,1000-pt);
  pt-=min(pt,1000);
  int Trange=Tlen*2000;

  tmp+=Trange;
  pt+=Tlen*200;

  int rest=(sum[n]-sum[a+1])*1000;
  tmp+=max(0,rest-pt);
  return tmp;
}
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>n;
  Opos.pb(-1);
  Tpos.pb(-1);
  REP(i,n){
    int a;scanf("%d",&a);
    ar[i]=a/1000;
    if(ar[i]==1) Opos.pb(i);
    else Tpos.pb(i);
  }
  Tpos.pb(INF);
  Opos.pb(INF);
  REP(i,n) sum[i+1]=sum[i]+ar[i];

  int res=INF;
  REP(i,n+1){
    int tmp=sum[i]*1000;
    int pt=sum[i]*100;
    int rest=(sum[n]-sum[i])*1000;
    tmp+=max(0,rest-pt);
    chmin(res,tmp);
  }

  int prev=res;

  REP(i,(int)Tpos.size()-1){
    int a=Tpos[i],b=Tpos[i+1];
    int B=*lower_bound(ALL(Opos),b);
    int A=*(--lower_bound(ALL(Opos),a));

    int X=solve1(a,b,A,B);
    int Y=solve2(a,b,A,B);
    chmin(res,X);
    chmin(res,Y);
  }

//  assert(prev!=res);

  cout<<res<<endl;
  return 0;
}