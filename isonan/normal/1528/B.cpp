#include <cstdio>

const int P=998244353;
int n;
int f[1000001];
int g[1000001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			g[j]=(g[j]+1);
	for(int i=1,sum=0;i<=n;i++){
		f[i]=(sum+g[i])%P;
		if(i==1)f[i]=1;
		sum=(sum+f[i])%P;
	}
	printf("%d\n",f[n]); 
}