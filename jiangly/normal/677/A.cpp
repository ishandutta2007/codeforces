#include<cstdio>
const int N=1e5+5;
int n,h,ans;
int main(){
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;++i){
		int a;
		scanf("%d",&a);
		ans+=a>h;
	}
	printf("%d\n",ans+n);
	return 0;
}