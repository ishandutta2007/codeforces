#include <algorithm>
#include <cstdio>
#include <cmath>

int t,n;
int a[100001],b[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		int i1=0,i2=0;
		for(int i=1,t1,t2;i<=(n<<1);++i){
			scanf("%d%d",&t1,&t2);
			if(t2<0)t2=-t2;
			if(t1<0)t1=-t1;
			if(!t1)a[++i1]=t2;
			else b[++i2]=t1;
		}
		std::sort(a+1,a+n+1);
		std::sort(b+1,b+n+1);
		double ans=0;
		for(int i=1;i<=n;++i){
			ans+=sqrt((double)a[i]*a[i]+(double)b[i]*b[i]);
		}
		printf("%.10lf\n",ans);
	}
}