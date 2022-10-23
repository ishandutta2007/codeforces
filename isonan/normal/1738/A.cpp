#include <cstdio>
#include <vector>
#include <algorithm>

int n,t,a[100001],c[100001];
std::vector<int>vec[2];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		vec[0].clear(),vec[1].clear();
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		long long tot=0;
		for(int i=1;i<=n;++i){
			scanf("%d",c+i);
			vec[a[i]].push_back(c[i]);
			tot+=c[i];
		}
		std::sort(vec[0].begin(),vec[0].end());
		std::sort(vec[1].begin(),vec[1].end());
		if(vec[0].size()==vec[1].size()){
			tot<<=1;
			tot-=std::min(vec[0][0],vec[1][0]);
			printf("%lld\n",tot);
		}
		else{
			if(vec[0].size()<vec[1].size())std::swap(vec[0],vec[1]);
			for(int i=0;i<vec[1].size();++i)vec[0].pop_back();
			tot<<=1;
			for(int v:vec[0])tot-=v;
			printf("%lld\n",tot);
		}
	}
}