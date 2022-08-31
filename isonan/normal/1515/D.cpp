#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

int t,n,l,r;
int cnt[2][200001];
std::multiset<int>set[2];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d%d",&n,&l,&r);
		for(int i=1;i<=n;++i)cnt[0][i]=cnt[1][i]=0;
		for(int i=1,tem;i<=l;++i){
			scanf("%d",&tem);
			++cnt[0][tem];
		}
		for(int i=1,tem;i<=r;++i){
			scanf("%d",&tem);
			++cnt[1][tem];
		}
		int ans=0;
		set[0].clear();set[1].clear();
		for(int i=1;i<=n;++i){
			int x=std::min(cnt[0][i],cnt[1][i]);
			cnt[0][i]-=x,cnt[1][i]-=x;
			l-=x,r-=x;
			if(cnt[0][i])set[0].insert(cnt[0][i]);
			if(cnt[1][i])set[1].insert(cnt[1][i]);
		}
		while(l>r){
			if(*set[0].rbegin()>1){
				int x=*set[0].rbegin();
				set[0].erase(set[0].find(x));
				set[0].insert(x-2);
				++ans;
				l-=2;
			}
			else{
				ans+=l-r;
				break;
			}
		}
		while(l<r){
			if(*set[1].rbegin()>1){
				int x=*set[1].rbegin();
				set[1].erase(set[1].find(x));
				set[1].insert(x-2);
				++ans;
				r-=2;
			}
			else{
				ans+=r-l;
				break;
			}
		}
		ans+=std::min(l,r);
		printf("%d\n",ans);
	}
}