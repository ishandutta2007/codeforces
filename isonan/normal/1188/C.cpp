#include <cstdio>
#include <algorithm>

int f[1001][1001],a[1001],n,k,mx,P=998244353,ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	a[0]=-10000000;
	std::sort(a+1,a+n+1);
	for(int i=1;i<=(a[n]+k-2)/(k-1);i++){
		int last=0;
		f[0][0]=1;
		for(int j=1;j<=n;j++){
			while((a[j]-a[last+1])>=i)++last;
			for(int l=0;l<=k;l++)f[j][l]=0;
			for(int l=1;l<=k;l++)f[j][l]=f[last][l-1];
			for(int l=0;l<=k;l++)(f[j][l]+=f[j-1][l])%=P;
		}
		(ans+=f[n][k])%=P;
	}
	printf("%d",ans);
}