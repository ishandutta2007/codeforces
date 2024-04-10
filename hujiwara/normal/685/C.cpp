#include <bits/stdc++.h>
using namespace std;
const long long INF=4000000000000000000ll;

int main()
{
  int T;
  scanf("%d",&T);
  static long long X[100000],Y[100000],Z[100000];
  while(T--){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%lld%lld%lld",X+i,Y+i,Z+i);
    }
    long long a1=-INF,a2=INF,b1=-INF,b2=INF,c1=-INF,c2=INF,d1=-INF,d2=INF;
    for(int i=0;i<n;i++){
      a1=max(a1,X[i]-Y[i]-Z[i]);
      a2=min(a2,X[i]-Y[i]-Z[i]);
      b1=max(b1,-X[i]+Y[i]-Z[i]);
      b2=min(b2,-X[i]+Y[i]-Z[i]);
      c1=max(c1,-X[i]-Y[i]+Z[i]);
      c2=min(c2,-X[i]-Y[i]+Z[i]);
      d1=max(d1,-X[i]-Y[i]-Z[i]);
      d2=min(d2,-X[i]-Y[i]-Z[i]);
    }
    long long L=-1,R=3100000000000000000ll;
    long long x,y,z;
    while(L+1<R){
      long long d=(L+R)/2;
      long long A1=a1-d,A2=a2+d,B1=b1-d,B2=b2+d,C1=c1-d,C2=c2+d,D1=d1-d,D2=d2+d;
      if(A1>A2||B1>B2||C1>C2||D1>D2||A1+B1+C1>D2||A2+B2+C2<D1){
	L=d;
	continue;
      }
      bool F=0;
      for(int I=0;I<8;I++){
	long long A=A1+(I/4),B=B1+(I/2%2),C=C1+(I%2);
	if(abs(A)%2!=abs(B)%2||abs(B)%2!=abs(C)%2||A>A2||B>B2||C>C2||A+B+C>D2){
	  continue;
	}
	long long P=D1-A-B-C;
	if(P<=0){
	  F=1;
	}
	else if(D1==D2&&P%2==1){
	  continue;
	}
	else{
	  if(P%2==1){
	    P++;
	  }
	  if(A+P<=A2){
	    A+=P;
	    F=1;
	  }
	  else{
	    P-=(A2-A)/2*2;
	    A+=(A2-A)/2*2;
	    if(B+P<=B2){
	      B+=P;
	      F=1;
	    }
	    else{
	      P-=(B2-B)/2*2;
	      B+=(B2-B)/2*2;
	      if(C+P<=C2){
		C+=P;
		F=1;
	      }
	    }
	  }
	}
	if(F){
	  x=-(B+C)/2,y=-(C+A)/2,z=-(A+B)/2;
	  break;
	}
      }
      //printf("%lld %d\n",(long long)d,F);
      if(!F){
	L=d;
      }
      else{
	R=d;
      }
    }
    printf("%lld %lld %lld\n",x,y,z);
  }
  return 0;
}