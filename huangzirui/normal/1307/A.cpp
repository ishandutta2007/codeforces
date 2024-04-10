#include<stdio.h>
const int maxn=105;
int T,n,d;
int a[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans=a[1];
		for(int i=2;i<=n;i++){
			int v=d/(i-1);
			if(v>=a[i])
				d-=a[i]*(i-1),ans+=a[i];
			else{
				ans+=v;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}