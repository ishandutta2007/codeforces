#include<cstdio>
#include<algorithm>
int a[100005];
int main(){
  int q;scanf("%d",&q);
  while(q--){int n;scanf("%d",&n);
  long long sum=0;int mx=-1000000000;
  for(int i=0;i<n;++i){scanf("%d",&a[i]);sum+=a[i];mx=std::max(mx,a[i]);}
  printf("%.10lf\n",(double)(sum-mx)/(n-1)+(double)mx);}
}