#include <algorithm>
#include <cstdio>
#include <set>

int n,a[200001],t[200001];
struct point{
	int a,t;
}num[200001];
bool cmp(point a,point b){
	return a.a<b.a;
}
std::multiset<int>set;
long long sum,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i].a);
	for(int i=1;i<=n;i++)scanf("%d",&num[i].t);
	std::sort(num+1,num+n+1,cmp);
	for(int i=1,last=-1;i<=n;i++){
		while(last!=num[i].a&&set.size()){
			sum-=*set.rbegin();
			set.erase(--set.end());
			ans+=sum;
			++last;
		}
		last=num[i].a;
		set.insert(num[i].t);
		sum+=num[i].t;
	}
		while(set.size()){
			sum-=*set.rbegin();
			set.erase(--set.end());
			ans+=sum;
		}
	printf("%lld\n",ans);
}