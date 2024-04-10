#include <cstdio>

int cntval[1000001],pow[1000001],cntexi[1000001],prime[1000001],n,f[1000001],p[1000001],top,mx[1000001],exi[1000001],P=1000000007;
bool pri[1000001];
int vis[1000001],vis2[1000001];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
	scanf("%d",&n);
	f[1]=mx[1]=1;
	for(int i=2;i<=n;i++){
		if(!pri[i])prime[++top]=f[i]=mx[i]=i;
		for(int j=1;j<=top&&i*prime[j]<=n;j++){
			int tem=i*prime[j];
			pri[tem]=1;
			mx[tem]=mx[i];
			if(i%prime[j]==0){
				f[tem]=f[i];
				break;
			}
			else f[tem]=f[i]*prime[j];
		}
	}
	for(int i=1;i<=n;i++)++cntval[f[i]];
	++cntexi[exi[1]=1];
	for(int i=1;i<=top;i++)++cntexi[exi[prime[i]]=n/prime[i]];
	for(int i=1;i<=n;i++){
		p[i]=read();
		if(!p[i])continue;
		if(f[p[i]]!=f[i]&&(f[p[i]/mx[p[i]]]!=f[i/mx[i]]||exi[mx[p[i]]]!=exi[mx[i]])){
			puts("0");
			return 0;
		}
		--cntval[f[i]];
		if(!vis2[mx[p[i]]])vis2[mx[p[i]]]=mx[i];
		else if(vis2[mx[p[i]]]!=mx[i]){
			puts("0");
			return 0;
		}
		if(!vis[mx[i]])vis[mx[i]]=mx[p[i]],--cntexi[exi[mx[i]]];
		else if(vis[mx[i]]!=mx[p[i]]){
			puts("0");
			return 0;
		}
	}
	int ans=pow[0]=1;
	for(int i=1;i<=n;i++)pow[i]=1ll*pow[i-1]*i%P;
	for(int i=1;i<=n;i++)ans=1ll*ans*pow[cntval[i]]%P*pow[cntexi[i]]%P;
	printf("%d\n",ans);
}