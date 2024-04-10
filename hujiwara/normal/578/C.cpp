#include <bits/stdc++.h>
using namespace std;

double cal(int n,int *a,double x)
{
  double ret=0,t1=0,t2=0;
  for(int i=0;i<n;i++){
    t1+=a[i]-x;
    t2+=a[i]-x;
    t1=max(0.,t1);
    t2=min(0.,t2);
    ret=max(ret,t1);
    ret=max(ret,-t2);
  }
  return ret;
}

int main()
{
  int n;
  scanf("%d",&n);
  static int a[200000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  double l=-10001,r=10001,ans;
  for(int t=0;t<100;t++){
    double d1=(2*l+r)/3,d2=(l+2*r)/3;
    double e1=cal(n,a,d1),e2=cal(n,a,d2);
    if(e1<=e2){
      r=d2;
      ans=e1;
    }
    else{
      l=d1;
      ans=e2;
    }
  }
  printf("%.9lf\n",ans);
  return 0;
}