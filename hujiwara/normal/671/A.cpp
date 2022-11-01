#include <bits/stdc++.h>
using namespace std;
typedef complex<double> point;
const double EPS=1e-8,INF=1e12;


namespace std{
  bool operator<(point P1,point P2)
  {
    return abs(P1.real()-P2.real())>EPS?P1.real()<P2.real():P1.imag()<P2.imag();
  }
  bool operator>(point P1,point P2)
  {
    return abs(P1.real()-P2.real())>EPS?P1.real()>P2.real():P1.imag()>P2.imag();
  } 
}

double op(point P1,point P2)
{
  return imag((conj(P1)*P2));
}

double ip(point P1,point P2)
{
  return real((conj(P1)*P2));
}

double ccw(point P0,point P1,point P2)
{
  return op(P1-P0,P2-P0);
}

double dis(point P1,point P2)
{
  return sqrt(ip(P1-P2,P1-P2));
}

int main()
{
  double ax,ay,bx,by,tx,ty;
  scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty);
  point A(ax,ay),B(bx,by),T(tx,ty);
  int n;
  scanf("%d",&n);
  double S=0,am1=-INF,am2=-INF,bm1=-INF,bm2=-INF;
  int i1=-1,i2=-1;
  for(int i=0;i<n;i++){
    double x,y;
    scanf("%lf%lf",&x,&y);
    point P(x,y);
    double d=dis(P,T);
    S+=2*d;
    double da=d-dis(A,P),db=d-dis(B,P);
    if(i1==-1||am1<da){
      am2=am1;
      am1=da;
      i1=i;
    }
    else if(am2<da){
      am2=da;
    }
    if(i2==-1||bm1<db){
      bm2=bm1;
      bm1=db;
      i2=i;
    }
    else if(bm2<db){
      bm2=db;
    }
  }
  double S1=min(S-am1,S-bm1);
  if(i1!=i2){
    S-=am1+bm1;
  }
  else{
    S-=max(am1+bm2,am2+bm1);
  }
  S=min(S,S1);
  printf("%.9lf\n",S);
  return 0;
}