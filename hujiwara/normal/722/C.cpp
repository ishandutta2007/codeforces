#include <cstdio>
#include <algorithm>

using namespace std;

long long seg1[(1<<18)+1],seg2[(1<<18)+1],seg3[(1<<18)+1];
bool seg4[(1<<18)+1];

void dest(int i)
{
  int p=(1<<17)+i;
  seg1[p]=seg2[p]=seg3[p]=0;
  seg4[p]=0;
  p/=2;
  while(p>0){
    seg4[p]=(seg4[2*p]&&seg4[2*p+1]);
    seg1[p]=(seg4[2*p]?seg1[2*p]+seg1[2*p+1]:seg1[2*p]);
    seg2[p]=(seg4[2*p+1]?seg2[2*p]+seg2[2*p+1]:seg2[2*p+1]);
    seg3[p]=max(max(seg3[2*p],seg3[2*p+1]),seg2[2*p]+seg1[2*p+1]);
    p/=2;
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  static int a[1000000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  for(int i=0;i<(1<<17);i++){
    int p=(1<<17)+i;
    seg1[p]=seg2[p]=seg3[p]=(i<n?a[i]:0);
    seg4[p]=1;
  }
  for(int p=(1<<17)-1;p>0;p--){
    seg1[p]=seg2[p]=seg3[p]=seg3[2*p]+seg3[2*p+1];
    seg4[p]=1;
  }
  static int b[100000];
  for(int i=0;i<n;i++){
    scanf("%d",b+i);
    b[i]--;
  }
  for(int i=0;i<n;i++){
    dest(b[i]);
    printf("%I64d\n",seg3[1]);
  }
  return 0;
}