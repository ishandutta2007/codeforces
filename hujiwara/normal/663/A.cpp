#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  int b[110];
  int N=1,A=1,B=0;
  b[0]=1;
  while(1){
    char q[2],s[2];
    scanf("%s%s",q,s);
    if(s[0]=='+'){
      b[N]=1;
      N++;
      A++;
    }
    else if(s[0]=='-'){
      b[N]=-1;
      N++;
      B++;
    }
    else{
      break;
    }
  }
  scanf("%d",&n);
  if(A*1-B*n>n||A*n-B*1<n){
    puts("Impossible");
  }
  else{
    puts("Possible");
    int C[110];
    int t=n;
    for(int i=0;i<N;i++){
      if(b[i]==1){
	A--;
	C[i]=min(n,t-(A-B*n));
	t-=C[i];
      }
      else{
	B--;
	//A*1-B*n<=t+d;
	C[i]=max(1,(A*1-B*n)-t);
	t+=C[i];
      }
    }
    for(int i=0;i<N;i++){
      if(i>0){
	printf(" %c ",b[i]==1?'+':'-');
      }
      printf("%d",C[i]);
    }
    printf(" = %d\n",n);
  }
  return 0;
}