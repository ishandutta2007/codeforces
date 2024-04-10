#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  char s[120][120];
  for(int i=0;i<n;i++){
    scanf("%s",s[i]);
  }
  int X=0,Y=0,c=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]=='B'){
	X+=i;
	Y+=j;
	c++;
      }
    }
  }
  printf("%d %d\n",X/c+1,Y/c+1);
  return 0;
}