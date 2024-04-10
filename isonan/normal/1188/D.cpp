#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

long long a[100001];
int f[100001],g[100001];
std::pair<long long,int>b[100001];
int n;
signed main(){
	scanf("%lld",&n);
	long long mx=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		mx=std::max(mx,a[i]);
	}
	for(int i=1;i<=n;i++)a[i]=mx-a[i];
	memset(f,0x3f3f3f3f,sizeof f);
	f[0]=0;
	for(long long i=0,tem=0;i<63;i++){
		memset(g,0x3f3f3f3f,sizeof g);
		for(int j=1;j<=n;j++)b[j]=std::make_pair(a[j]&tem,j);
		std::sort(b+1,b+n+1);
		std::reverse(b+1,b+n+1);
		int cntf=0,tot=0;
		for(int j=1;j<=n;j++)
			if(a[j]&(1ll<<(1ll*i)))++tot;
		for(int j=0;j<=n;j++){
			if(j)cntf+=((a[b[j].second]&(1ll<<(1ll*i)))!=0);
			g[cntf]=std::min(g[cntf],f[j]+(j-cntf)+tot-cntf);
			g[j+(tot-cntf)]=std::min(g[j+(tot-cntf)],f[j]+(n-j-tot+cntf)+cntf);
		}
		memcpy(f,g,sizeof g);
		tem|=(1ll<<(1ll*i));
	}
	printf("%d",f[0]);
}