#include <cstdio>

int n,t,a[100001],q;
bool vis[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			vis[i]=0;
		}
		for(int i=n,t=0;i;--i){
			if(t<q&&a[i]>=t+1)++t,vis[i]=1;
			else if(a[i]<=t)vis[i]=1;
		}
		for(int i=1;i<=n;++i)printf("%d",vis[i]);putchar('\n');
	}
}