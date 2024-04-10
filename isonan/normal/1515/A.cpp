#include <cstdio>
#include <algorithm>

int t,n,x,w[101];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&x);
		int sum=0;
		for(int i=1;i<=n;++i)scanf("%d",w+i),sum+=w[i];
		if(sum==x){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1,y=0;i<=n;++i){
			if(y+w[i]==x){
				std::swap(w[i],w[i+1]);
			}
			y+=w[i];
			printf("%d ",w[i]);
		}
		putchar('\n');
	}
}