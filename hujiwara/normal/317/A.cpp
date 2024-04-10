#include <cstdio>

int main()
{
  long long x,y,m;
  scanf("%I64d%I64d%I64d",&x,&y,&m);
  //scanf("%d%d%d",&x,&y,&m);
  long long T;
  if(x<=0&&y<=0){
    if(m<=x||m<=y){
      T=0;
    }
    else{
      T=-1;
    }
  }
  else{
    T=0;
    if(x<m&&y<m){
      if(x<=0){
	T+=(-x+y-1)/y;
	x+=(-x+y-1)/y*y;
      }
      if(y<=0){
	T+=(-y+x-1)/x;
	y+=(-y+x-1)/x*x;
      }
      while(x<m&&y<m){
	long long M=x+y;
	if(x<=y){
	  x=M;
	}
	else{
	  y=M;
	}
	T++;
      }
    }
  }
  printf("%I64d\n",T);
  //printf("%d\n",T);
  return 0;
}