#include <cstdio>

int n,d[100001];
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		++d[u];
		++d[v];
	}
	for(int i=1;i<=n;i++)
		if(d[i]==2){
			puts("NO");
			return 0;
		}
	puts("YES");
}