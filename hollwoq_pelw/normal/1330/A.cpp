#include<cstdio>
using namespace std;
int T,n,x,k,ans;
bool a[310];
int main(){
	scanf("%d",&T);
	while (T--){
		for (int i=1;i<=300;i++) a[i]=false;
		scanf("%d%d",&n,&x);
		for (int i=1;i<=n;i++){
			scanf("%d",&k);
			a[k]=true;
		}
		ans=0;
		for (int i=1;i<=300&&x>=0;i++){
			if (!a[i]) x--;
			ans=i;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}