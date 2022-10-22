#include <cstdio>
const int Maxn=200000;
int n;
int a[Maxn+5],b[Maxn+5];
int vis[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	int num=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!vis[a[i]]){
			num++;
			vis[a[i]]=i;
			b[i]=a[i];
		}
		else{
			b[i]=-1;
		}
	}
	for(int i=1,j=1;i<=n;i++){
		if(b[i]==-1){
			while(vis[j]){
				j++;
			}
			if(j==i){
				b[i]=a[i];
				b[vis[a[i]]]=j;
				vis[j]=vis[a[i]];
				vis[a[i]]=i;
			}
			else{
				b[i]=j;
				vis[j]=i;
			}
		}
	}
	printf("%d\n",num);
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}