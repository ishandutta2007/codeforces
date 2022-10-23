#include <bits/stdc++.h>

int t,n,k,a[51];
int f[51][51];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&k);
		bool bb=0;
		for(int i=1,tem;i<=n;++i){
			scanf("%d",a+i);
			if(a[i]==1)bb=1;
		}
		if(bb)puts("YES");
		else puts("NO");
	}
}