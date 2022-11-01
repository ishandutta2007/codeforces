#include <bits/stdc++.h>
using namespace std;

typedef long long cood;
const cood EPS=0;
typedef complex<cood> point;
const point IU=point((cood)0,(cood)1);
namespace std{
  bool operator<(point P1,point P2){
    return abs(P1.real()-P2.real())>EPS?P1.real()<P2.real():P1.imag()<P2.imag();
  }
  bool operator>(point P1,point P2){
    return abs(P1.real()-P2.real())>EPS?P1.real()>P2.real():P1.imag()>P2.imag();
  } 
}
cood ep(point P1,point P2){return imag((conj(P1)*P2));}
cood ip(point P1,point P2){return real((conj(P1)*P2));}
int sign(cood s){return abs(s)<=EPS?0:s>0?1:-1;}
int ccw(point P0,point P1,point P2){return sign(ep(P1-P0,P2-P0));}

const int MAXN=100010;


void convex_hull(point *P,int n,point *H,int &N)
{
  sort(P,P+n);
  static int v1[MAXN],v2[MAXN];
  v1[0]=v2[0]=0;
  int m1=1,m2=1;
  for(int i=1;i<n;i++){
    while(m1>=2&&ccw(P[v1[m1-2]],P[v1[m1-1]],P[i])<=0){
      m1--;
    }
    v1[m1]=i;
    m1++;
    while(m2>=2&&ccw(P[v2[m2-2]],P[v2[m2-1]],P[i])>=0){
      m2--;
    }
    v2[m2]=i;
    m2++;
  }
  N=m1+m2-2;
  for(int i=0;i<m1-1;i++){
    H[i]=P[v1[i]];
  }
  for(int i=0;i<m2-1;i++){
    H[m1-1+i]=P[v2[m2-1-i]];
  }
}

int Booth(vector<cood> S)
{
  int N=S.size();
  vector<int> f(N,-1);
  int k=0;
  for(int j=1;j<N;j++){
    cood sj=S[j];
    int i=f[j-k-1];
    while(i!=-1&&sj!=S[(k+i+1)%N]){
      if(sj<S[(k+i+1)%N])
	k=j-i-1;
      i=f[i];
    }
    if(sj!=S[(k+i+1)%N]){
      if(sj<S[k])
	k=j;
      f[j-k]=-1;
    }
    else
      f[j-k]=i+1;
  }
  return k;
}

vector<cood> cal(point *P,int n)
{
  static point H[MAXN];
  int N;
  convex_hull(P,n,H,N);
  point G=0ll;
  for(int i=0;i<N;i++){
    G+=H[i];
  }
  vector<cood> T(2*N);
  for(int i=0;i<N;i++){
    T[2*i]=ip((cood)N*H[i]-G,(cood)N*H[i]-G);
    int j=(i+1)%N;
    T[2*i+1]=ep((cood)N*H[i]-G,(cood)N*H[j]-G);
  }
  int k=Booth(T);
  vector<cood> ret(2*N);
  for(int i=0;i<2*N;i++){
    ret[i]=T[(k+i)%(2*N)];
    //printf("%lld\n",(long long)T[i]);
  }
  return ret;
}

point scanpt()
{
  long long a,b;
  scanf("%lld%lld",&a,&b);
  return point((cood)a,(cood)b);
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static point P1[MAXN],P2[MAXN];
  for(int i=0;i<n;i++){
    P1[i]=scanpt();
  }
  for(int i=0;i<m;i++){
    P2[i]=scanpt();
  }
  vector<cood> ret1=cal(P1,n),ret2=cal(P2,m);
  bool F=1;
  if(ret1.size()!=ret2.size()){
    F=0;
  }
  else{
    for(int i=0;i<ret1.size();i++){
      if(ret1[i]!=ret2[i]){
	F=0;
      }
    }
  }
  puts(F?"YES":"NO");
  return 0;
}