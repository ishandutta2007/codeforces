#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  char S[5000][2];
  int A[5000],B[5000];
  for(int i=0;i<n;i++){
    scanf("%s%d%d",S[i],A+i,B+i);
  }
  int M=0;
  for(int i=1;i<=366;i++){
    int m=0,f=0;
    for(int j=0;j<n;j++){
      if(A[j]<=i&&i<=B[j]){
	if(S[j][0]=='M'){
	  m++;
	}
	else{
	  f++;
	}
      }
    }
    M=max(M,min(m,f));
  }
  printf("%d\n",2*M);
  return 0;
}