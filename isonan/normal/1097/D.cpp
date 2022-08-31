#include <cstdio>
#include <cstring>
#define int long long

typedef long long ll;

long long n;
int k,P=1000000007,f[10001][51],ans=1;
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=(ll)ans*a%P;
		a=(ll)a*a%P;
		b>>=1;
	}
	return ans;
}
void DP(int prime,int power){
	memset(f,0,sizeof f);
	f[0][power]=1;
	for(int i=1;i<=k;i++)
		for(int j=power;~j;--j)
			f[i][j]=(f[i][j+1]+(ll)f[i-1][j]*qsm(j+1,P-2)%P)%P;
	int cnt=0;
	for(int i=0;i<=power;i++)(cnt+=(ll)f[k][i]*qsm(prime,i)%P)%=P;
	ans=(ll)ans*cnt%P;
}
signed main(){
	scanf("%I64d%d",&n,&k);
	for(long long i=2;i*i<=n;i++)
		if(n%i==0){
			int tem=0;
			while(n%i==0)++tem,n/=i;
			DP(i,tem);
		}
	if(n>1)DP(n,1);
	printf("%I64d\n",ans);
}