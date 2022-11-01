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

const lint INF=1.1e12;
int n,m,K;
const lint INF2=1e18;
const int M=1000003;
lint evmin[100005];
lint pcost[1000005],scost[1000005];

pair<int,pi> in[100005],out[100005];
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>n>>m>>K;

  int c1=0,c2=0;
  REP(i,m){
    int d,f,t,c;
    scanf("%d%d%d%d",&d,&f,&t,&c);
    --f;--t;
    if(f==-1){
      out[c2++]={d,{t,c}};
    }else{
      in[c1++]={d,{f,c}};
    }
  }

  REP(i,n) evmin[i]=INF;

  sort(in,in+c1);

  lint sum=INF*n;
  int i=0;
  for(int D=0;D<=M;++D){
    pcost[D]=sum;
    while(i<c1){
      int d=in[i].fr,who=in[i].sc.fr,c=in[i].sc.sc;
      if(d>D) break;
      if(evmin[who]>c){
        sum-=evmin[who];
        sum+=c;
        evmin[who]=c;
      }
      ++i;
    }
  }

  sort(out,out+c2);
  reverse(out,out+c2);
  REP(i,n) evmin[i]=INF;

  i=0;
  sum=INF*n;
  for(int D=M;D>=0;--D){
    scost[D]=sum;
    while(i<c2){
      int d=out[i].fr,who=out[i].sc.fr,c=out[i].sc.sc;
      if(d<D) break;
      if(evmin[who]>c){
        sum-=evmin[who];
        sum+=c;
        evmin[who]=c;
      }
      ++i;
    }
  }

  REP(i,M) chmin(pcost[i+1],pcost[i]);
  for(int i=M-1;i>=0;--i) chmin(scost[i],scost[i+1]);

  lint res=INF2;
  REP(i,M) if(i+K-1<=M){
    chmin(res,pcost[i]+scost[i+K-1]);
  }
  if(res>=INF) res=-1;
  cout<<res<<endl;
  return 0;
}