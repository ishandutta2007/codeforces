#include <bits/stdc++.h>
using namespace std;

const int MN=400010;
const int BS=19;

int main()
{
  int N=1;
  static int pr[MN][BS];
  static long long MW[MN][BS];
  static int Pr[MN][BS];
  static long long SW[MN][BS];
  for(int t=0;t<BS;t++){
    pr[0][t]=Pr[0][t]=-1;
    MW[0][t]=SW[0][t]=0;
  }
  int Q;
  scanf("%d",&Q);
  long long last=0;
  while(Q--){
    int t;
    long long p,q;
    scanf("%d%lld%lld",&t,&p,&q);
    int R=(p^last)-1;
    long long W=q^last;
    if(t==1){
      for(int t=0;t<BS;t++){
	pr[N][t]=Pr[N][t]=-1;
      }
      pr[N][0]=R;
      MW[N][0]=W;
      for(int t=1;t<BS;t++){
	pr[N][t]=pr[pr[N][t-1]][t-1];
	if(pr[N][t]!=-1){
	  MW[N][t]=max(MW[N][t-1],MW[pr[N][t-1]][t-1]);
	}
	else{
	  break;
	}
      }
      int P=R;
      for(int t=BS-1;t>=0;t--){
	if(pr[P][t]!=-1&&MW[P][t]<W){
	  P=pr[P][t];
	}
      }
      if(MW[P][0]<W){
	P=pr[P][0];
      }
      Pr[N][0]=P;
      SW[N][0]=W;
      //printf("%d %d %lld\n",N,P,SW[N][0]);
      if(P!=-1){
	for(int t=1;t<BS;t++){
	  Pr[N][t]=Pr[Pr[N][t-1]][t-1];
	  if(Pr[N][t]!=-1){
	    SW[N][t]=SW[N][t-1]+SW[Pr[N][t-1]][t-1];
	  }
	  else{
	    break;
	  }
	}
      }
      N++;
    }
    else{
      int ans=0;
      long long S=0ll;
      int P=R;
      //printf("%d %d %d %lld\n",P,Pr[P][0],Pr[P][1],W);
      for(int t=BS-1;t>=0;t--){
	if(Pr[P][t]!=-1&&S+SW[P][t]<=W){
	  S+=SW[P][t];
	  P=Pr[P][t];
	  ans+=(1<<t);
	}
      }
      if(S+SW[P][0]<=W){
	ans++;
      }
      printf("%d\n",ans);
      last=ans;
    }
  }
  return 0;
}