#include <cstdio>
#include <map>

int n,a[200001],q,val[200001];
long long ans;
std::map<std::pair<int,int>,int>map;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),ans+=a[i];
	scanf("%d",&q);
	for(int i=1,s,t,u;i<=q;i++){
		scanf("%d%d%d",&s,&t,&u);
			if(map.count(std::make_pair(s,t))){
				int ind=map[std::make_pair(s,t)];
				ans-=std::max(a[ind]-val[ind],0);
				--val[ind];
				ans+=std::max(a[ind]-val[ind],0);
				map.erase(std::make_pair(s,t));
			}
		if(u){
			int ind=u;
				ans-=std::max(a[ind]-val[ind],0);
				++val[ind];
				ans+=std::max(a[ind]-val[ind],0);
			map[std::make_pair(s,t)]=ind;
		}
		printf("%lld\n",ans);
	} 
}