#include <bits/stdc++.h>
using namespace std;
static int segm[51][1<<17]={0},segp[51][1<<17]={0};

void segplus0(int X,int i,int j,int k,int a,int b,int v)
{
  if(a<=j&&k<=b){
    segp[X][i]+=v;
    segm[X][i]+=v;
  }
  else if(a<k&&j<b){
    segplus0(X,2*i,j,(j+k)/2,a,b,v);
    segplus0(X,2*i+1,(j+k)/2,k,a,b,v);
    segm[X][i]=max(segm[X][2*i],segm[X][2*i+1])+segp[X][i];
  }
}

void segplus(int X,int a,int b,int v)
{
  segplus0(X,1,0,1<<16,a,b,v);
}


int main()
{
  int n,K;
  scanf("%d%d",&n,&K);
  static int a[35000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
    a[i]--;
  }
  static int b[35000];
  for(int i=0;i<n;i++)b[i]=-1;
  segplus(1,0,1,1);
  b[a[0]]=0;
  for(int i=1;i<n;i++){
    for(int j=K;j>=1;j--){
      if(j<K){
	int v=segm[j][1];
	//printf("%d %d %d\n",i,j,v);
	segplus(j+1,i,i+1,v+1);
      }
	  //printf("%d %d\n",b[a[i]]+1,i);
      segplus(j,b[a[i]]+1,i,1);
    }
    b[a[i]]=i;
  }
  printf("%d\n",segm[K][1]);
  return 0;
}