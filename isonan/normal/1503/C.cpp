#include <cstdio>
#include <set>

int a[100001],c[100001],n;
std::set<std::pair<int,int> >set1,set2;
int main(){
	scanf("%d",&n);
	long long val=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d",a+i,c+i);
		c[i]+=a[i];
		val-=a[i];
		set1.insert(std::make_pair(a[i],i));
		set2.insert(std::make_pair(c[i],i));
	}
	for(int i=1;i<n;++i){
		std::pair<int,int>x1=*set1.rbegin(),x2=*set2.rbegin();
		if(x1.second==x2.second){
			if(((++set1.rbegin())->first)<(++set2.rbegin())->first)x2=*++set2.rbegin();
			else x1=*++set1.rbegin();
		}
		val+=std::max(x1.first,x2.first);
		int u=x1.second,v=x2.second;
		set1.erase(std::make_pair(a[u],u));
		set1.erase(std::make_pair(a[v],v));
		set2.erase(std::make_pair(c[u],u));
		set2.erase(std::make_pair(c[v],v));
		set1.insert(std::make_pair(a[v],v));
		set2.insert(std::make_pair(c[u],v));
		c[v]=c[u];
	}
	printf("%lld\n",val+std::max(set1.rbegin()->first,set2.rbegin()->first));
}