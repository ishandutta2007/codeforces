#include <algorithm>
#include <cstdio>
#include <map> 

std::map<int,long long>map;
int n,a[200001],b[200001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),map[b[i]-i]+=b[i];
	long long ans=0;
	for(auto it=map.begin();it!=map.end();++it)ans=std::max(ans,it->second);
	printf("%lld\n",ans);
}