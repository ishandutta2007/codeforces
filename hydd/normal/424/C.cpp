#include<cstdio>
using namespace std;
int n,sum[1100000];
int main(){
	scanf("%d",&n);
	int x,ans=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		ans^=x;
	}
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]^i;
	for (int i=1;i<=n;i++){
		if ((n/i)&1) ans^=sum[i-1];
		ans^=sum[n%i];
	}
	printf("%d\n",ans);
	return 0;
}