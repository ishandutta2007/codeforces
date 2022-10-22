#include <cstdio>
#define Maxn 100
int a[Maxn+5];
int b[Maxn+5];
int n,m;
bool vis[Maxn<<2|5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vis[a[i]]=1;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		vis[b[i]]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!vis[a[i]+b[j]]){
				printf("%d %d\n",a[i],b[j]);
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}