#include <cstdio>
#include <cmath>
#define PI 3.1415926535898

int main()
{
  double l1,l2,l3;
  scanf("%lf%lf%lf",&l1,&l2,&l3);
  printf("%.10f\n",sqrt(3)/4*sqrt(2./3)/3*l1*l1*l1+1./3/sqrt(2)*l2*l2*l2+5./4/tan(PI/5)*sqrt(1.-1./4/sin(PI/5)/sin(PI/5))/3*l3*l3*l3);
  return 0;
}