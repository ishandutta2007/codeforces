#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

int x[2001],y[2001],a[2001];
int num[2001];
double v[2001];
int n;
bool cmp(int a,int b){
	return v[a]<v[b];
}
int f[2001];
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
std::vector<std::pair<int,int> >ans;
void check(int a,int b,int p){
	if(find(a)!=find(b)&&1ll*(x[b]-x[p])*(y[a]-y[p])-1ll*(y[b]-y[p])*(x[a]-x[p])<0ll){
		ans.push_back(std::make_pair(a,b));
		std::swap(::a[a],::a[b]);
		f[find(a)]=find(b);
	}
}
int main(){
	scanf("%d",&n);
	int p=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",x+i,y+i,a+i);
		if(a[i]!=i)p=i;
	}
	if(!p){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;++i)num[i]=i,v[i]=(i==p)?-1e18:atan2(y[i]-y[p],x[i]-x[p]);
	std::sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;++i){
		if(find(a[i])!=find(i))f[find(i)]=find(a[i]);
	}
	for(int i=2;i<n;++i)check(num[i],num[i+1],p);
	check(num[n],num[2],p);
	while(a[p]!=p){
		ans.push_back(std::make_pair(a[p],p));
		std::swap(a[p],a[a[p]]);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i)printf("%d %d\n",ans[i].first,ans[i].second);
}