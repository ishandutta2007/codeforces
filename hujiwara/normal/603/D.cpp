#include <bits/stdc++.h>
using namespace std;
typedef complex<double> point;
const double EPS=1e-8;
const double Pi=3.14159265359;

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

double len(point P)
{
  return sqrt(ip(P,P));
}

point cross_point(point P1,point P2,point P3,point P4)
{
  double r=op(P3-P1,P2-P1)/op(P4-P3,P2-P1);
  return P3-r*(P4-P3);
}

int main()
{
  int n;
  scanf("%d",&n);
  point P[2000];
  for(int i=0;i<n;i++){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    P[i]=point(a*c/(a*a+b*b),b*c/(a*a+b*b));
    P[i]*=point(cos(2.),sin(2.));
  }
  long long ans=0;
  bool F=0;
  for(int i=0;i<n;i++){
    double ang[2000];
    int N=0;
    int c=0;
    for(int j=0;j<n;j++){
      if(i==j){
	continue;
      }
      if(dis(P[i],P[j])<EPS){
	c++;
	continue;
      }
      double sg;
      if(abs(P[j].imag()-P[i].imag())>EPS){
	sg=(P[j].imag()>P[i].imag()?1:-1);
      }
      else{
	sg=(P[j].real()>P[i].real()?1:-1);
      }
      ang[N]=atan2(sg*(P[j].imag()-P[i].imag()),sg*(P[j].real()-P[i].real()));
      //printf("%d %d %lf\n",i,j,ang[N]);
      //printf("%d %d %lf\n",i,j,ang[N]);
      N++;
    }
    sort(ang,ang+N);
    for(int k=0;k<N;){
      int t=1;
      while(k+t<N&&ang[k+t]<=ang[k]+0.0001*EPS){
	t++;
      }
      ans+=t*(t-1)/2;
      k+=t;
    }
    ans+=c*(n-1-c)+c*(c-1)/2;
  }
  printf("%lld\n",ans/3);
  return 0;
}