#include <algorithm>
#include <cstdio>
#include <set>

std::set<std::pair<long long,int> >set;
int n,m;
long long l[200001],r[200001],gap[200001],ans[200001];
struct point{
	int ord;
	long long mn,mx;
}num[200001];
bool cmp(point a,point b){
	return (a.mx<b.mx)||(a.mx==b.mx&&a.mn<b.mn);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%I64d%I64d",l+i,r+i);
		if(i>1)num[i]=(point){i,l[i]-r[i-1],r[i]-l[i-1]};
	}
	std::sort(num+2,num+n+1,cmp);
	long long tem;
	for(int i=1;i<=m;i++){
		scanf("%I64d",&tem);
		set.insert(std::make_pair(tem,i));
	}
	for(int i=2;i<=n;i++){
		auto x=set.lower_bound(std::make_pair(num[i].mn,0));
		if(x==set.end()){
			puts("No");
			return 0;
		}
		if(x->first>num[i].mx){
			puts("No");
			return 0;
		}
		ans[num[i].ord]=x->second;
		set.erase(x);
	}
	puts("Yes");
	for(int i=2;i<=n;i++)printf("%d ",ans[i]);
}