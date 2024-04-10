#include <cstdio>
#include <map>

int t,n,a[200001],cnt[400001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)cnt[i]=0;
		for(int i=0;i<n;i++){
			scanf("%d",a+i);
			++cnt[((i+a[i])%n+n)%n];
		}
		bool cando=1;
		for(int i=0;i<n;i++)if(cnt[i]>1)cando=0;
		if(cando)puts("YES");
		else puts("NO");
	}
}