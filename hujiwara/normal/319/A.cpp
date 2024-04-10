#include <cstdio>
#include <cstring>

#define MOD 1000000007

int main()
{
  char s[110];
  scanf("%s",s);
  int n=strlen(s);
  long long P[110];
  P[0]=1;
  for(int i=0;i<n;i++){
    P[i+1]=P[i]*2%MOD;
  }
  long long A=0ll;
  for(int i=0;i<n;i++){
    if(s[n-i-1]=='1'){
      A=(A+P[n-i-1]*(P[i]*P[i]%MOD)%MOD)%MOD;
    }
  }
  printf("%d\n",(int)A);
  return 0;
}