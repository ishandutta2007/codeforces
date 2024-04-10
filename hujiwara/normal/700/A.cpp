#include <cstdio>

int main()
{
  int n,k;
  double L,v1,v2;
  scanf("%d%lf%lf%lf%d",&n,&L,&v1,&v2,&k);
  int m=(n+k-1)/k;
  double l=0,r=L/v1;
  while(r-l>1e-9){
    double t=(l+r)/2,T=0,x=0;
    double v=(L-v1*t)/(v2-v1),vv=v*(v2-v1)/(v2+v1);
    if(v*m+(m-1)*vv<=t){
      r=t;
    }
    else{
      l=t;
    }
  }
  printf("%.9lf\n",(l+r)/2);
  return 0;
}