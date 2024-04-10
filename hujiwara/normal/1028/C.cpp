#include <bits/stdc++.h>
using namespace std;

const int MN=200000,INF=1100000000;

int main()
{
  int n;
  scanf("%d",&n);
  static int x1[MN],y1[MN],x2[MN],y2[MN];
  for(int i=0;i<n;i++){
    scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
  }
  static int x1l[MN],y1l[MN],x2l[MN],y2l[MN];
  x1l[0]=y1l[0]=-INF;
  x2l[0]=y2l[0]=INF;
  for(int i=0;i<n;i++){
    x1l[i+1]=max(x1l[i],x1[i]);
    y1l[i+1]=max(y1l[i],y1[i]);
    x2l[i+1]=min(x2l[i],x2[i]);
    y2l[i+1]=min(y2l[i],y2[i]);
  }
  static int x1r[MN],y1r[MN],x2r[MN],y2r[MN];
  x1r[n]=y1r[n]=-INF;
  x2r[n]=y2r[n]=INF;
  for(int i=n-1;i>=0;i--){
    x1r[i]=max(x1r[i+1],x1[i]);
    y1r[i]=max(y1r[i+1],y1[i]);
    x2r[i]=min(x2r[i+1],x2[i]);
    y2r[i]=min(y2r[i+1],y2[i]);
  }
  for(int i=0;i<n;i++){
    int X1=max(x1l[i],x1r[i+1]);
    int Y1=max(y1l[i],y1r[i+1]);
    int X2=min(x2l[i],x2r[i+1]);
    int Y2=min(y2l[i],y2r[i+1]);
    if(X1<=X2&&Y1<=Y2){
      printf("%d %d\n",X1,Y1);
      break;
    }
  }
  return 0;
}