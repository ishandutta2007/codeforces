#include <cstdio>

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int K[1000]={0},L[1000]={0};
  for(int i=0;i<m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    x--;
    y--;
    K[x]=1;
    L[y]=1;
  }
  int A=0;
  for(int i=1;i<n-1;i++){
    if(!K[i]&&L[i]||K[i]&&!L[i]){
      A++;
    }
    else if(!K[i]&&!L[i]){
      if(i==n-i-1){
	A++;
      }
      else{
	A+=2;
      }
    }
  }
  printf("%d\n",A);
  return 0;
}