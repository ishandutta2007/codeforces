#include <cstdio>

char str[2][21][21];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",str[0][i]+1);
	for(int i=0;i<m;i++)scanf("%s",str[1][i]+1);
	int q;
	scanf("%d",&q);
	for(int i=1,u,v;i<=q;i++){
		scanf("%d",&u);
		--u;
		printf("%s%s\n",str[0][u%n]+1,str[1][u%m]+1);
	}
}