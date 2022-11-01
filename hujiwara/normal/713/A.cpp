#include <cstdio>
#include <cstring>

int main()
{
  static int C[1<<18]={0};
  int T;
  scanf("%d",&T);
  while(T--){
    char s[2];
    scanf("%s",s);
    if(s[0]!='?'){
      char d[20];
      scanf("%s",d);
      int I=0;
      int m=strlen(d);
      for(int i=0;i<m;i++){
	if((d[i]-'0')%2==1){
	  I|=1<<(m-i-1);
	}
      }
      if(s[0]=='+'){
	C[I]++;
      }
      else{
	C[I]--;
      }
    }
    else{
      char d[20];
      scanf("%s",d);
      int m=strlen(d);
      int I=0;
      for(int i=0;i<m;i++){
	if(d[i]=='1'){
	  I|=1<<(m-i-1);
	}
      }
      printf("%d\n",C[I]);
    }
  }
  return 0;
}