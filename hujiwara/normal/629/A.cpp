#include <cstdio>

int main()
{
  int n;
  scanf("%d",&n);
  char B[110][110];
  for(int i=0;i<n;i++){
    scanf("%s",B[i]);
  }
  int C=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=0;k<n;k++){
	if(B[i][k]=='C'&&B[j][k]=='C'){
	  C++;
	}
	if(B[k][i]=='C'&&B[k][j]=='C'){
	  C++;
	}
      }
    }
  }
  printf("%d\n",C);
  return 0;
}