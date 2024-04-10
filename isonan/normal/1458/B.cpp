#include <cstdio>
#include <cstring>
#include <algorithm>

int n,a[101],b[101];
int f[101][10001];
int main(){
	scanf("%d",&n);
	long long sum=0,S=0;
	for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i),S+=b[i];
	memset(f,-0x7f7f7f7f,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(int j=n;j;j--)
			for(int k=a[i];k<=sum;k++)
				f[j][k]=std::max(f[j][k],f[j-1][k-a[i]]+b[i]);
	}
	for(int k=1;k<=n;k++){
		long long ans=0;
		for(int l=0;l<=sum;l++)
			if(f[k][l]!=-0x7f7f7f7f){
				ans=std::max(ans,std::min((1ll*l)<<1ll,S+f[k][l]));
			}
		if(ans&1)printf("%lld.5 ",ans>>1);
		else  printf("%lld.0 ",ans>>1);
	}
}