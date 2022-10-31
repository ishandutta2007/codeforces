#include <bits/stdc++.h>
using namespace std;
#define SZ 1000010
int main()
{
  int n;
  long long x,y;
  scanf("%d%lld%lld",&n,&x,&y);
  vector<int> a(n);
  for(int i=0;i<n;i++){
    scanf("%d",&(a[i]));
  }
  static long long K1[2*SZ+10]={0},K2[2*SZ+10]={0};
  for(int i=0;i<n;i++){
    K1[a[i]]++;
    K2[a[i]]+=a[i];
  }
  static long long S1[2*SZ+10],S2[2*SZ+10];
  S1[0]=S2[0]=0ll;
  for(int i=0;i<=2*SZ;i++){
    S1[i+1]=S1[i]+K1[i];
    S2[i+1]=S2[i]+K2[i];
  }
  int m=x/y;
  long long ans=x*n;
  static bool E[SZ+10];
  for(int p=2;p<=SZ;p++){
    if(E[p])continue;
    for(int j=p+p;j<=SZ;j+=p)E[j]=1;
    long long A=0ll;
    for(int t=0;t*p<=SZ;t++){
      int mm=min(m,p-1),C1=S1[t*p+p-mm]-S1[t*p+1],C2=S1[(t+1)*p]-S1[t*p+p-mm];
      A+=x*C1+y*((long long)C2*(t+1)*p-(S2[(t+1)*p]-S2[t*p+p-mm]));
      //if(p<18&&(C1>0||C2>0)){printf("%d %d %d %d\n",p,C1,C2,mm);}
    }
    ans=min(ans,A);
  }
  printf("%lld\n",ans);
  return 0;
}