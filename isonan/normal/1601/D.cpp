#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

int n,d;
std::pair<int,int>a[500100];
bool cmp(std::pair<int,int> a,std::pair<int,int> b){
	return 
		std::max(a.first,a.second)< std::max(b.first,b.second)||(
		std::max(a.first,a.second)==std::max(b.first,b.second)&&
		std::min(a.first,a.second)< std::min(b.first,b.second));
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i].first,&a[i].second);
	std::sort(a+1,a+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(a[i].first>=d){
			++cnt;
			d=std::max(d,a[i].second);
		}
	printf("%d\n",cnt);
}