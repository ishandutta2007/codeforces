#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
#define MOD 1000000007
long long C[1010][1010],F1[1001010],F2[1001010],F3[1001010],n,K,i,j,ans;
long long calc(long long x,long long y){
	return F2[n*n-(n-x)*(n-y)]*F1[(n-x)*(n-y)] % MOD;
}
int main()
{
	n=read();K=read();
	C[0][0]=1;
	for (i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for (j=1;j<i;j++)
		   C[i][j]=(C[i-1][j]+C[i-1][j-1]) % MOD;
	}
	F1[0]=1;F2[0]=1;F3[0]=1;
	for (i=1;i<=max(n*n,2*n);i++) {
		F1[i]=F1[i-1]*K % MOD;
		F2[i]=F2[i-1]*(K-1) % MOD;
		F3[i]=F3[i-1]*(MOD-1) % MOD;
	}
    for (i=0;i<=n;i++)
       for (j=0;j<=n;j++)
          ans=(ans+F3[i+j]*C[n][i] % MOD*C[n][j] % MOD*calc(i,j)) % MOD;
    printf("%lld\n",ans);
return 0;
}