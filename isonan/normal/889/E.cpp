#include <algorithm>
#include <cstdio>
#include <map>

std::map<long long,long long>map;
int n;
long long a;
void update(long long r,long long k){
	r=-r;
	if(map.count(r))map[r]=std::max(map[r],k);
	else map[r]=k;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a);
		if(i==1)update(a-1,0);
		for(auto it=map.begin(),tem=it;it!=map.end();){
			long long f=-it->first,s=it->second;
			if(f<a)break;
			update(a-1,s+(1ll*(i-1)*(f-(f%a)-a)));
			update((f%a),s+(1ll*(i-1)*(f-(f%a))));
			tem=it;
			++it;
			map.erase(tem);
		}
	}
	long long ans=0;
	for(auto it=map.begin();it!=map.end();++it)
		ans=std::max(ans,1ll*n*(-it->first)+it->second);
	printf("%I64d",ans);
}