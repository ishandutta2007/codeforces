#include <cstdio>
#include <vector>
#include <algorithm>

int t,n,a[4001];
std::vector<int>ans;
void flip(int x){
	std::reverse(a+1,a+x+1);
	ans.push_back(x);
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		bool Ans=1;
		for(int i=1;i<=n;++i)
			if((a[i]&1)!=(i&1))Ans=0;
		if(!Ans){
			puts("-1");
			continue;
		}
		ans.clear();
		for(int i=n;i>1;i-=2){
			for(int j=1;j<=n;++j)
				if(a[j]==i){
					flip(j);
					break;
				}
			for(int j=1;j<=n;++j)
				if(a[j]==i-1){
					flip(j-1);
					flip(j+1);
					flip(3);
					flip(i);
					break;
				}
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);putchar('\n');
	}
}