#include <cstdio>

int main()
{
  int k,n,m;
  int x;
  scanf("%d%d%d%d",&k,&x,&n,&m);
  bool f=0;
  char A[111],B[111];
  for(int A1=0;A1<4;A1++){
    for(int B1=0;B1<4;B1++){
      if(n==1&&A1==3||m==1&&B1==3){
	continue;
      }
      int N,M;
      if(n%2==0){
	if(A1==0){
	  N=n/2;
	}
	else{
	  N=n/2-1;
	}
      }
      else{
	if(A1==3){
	  N=n/2-1;
	}
	else{
	  N=n/2;
	}
      }      
      if(m%2==0){
	if(B1==0){
	  M=m/2;
	}
	else{
	  M=m/2-1;
	}
      }
      else{
	if(B1==3){
	  M=m/2-1;
	}
	else{
	  M=m/2;
	}
      }
      for(int i=0;i<=N;i++){
	for(int j=0;j<=M;j++){
	  long long dp[100];
	  bool AA[100],BB[100];
	  dp[0]=i;
	  AA[0]=0;
	  BB[0]=0;
	  dp[1]=j;
	  AA[1]=1;
	  BB[1]=1;
	  for(int s=2;s<=k;s++){
	    dp[s]=dp[s-2]+dp[s-1];
	    AA[s]=AA[s-2];
	    BB[s]=BB[s-1];
	    if(((AA[s-1]==0&&(A1==1||A1==3))||(AA[s-1]==1&&(B1==1||B1==3)))
	       &&((BB[s-2]==0&&(A1==2||A1==3))||(BB[s-2]==1&&(B1==2||B1==3)))){
	      dp[s]++;
	    }
	    if(dp[s]>x){
	      dp[s]=x+1;
	    }
	  }
	  if(dp[k-1]==x){
	    f=1;
	    //printf("%d %d %d %d\n",A1,B1,i,j);
	    int p=0;
	    if(A1==1||A1==3){
	      A[p]='C';
	      p++;
	    }
	    for(int t=0;t<i;t++){
	      A[p]='A';
	      p++;
	      A[p]='C';
	      p++;
	    }
	    for(;p<(A1==2||A1==3?n-1:n);p++){
	      A[p]='B';
	    }
	    if(p==n-1){
	      A[p]='A';
	      p++;
	    }
	    A[p]=0;
	    p=0;
	    if(B1==1||B1==3){
	      B[p]='C';
	      p++;
	    }
	    for(int t=0;t<j;t++){
	      B[p]='A';
	      p++;
	      B[p]='C';
	      p++;
	    }
	    for(;p<(B1==2||B1==3?m-1:m);p++){
	      B[p]='B';
	    }
	    if(p==m-1){
	      B[p]='A';
	      p++;
	    }
	    B[p]=0;
	  }
	}
      }
    }
  }
  if(f){
    printf("%s\n%s\n",A,B);
  }
  else{
    puts("Happy new year!");
  }
  return 0;
}