#include <cstdio>

int n,ind[10001],top,stk[1001],now,to[10001];
long long ans[21],tot,fin[1001];
int main(){
	scanf("%d",&n);
	for(int i=0;i<(1<<13);i++)
		if(__builtin_popcount(i)==6){
			ind[++top]=i;
			to[i]=top;
		}
	for(int i=0;i<13;i++){
		top=0;
		for(int j=1;j<=n;j++)if(ind[j]&(1<<i))stk[++top]=j;
		if(top){
			printf("? %d",top);
			for(int i=1;i<=top;i++)printf(" %d",stk[i]);
			putchar('\n');
			fflush(stdout);
			scanf("%lld",ans+i);
		}
		tot|=ans[i];
	}
	for(int i=1;i<=n;i++)fin[i]=tot;
	for(int i=0;i<64;i++){
		long long tem=0,tm=0;
		for(int j=0;j<13;j++)(ans[j]&(1ll<<(1ll*i)))?tem|=1<<j:(tm|=ans[j]);
		fin[to[tem]]=tm;
	}
	printf("!");
	for(int i=1;i<=n;i++)printf(" %lld",fin[i]);
	putchar('\n');
	fclose(stdout);
}