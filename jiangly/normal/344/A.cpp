#include<cstdio>
int n,x,y,ans;
int main(){
	scanf("%d%d",&n,&x);
	for(int i=2;i<=n;++i){
		scanf("%d",&y);
		ans+=x!=y;
		x=y;
	}
	printf("%d\n",ans+1);
	return 0;
}