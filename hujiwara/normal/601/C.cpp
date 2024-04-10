#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  if(m==1){
    printf("%.9lf\n",1.);
    return 0;
  }
  int x[1000],s=0;
  for(int i=0;i<n;i++){
    scanf("%d",x+i);
    x[i]--;
    s+=x[i];
  }
  static double E[2][100010]={0},S[100010];
  bool b=0;
  E[b][0]=1.;
  for(int i=0;i<n;i++){
    S[0]=0.;
    for(int j=0;j<=n*m;j++){
      S[j+1]=S[j]+E[b][j];
    }
    for(int j=0;j<=n*m;j++){
      E[!b][j]=(S[j+1]-S[max(0,j-m+1)]-(j-x[i]>=0?E[b][j-x[i]]:0))/(m-1);
      //printf("%d %d %lf\n",i,j,E[!b][j]);
    }
    b=!b;
  }
  double ans=0;
  for(int i=0;i<s;i++){
    ans+=E[b][i];
  }
  printf("%.9lf\n",ans*(m-1)+1);
  return 0;
}