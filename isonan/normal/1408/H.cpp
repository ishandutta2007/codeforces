#include <algorithm>
#include <cstdio>
#include <set>

std::multiset<int>set;
int L[500001],R[500001],n,a[500001],T;
struct point{
	int l,r;
}num[500001];
bool cmp(point a,point b){return (a.l>b.l);}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)L[i]=R[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i),cnt+=(a[i]==0);
		for(int i=1,now=0;i<=n;i++)
			if(!a[i])++now;
			else{
				if(now<(cnt>>1))L[a[i]]=now;
				else R[a[i]]=std::max(R[a[i]],cnt-now);
			}
		for(int i=1;i<=n;i++)num[i]=(point){L[i],R[i]};
		std::sort(num+1,num+n+1,cmp);
		int ans=0;
		set.clear();
		int now=1;
		for(int i=cnt>>1;i;i--){
			while(now<=n&&num[now].l>=i){
				set.insert(num[now].r);
				++now;
			}
			if(!set.empty()){
				++ans;
				set.erase(set.find(*set.begin()));
			}
		}
		while(now<=n)set.insert(num[now++].r);
		for(int i=cnt>>1;i;i--){
			if(!set.empty()&&*set.rbegin()>=i){
				set.erase(set.find(*set.rbegin()));
				++ans;
			}
		}
		printf("%d\n",std::min(ans,cnt>>1));
	}
}