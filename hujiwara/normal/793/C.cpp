#include <bits/stdc++.h>
using namespace std;

typedef complex<long long> point;

long long op(point P1,point P2)
{
  return imag((conj(P1)*P2));
}

long long ip(point P1,point P2)
{
  return real((conj(P1)*P2));
}
const long double INF=1e10,EPS=1e-11;

/*bool cal(point p,point V,point p1,point p2)
{
  long long o1=op(v,p1-p),o2=op(v,p2-p);
  if(!((o1>0&&o2<0)||(o1<0&&o2>0))){
    return 0;
  }
  }*/


int main()
{
  int n;
  scanf("%d",&n);
  long long x1[2],x2[2];
  scanf("%lld%lld%lld%lld",x1,x1+1,x2,x2+1);
  static long long X[2][100000],V[2][100000];
  for(int i=0;i<n;i++){
    scanf("%lld%lld%lld%lld",X[0]+i,X[1]+i,V[0]+i,V[1]+i);
  }
  long double M1=-INF,M2=INF;
  bool F=0;
  for(int b=0;b<2;b++){
    for(int i=0;i<n;i++){
      long double t1,t2;
      long long v=V[b][i];
      if(x1[b]<X[b][i]&&X[b][i]<x2[b]){
	t1=0;
      }
      else if(X[b][i]<=x1[b]&&v>0){
	t1=(long double)(x1[b]-X[b][i])/v;
      }
      else if(X[b][i]>=x2[b]&&v<0){
	t1=(long double)(x2[b]-X[b][i])/v;
      }
      else{
	F=1;
      }
      if(v>0){
	t2=(long double)(x2[b]-X[b][i])/v;
      }
      else if(v<0){
	t2=(long double)(x1[b]-X[b][i])/v;
      }
      else{
	t2=INF;
      }
      M1=max(M1,t1);
      M2=min(M2,t2);
    }
  }
  if(!F&&M1+EPS<M2){
    printf("%.8Lf\n",M1);
  }
  else{
    puts("-1");
  }
  return 0;
}