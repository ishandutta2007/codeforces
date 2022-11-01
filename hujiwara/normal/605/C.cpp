#include <bits/stdc++.h>

using namespace std;

const int MAXN=100000;
const double EPS=1e-8,INF=1e9;
typedef complex<double> point;


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

void convex_hell(point *P,int n,point *H,int &N)
{
  sort(P,P+n);
  int v1[MAXN],v2[MAXN];
  v1[0]=v2[0]=0;
  int m1=1,m2=1;
  for(int i=1;i<n;i++){
    while(m1>=2&&ccw(P[v1[m1-2]],P[v1[m1-1]],P[i])<=EPS){
      m1--;
    }
    v1[m1]=i;
    m1++;
    while(m2>=2&&ccw(P[v2[m2-2]],P[v2[m2-1]],P[i])>=-EPS){
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


int main()
{
  int n;
  double p,q;
  scanf("%d%lf%lf",&n,&p,&q);
  double a[MAXN],b[MAXN];
  for(int i=0;i<n;i++){
    scanf("%lf%lf",a+i,b+i);
  }
  double ans=INF;
  for(int i=0;i<n;i++){
    ans=min(ans,max(p/a[i],q/b[i]));
  }
  point O(0,0),T(p,q);
  static point P[MAXN];
  for(int i=0;i<n;i++){
    P[i]=point(a[i],b[i]);
  }
  static point H[MAXN];
  int N;
  convex_hell(P,n,H,N);
  for(int i=0;i<N;i++){
    point P1=H[i],P2=H[(i+1)%N];
    if(ccw(O,T,P1)*ccw(O,T,P2)<-EPS){
      point Q=cross_point(O,T,P1,P2);
      ans=min(ans,len(T)/len(Q));
    }
  }
  printf("%.9lf\n",ans);
  return 0;
}