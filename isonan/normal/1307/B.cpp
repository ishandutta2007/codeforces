#include <cstdio>
#include <algorithm>

int n,d,a[100001],ans;
int main(){
	int t;
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		std::sort(a+1,a+n+1);
		bool cando=0;
		for(int i=1;i<=n;i++)
			if(a[i]==d){
				puts("1");
				cando=1;
				break;
			}
		if(!cando)printf("%d\n",(d%a[n]==0)?(d/a[n]):(d<a[n]?2:(d/a[n]+1)));
	}
}