#include<cstdio>
const int N=1e5+5;
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int p;
		scanf("%d",&p);
		ans+=p;
	}
	printf("%lf\n",1.0*ans/n);
	return 0;
}