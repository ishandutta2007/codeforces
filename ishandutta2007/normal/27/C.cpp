#include<cstdio>
#include<iostream>
#include<algorithm>
int a[1000001];
using namespace std;
int main(){
  int i,j,k,n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  int mode=0;
  for(int i=1;i<n;i++)
  { if(a[i]==a[i-1])continue;
    if(a[i]>a[i-1]){mode=1;break;}//-1 indicates nondecreasing
    else if(a[i]<a[i-1]){mode=-1;break;}//1 indicates nonincreasing
  }
//  cout<<mode<<endl;
  if(mode==1){//non decreasing
    int maxsofar=a[1];
    for(int i=2;i<n;i++)
    {
      if(a[i]<maxsofar)
      {
        printf("3\n1 %d %d\n",i,i+1);
  //      system("PAUSE");
        return 0;
      }
      maxsofar=a[i];
    }
  }
  else if(mode==-1){//nonincreasing
    int minsofar=a[1];
    for(int i=2;i<n;i++)
    {
      if(a[i]>minsofar)
        {
          printf("3\n1 %d %d\n",i,i+1);
    //      system("PAUSE");
          return 0;
        }
      minsofar=a[i];
    }
  }
  printf("0\n");
//  system("PAUSE");
  return 0;
}