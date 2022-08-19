#include <cstdio>

int t,n,a[200001],cnt[30];
int gcd(int a,int b){
	return (!b)?a:gcd(b,a%b);
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		for(int i=0;i<30;++i)cnt[i]=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<30;++j){
				cnt[j]+=(a[i]&(1<<j))!=0;
			}
		}
		int x=0;
		for(int i=0;i<30;++i)x=gcd(x,cnt[i]);
		if(!x){
			for(int i=1;i<=n;++i)printf("%d ",i);
		}
		else{
			for(int i=1;i<=n;++i)
				if(x%i==0)printf("%d ",i);
		}
		putchar('\n');
	}
}