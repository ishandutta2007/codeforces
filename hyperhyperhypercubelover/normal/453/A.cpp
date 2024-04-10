#include<cstdio>

double f(double x,int y)
{
  if(y==0)return 1;
  if(y&1)return f(x,y-1)*x;
  x=f(x,y>>1);
  return x*x;
}

int main()
{
  double res=0;
  int i,a,b;
  scanf("%d%d",&a,&b);
  for(i=1;i<=a;i++)
  {
    res+=i*(f(1.*i/a,b)-f(1.*(i-1)/a,b));
  }
  printf("%.12lf",res);
}