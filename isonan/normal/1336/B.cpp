#include <cstdio>
#include <set>

std::set<int>set[3];
int a[100001],b[100001],c[100001],t,na,nb,nc;
int near1(int x,int y){
	if(set[x].lower_bound(y)!=set[x].end())return *set[x].lower_bound(y);
	else return *set[x].rbegin();
}
int near2(int x,int y){
	if(set[x].upper_bound(y)!=set[x].begin())return *--set[x].upper_bound(y);
	else return *set[x].begin();
}
long long ans;
void check(int x,int y,int z){
	ans=std::min(ans,1ll*(x-y)*(x-y)+1ll*(y-z)*(y-z)+1ll*(x-z)*(x-z));
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d",&na,&nb,&nc);
		for(int i=0;i<3;i++)set[i].clear();
		for(int i=1;i<=na;i++)scanf("%d",a+i),set[0].insert(a[i]);
		for(int i=1;i<=nb;i++)scanf("%d",b+i),set[1].insert(b[i]);
		for(int i=1;i<=nc;i++)scanf("%d",c+i),set[2].insert(c[i]);
		ans=3e18+1;
		for(int i=1;i<=na;i++){
			check(near1(1,a[i]),near1(2,a[i]),a[i]);
			check(near1(1,a[i]),near2(2,a[i]),a[i]);
			check(near2(1,a[i]),near1(2,a[i]),a[i]);
			check(near2(1,a[i]),near2(2,a[i]),a[i]);
		}
		for(int i=1;i<=nb;i++){
			check(near1(0,b[i]),near1(2,b[i]),b[i]);
			check(near1(0,b[i]),near2(2,b[i]),b[i]);
			check(near2(0,b[i]),near1(2,b[i]),b[i]);
			check(near2(0,b[i]),near2(2,b[i]),b[i]);
		}
		for(int i=1;i<=nc;i++){
			check(near1(1,c[i]),near1(0,c[i]),c[i]);
			check(near1(1,c[i]),near2(0,c[i]),c[i]);
			check(near2(1,c[i]),near1(0,c[i]),c[i]);
			check(near2(1,c[i]),near2(0,c[i]),c[i]);
		}
		printf("%lld\n",ans);
	}
}