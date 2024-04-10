#include <cstdio>
#include <algorithm>

int n,m,hp[1000010],res[1000010],k[1000010];
long long tot;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",hp+i),res[i]=(tot+=hp[i])%n;
	res[m]=n;
	std::sort(res+1,res+m+1);
	std::adjacent_difference(res+1,res+m+1,k+1);
	printf("%d\n",(tot+n-1)/n);
	for(int i=1;i<=m;i++)printf("%d ",k[i]);putchar('\n');
	int cnt=0;
	for(int i=1,j=1;i<=m;i++)
		for(;hp[i]>0;hp[i]-=k[j],j=(j==m)?1:j+1){
			printf("%d",i);
			if(j==m)putchar('\n');
			else putchar(' ');
			++cnt;
		}
	for(int i=cnt+1;i<=((tot+n-1)/n)*m;i++)printf("%d ",m);
}