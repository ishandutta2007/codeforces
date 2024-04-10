#include <cstdio>
#include <vector>

int a[200001],n,t;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		long long tot=0;
		int p=n+1;
		bool bb=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i),tot+=a[i];
			if(tot<0){
				bb=1;
			}
			else if(tot==0)
				if(p==n+1)p=i;
		}
		for(int j=p+1;j<=n;++j)if(a[j])bb=1;
		if(tot||bb){
			puts("No");
			continue;
		}
		puts("Yes");
	}
}