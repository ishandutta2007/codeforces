#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  static bool B[2][501][501]={0};
  bool b=0;
  B[b][0][0]=1;
  for(int i=0;i<n;i++){
    int c;
    scanf("%d",&c);
    for(int x=0;x<=k;x++){
      for(int y=0;y<=x;y++){
	if(!B[b][x][y]){
	  continue;
	}
	B[b][x][y]=0;
	B[!b][x][y]=1;
	if(x+c<=k){
	  B[!b][x+c][y]=1;
	  B[!b][x+c][y+c]=1;
	}
      }
    }
    b=!b;
  }
  int C=0;
  for(int y=0;y<=k;y++){
    if(B[b][k][y]){
      C++;
    }
  }
  printf("%d\n",C);
  for(int y=0;y<=k;y++){
    if(B[b][k][y]){
      printf("%d ",y);
    }
  }
  putchar('\n');
  return 0;
}