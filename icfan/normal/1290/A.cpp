#include <cstdio>
const int Maxn=3500;
const int Inf=(1<<30);
int n,m,k;
int a[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int t;
	scanf("%d",&t);
	int ans,now;
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		ans=0;
		if(k>=m-1){
			for(int i=1;i<=m;i++){
				ans=mx(ans,a[i]);
				ans=mx(ans,a[n-i+1]);
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=0;i<=k;i++){
			now=Inf;
			for(int j=0;j<=(m-1-k);j++){
				now=mn(now,mx(a[i+j+1],a[n-(k-i)-(m-1-k-j)]));
			}
			ans=mx(ans,now);
		}
		printf("%d\n",ans);
	}
	return 0;
}