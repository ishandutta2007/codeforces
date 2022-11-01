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
char buf[2505][2505],rev[2505][2505];
int K;
int h,w;


int lef[2505][10],rig[2505][10],cl[2505],cr[2505];

void mergee(int a[10],int b[10],int cb,bool flag){
  int nxt[10];
  int cn=0;
  int i=0,j=0;
  while(cn<=K+1 && (i<K+2 || j<cb)){
    if(i<K+2 && (j==cb || ((a[i]<b[j])^flag) )) nxt[cn++]=a[i++];
    else nxt[cn++]=b[j++];
  }
  REP(i,10) a[i]=nxt[i];
}

lint doit(int t,int l,int b,int r,int div,char buf[2505][2505]){
  if(t==b || l==r) return 0;
  REPN(i,b,t){
    cl[i]=cr[i]=0;
    for(int j=div-1;j>=l && cl[i]<=K;--j) if(buf[i][j]=='1') lef[i][cl[i]++]=j;
    for(int j=div;j<r && cr[i]<=K;++j) if(buf[i][j]=='1') rig[i][cr[i]++]=j;
  }

  int L[10],R[10];
  lint res=0;
  REPN(i,b,t){
    REP(j,10){
      R[j]=r;
      L[j]=l-1;
    }
    R[0]=div;
    L[0]=div-1;
    for(int j=i;j<b;++j){
      mergee(R,rig[j],cr[j],false);
      mergee(L,lef[j],cl[j],true);

      REP(k2,K+1){
        res+=(R[k2+1]-R[k2])*(L[K-k2]-L[K-k2+1]);
      }
    }
  }
  return res;
}
lint solve(int t,int l,int b,int r){
  if(t==b || l==r) return 0;
  if(r-l==1 && b-t==1){
    if(buf[t][l]==K+'0') return 1;
    return 0;
  }
  int mid1=(l+r)/2;
  lint res=doit(t,l,b,r,mid1,buf);
  int mid2=(t+b)/2;
//  res+=doit(t,l,b,mid1,mid2,rev);
//  res+=doit(t,mid1,b,r,mdi2,rev);
  res+=doit(l,t,mid1,b,mid2,rev);
  res+=doit(mid1,t,r,b,mid2,rev);

  res+=solve(t,l,mid2,mid1);
  res+=solve(t,mid1,mid2,r);
  res+=solve(mid2,l,b,mid1);
  res+=solve(mid2,mid1,b,r);
  return res;
}

  
int main(){
  cin>>h>>w>>K;
  REP(i,h) scanf("%s",buf[i]);
  REP(i,h) REP(j,w) rev[j][i]=buf[i][j];

  lint res=solve(0,0,h,w);

  cout<<res<<endl;

  return 0;
}