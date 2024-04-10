#include <cstdio>
#include <algorithm>
#include <vector>

int n,m,a[2001],b[2001],c[2001],d[2001];
std::vector<std::pair<int,int> >vec;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
	for(int i=1;i<=m;i++)scanf("%d%d",c+i,d+i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(c[j]>=a[i]&&d[j]>=b[i]){
				vec.push_back(std::make_pair(c[j]-a[i]+1,d[j]-b[i]+1));
			}
	std::sort(vec.begin(),vec.end());
	int ans=0x7f7f7f7f,mx=0;
	for(int i=vec.size()-1;~i;--i){
		ans=std::min(ans,mx+vec[i].first);
		mx=std::max(mx,vec[i].second);
	}
	ans=std::min(ans,mx);
	printf("%d\n",ans);
}