#include <cstdio>
#define Maxn 1000000
int t;
int n;
int a[Maxn+5];
int vis[Maxn+5];
int ans[Maxn+5];
int main(){
	int len;
	scanf("%d",&t);
	int now;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]=i-a[i];
			vis[i]=0;
		}
		now=1;
		len=0;
		while(1){
			if(vis[now]){
				break;
			}
			ans[++len]=now;
			vis[now]=len;
			now=a[now];
		}
		printf("%d\n",len-vis[now]+1);
		for(int i=vis[now];i<=len;i++){
			printf("%d ",ans[i]);
		}
		puts("");
	}
	return 0;
}