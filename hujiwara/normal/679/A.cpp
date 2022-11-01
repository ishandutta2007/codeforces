#include <bits/stdc++.h>
using namespace std;

int main()
{
  int d[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  bool F=1;
  for(int i=0;i<4;i++){
    printf("%d\n",d[i]);
    fflush(stdout);
    char s[5];
    scanf("%s",s);
    if(s[0]=='y'){
      bool G=0;
      for(int j=i;j<15&&d[i]*d[j]<=100;j++){
	printf("%d\n",d[i]*d[j]);
	fflush(stdout);
	scanf("%s",s);
	if(s[0]=='y'){
	  G=1;
	  break;
	}
      }
      if(G){
	F=0;
      }
      else{
	F=1;
      }
      break;
    }
  }
  puts(F?"prime":"composite");
  return 0;
}