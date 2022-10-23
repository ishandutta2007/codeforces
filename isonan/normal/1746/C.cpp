#include <bits/stdc++.h>

int t,n,k,a[100001],p[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1,tem;i<=n;++i){
			scanf("%d",a+i);
			p[a[i]]=i;
		}
		for(int i=1;i<=n;++i){
			int x=p[i]+1;
			if(x==n+1)x=1;
			printf("%d ",x);
		}
		putchar('\n');
	}
}