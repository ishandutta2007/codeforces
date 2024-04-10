#include <bits/stdc++.h>

using namespace std;

const int N=100000,BS=17;

int bitmax(int *bit,int i)
{
  int p=i,ret=0;
  while(p>0){
    ret=max(ret,bit[p]);
    p-=p&-p;
  }
  return ret;
}
void bitadd(int *bit,int i,int v)
{
  int p=i+1;
  while(p<1<<BS){
    bit[p]=max(bit[p],v);
    p+=p&-p;
  }
}


int main()
{
  int n;
  scanf("%d",&n);
  static int a[N],p[N];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
    a[i]--;
    p[a[i]]=i;
  }
  int ans=0;
  for(int i=0;i<n;){
    int t=1;
    while(i+t<n&&p[i+t]>p[i+t-1]){
      t++;
    }
    ans=max(ans,t);
    i+=t;
  }
  printf("%d\n",n-ans);
  return 0;
}