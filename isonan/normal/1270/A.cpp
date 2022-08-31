#include <cstdio>
#include <algorithm>

int t,n,k1,k2;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d",&n,&k1,&k2);
		int mx1=0,mx2=0;
		for(int i=1,tem;i<=k1;i++)scanf("%d",&tem),mx1=std::max(mx1,tem);
		for(int i=1,tem;i<=k2;i++)scanf("%d",&tem),mx2=std::max(mx2,tem);
		if(mx1>mx2)puts("YES");
		else puts("NO");
	}
}