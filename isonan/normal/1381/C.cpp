#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>

std::set<std::pair<int,int> >set;
std::vector<int>pos[100010];
int t,n,x,y,cnt[1000010],a[1000010],fin[1000010];
bool exi[1000001],good[1000010];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d",&n,&x,&y);
		for(int i=1;i<=n+1;i++)exi[i]=0,pos[i].clear(),cnt[i]=0,good[i]=0;
		set.clear();
		for(int i=1;i<=n;i++)scanf("%d",a+i),pos[a[i]].push_back(i),exi[a[i]]=1,++cnt[a[i]];
		int r=0;
		for(int i=1;i<=n+1;i++)
			if(!exi[i])r=i;
			else set.insert(std::make_pair(cnt[i],i));
		for(int i=1;i<=n;i++)fin[i]=r;
		if(x>y){
			puts("NO");
			continue;
		}
		set.insert(std::make_pair(0,0));
		for(int i=1;i<=x;i++){
			int now=set.rbegin()->second;
			set.erase(*set.rbegin());
			--cnt[now];
			good[pos[now].back()]=1;
			pos[now].pop_back();
			if(cnt[now])set.insert(std::make_pair(cnt[now],now));
		}
		int canset=std::min((n-x-set.rbegin()->first)<<1,n-x);
		if(canset<y-x){
			puts("NO");
			continue;
		}
		if(set.size()>3&&(y-x)>=3&&(y-x)%2==1){
			int now1=set.rbegin()->second;
			set.erase(*set.rbegin());
			--cnt[now1];
			int now2=set.rbegin()->second;
			set.erase(*set.rbegin());
			--cnt[now2];
			int now3=set.rbegin()->second;
			set.erase(*set.rbegin());
			--cnt[now3];
			y-=3;
				fin[pos[now1].back()]=now3;
				fin[pos[now2].back()]=now1;
				fin[pos[now3].back()]=now2;
			pos[now1].pop_back();
			pos[now2].pop_back();
			pos[now3].pop_back();
			if(cnt[now1])set.insert(std::make_pair(cnt[now1],now1));
			if(cnt[now2])set.insert(std::make_pair(cnt[now2],now2));
			if(cnt[now3])set.insert(std::make_pair(cnt[now3],now3));
		}
		for(int res=y-x;res;){
//			printf("%d\n",set.size());
			int now1=set.rbegin()->second;
			set.erase(*set.rbegin());
			--cnt[now1];
			int now2=set.rbegin()->second;
			set.erase(*set.rbegin());
			--cnt[now2];
			if(res==1){
				fin[pos[now1].back()]=now2;
			}
			else{
				fin[pos[now1].back()]=now2;
				fin[pos[now2].back()]=now1;
			}
			pos[now1].pop_back();
			pos[now2].pop_back();
			res=std::max(res-2,0);
			if(cnt[now1])set.insert(std::make_pair(cnt[now1],now1));
			if(cnt[now2])set.insert(std::make_pair(cnt[now2],now2));
		}
		puts("YES");
		for(int i=1;i<=n;i++)
			if(good[i])printf("%d ",a[i]);
			else printf("%d ",fin[i]);
		putchar('\n');
	}
}