#include <cstdio>
#include <utility>
#include <algorithm>

int n,m;
std::pair<int,int>num[501];
bool have[501];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		printf("? ");
		for(int j=1;j<=m;++j)putchar('0'+(i==j));
		puts("");
		fflush(stdout);
		scanf("%d",&num[i].first);
		num[i].second=i;
	}
	std::sort(num+1,num+m+1);
	long long now=0;
	for(int i=1;i<=m;++i){
		printf("? ");
		for(int j=1;j<=m;++j)putchar('0'+have[j]|(num[i].second==j));
		puts("");
		fflush(stdout);
		long long tem;
		scanf("%lld",&tem);
		if(tem==now+num[i].first)have[num[i].second]=1,now=tem;
	}
	printf("! %d\n",now);
	fflush(stdout);
}