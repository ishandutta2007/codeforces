#include <cstdio>
#include <set>

std::set<std::pair<long long,int> >set;
int t,n,m,x,h[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d%d",&n,&m,&x);
		set.clear();
		for(int i=1;i<=m;++i)set.insert(std::make_pair(0,i));
		puts("YES");
		for(int i=1;i<=n;++i){
			scanf("%d",h+i);
			std::pair<long long,int>now=*set.begin();
			set.erase(set.begin());
			printf("%d ",now.second);
			now.first+=h[i];
			set.insert(now);
		}
		
		putchar('\n');
	}
}