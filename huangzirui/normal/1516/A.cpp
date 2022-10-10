#include<stdio.h>
const int maxn=105;
int T,n,k;
int a[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<n;i++)
			while(a[i]&&k)
				a[i]--,k--,a[n]++;
		for(int i=1;i<=n;i++)
			printf("%d%c",a[i],i==n? '\n':' ');
	}
	return 0;
}