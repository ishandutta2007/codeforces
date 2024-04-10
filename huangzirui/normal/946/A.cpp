#include<stdio.h>
#include<math.h> 
const int maxn=105;
int T,n,ans;
int a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),ans+=abs(a[i]);
	printf("%d\n",ans);
	return 0;
}