#include <cstdio>
#include <map>

int n,vis[7010];
long long a[7010],b[7010];
std::map<long long,int>map;
std::map<long long,int>::iterator it;

int main(){
	scanf("%d",&n);

	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]),++map[a[i]];
	
	for(int i=1;i<=n;i++)scanf("%I64d",&b[i]);
	
	long long ans=0;
	
	for(int j=1;j<=n;j++)
		if(map[a[j]]>1){
			for(int i=1;i<=n;i++)
				vis[i]|=((a[i]&a[j])==a[i]);
		}

	for(int i=1;i<=n;i++)ans+=1ll*vis[i]*b[i];
	
	printf("%I64d\n",ans);
}