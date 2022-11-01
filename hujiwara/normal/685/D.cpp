#include <bits/stdc++.h>
using namespace std;

struct eve{
  int y,x1,x2,s;
};

bool operator<(eve e1,eve e2)
{
  return e1.y<e2.y;
}

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  static int x[100000],y[100000];
  for(int i=0;i<n;i++){
    scanf("%d%d",x+i,y+i);
  }
  static int X[200000];
  for(int i=0;i<n;i++){
    X[i]=x[i];
    X[i+n]=x[i]+k;
  }
  sort(X,X+2*n);
  int N=0;
  for(int i=0;i<2*n;i++){
    if(i==0||X[i-1]<X[i]){
      X[N]=X[i];
      N++;
    }
  }
  static eve P[200000];
  for(int i=0;i<n;i++){
    int x1=lower_bound(X,X+N,x[i])-X,x2=lower_bound(X,X+N,x[i]+k)-X;
    P[i].y=y[i],P[i].x1=x1,P[i].x2=x2,P[i].s=1;
    P[i+n].y=y[i]+k,P[i+n].x1=x1,P[i+n].x2=x2,P[i+n].s=-1;
  }
  sort(P,P+2*n);
  static int D[200000]={0},T[200000]={0};
  static long long ans[100001]={0};
  for(int i=0;i<2*n;i++){
    //printf("%d %d %d %d\n",P[i].y,P[i].x1,P[i].x2,P[i].s);
    for(int j=P[i].x1;j<P[i].x2;j++){
      if(D[j]>0){
	ans[D[j]]+=(long long)(P[i].y-T[j])*(X[j+1]-X[j]);
      }
      T[j]=P[i].y;
      D[j]+=P[i].s;
    }
  }
  for(int i=1;i<=n;i++){
    printf("%lld%c",ans[i],i==n?'\n':' ');
  }
  return 0;
}