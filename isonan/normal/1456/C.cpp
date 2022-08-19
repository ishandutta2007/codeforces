#include <cstdio>
#include <algorithm>
 
int n,k,c[500010];
long long f[500010],S[500010];
int main(){
	scanf("%d%d",&n,&k);
	++k;
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	std::sort(c+1,c+n+1);
	long long ans=0,fin=-1e18;
	int p=0,mx=-1;
	for(int i=n;i;i--){
		S[i]=S[i+1]+c[i];
		f[i]=f[i+1]+S[i];
	}
	for(int i=1;i<=n;i++){
		ans+=1ll*((i-1)/k)*c[i];
		mx=((i-1)/k);
//		printf("%d %d %d\n",i,ans,mx);
		fin=std::max(fin,ans+f[i+1]+1ll*mx*S[i+1]);
	}
	printf("%lld\n",std::max(fin,f[1]-S[1]));
}