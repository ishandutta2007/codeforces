#include <cstdio>
#include <algorithm>
#include <set>

int n,m,b[2000010];
long long a[2000010];
struct point{
	int pos,time;
}num[2000010];
bool cmp(point a,point b){
	return a.time<b.time;
}
int stk[2000010],t[2000010],top;
long long time(int j,int i){
//	printf("time %d %d %d\n",j,i,(a[i]-a[j]+i-j-1)/(i-j));
	return (a[i]-a[j]+i-j-1)/(i-j);
}
std::set<int>set;
std::multiset<int>ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),a[i]+=a[i-1];
	stk[++top]=0;
	for(int i=1;i<n;i++){
		while(top>1&&time(stk[top],i)<=time(stk[top-1],stk[top]))--top;
//		printf("%d\n",stk[top]);
//		printf("%d\n",time(stk[top],i));
		num[i]=(point){i,time(stk[top],i)};
		stk[++top]=i;
	}
	std::sort(num+1,num+n,cmp);
	int now=1;
	set.insert(0);
	set.insert(n);
	ans.insert(n);
	for(int i=1;i<=m;i++){
		scanf("%d",b+i);
		while(now<n&&num[now].time<=b[i]){
			int r=num[now].pos;
//			printf("*%d\n",r);
			int x=*set.upper_bound(r),y=*--set.upper_bound(r);
//			printf("%d %d\n",x,y);
			ans.erase(ans.find(x-y));
			ans.insert(x-r);
			ans.insert(r-y);
			set.insert(r);
			++now;
		}
		printf("%d ",(*ans.rbegin())-1);
	}
}