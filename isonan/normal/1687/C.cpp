#include <bits/stdc++.h>

int t;
int n,m,a[200001],b[200001],l[200001],r[200001];
long long S[200001],cnt[200001];
std::queue<int>q;
std::set<std::pair<int,int> >set;
std::set<int> set2;
void clear(int l,int r){
	// printf("clear %d %d\n",l,r);
	for(;;){
		int x=*set2.lower_bound(l);
		if(x<=r)set2.erase(x);
		else break;
	}
	for(;;){
		auto now=*set.lower_bound(std::make_pair(l,0));
		if(now.first<=r){
			// printf("del %d\n",now.second);
			if(!--cnt[now.second])q.push(now.second);
			set.erase(now);
		}
		else break;
	}
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		for(int i=1;i<=n;++i)scanf("%d",b+i);
		for(int i=1;i<=n;++i)S[i]=S[i-1]+a[i]-b[i];
		for(int i=1;i<=m;++i)scanf("%d%d",l+i,r+i),--l[i],cnt[i]=2;
		set.clear();
		set2.clear();
		for(int i=0;i<=n;++i)if(S[i])set2.insert(i);
		set2.insert(n+1);
		for(int i=1;i<=m;++i)set.insert(std::make_pair(l[i],i)),set.insert(std::make_pair(r[i],i));
		set.insert(std::make_pair(n+1,0));
		for(int i=0;i<=n;++i)
			if(S[i]==0){
				clear(i,i);
			}
		while(!q.empty()){
			int x=q.front();
			q.pop();
			clear(l[x],r[x]);
		}
		set2.erase(n+1);
		// for(int i=0;i<=n;++i)if(set2.count(i))printf("%d ",i);
		if(set2.empty())puts("yes");
		else puts("no");
	}
}