#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}


int main()
{
  int rt[6][3]={{0,1,2},
		{0,2,1},
		{1,0,2},
		{1,2,0},
		{2,0,1},
		{2,1,0},
  };
  int SS[64][3]={0},C[64]={0};
  for(int I=1;I<64;I++){
      for(int k=0;k<6;k++){
	if(!((I>>k)&1))continue;
	for(int s=0;s<3;s++){
	  SS[I][s]|=(1<<rt[k][s]);
	}
	C[I]++;
      }
  }
  int dc[100010];
  for(int a=1;a<=100000;a++){
    dc[a]=0;
    for(int i=1;i*i<=a;i++){
      if(a%i==0){
	dc[a]++;
	if(a/i>i){
	  dc[a]++;
	}
      }
    }
  }
  int T;
  scanf("%d",&T);
  while(T--){
    int ans=0ll;
    int A[3];
    scanf("%d%d%d",A,A+1,A+2);
    int B[8];
    for(int S=1;S<8;S++){
      B[S]=0;
      for(int s=0;s<3;s++){
	if((S>>s)&1){
	  B[S]=gcd(A[s],B[S]);
	}
      }
    }
    int ct3=0,ct2=0,ct1=0;
    for(int I=1;I<64;I++){
      int sg=(C[I]%2==1?1:-1);
      ct3+=sg*dc[B[SS[I][0]]]*dc[B[SS[I][1]]]*dc[B[SS[I][2]]];
      ct2+=sg*(dc[B[SS[I][0]|SS[I][1]]]*dc[B[SS[I][2]]]+dc[B[SS[I][1]|SS[I][2]]]*dc[B[SS[I][0]]]+dc[B[SS[I][2]|SS[I][0]]]*dc[B[SS[I][1]]]);
      ct1+=sg*dc[B[SS[I][0]|SS[I][1]|SS[I][2]]];
      //printf("%d %d\n",I,ct);
    }
    printf("%d\n",(ct3-ct2+2*ct1)/6+(ct2-3*ct1)/3+ct1);
  }
  return 0;
}