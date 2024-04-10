#include <algorithm>
#include <cstdio>
#include <bitset>
#include <set>

std::bitset<200001>b;
std::set<int>set[200001];
int n,m,top,size[200001],last;
int dfs(int x){
	int tot=1;
	b[x]=0;
	for(int i=b._Find_first();i<b.size()&&i<=n;i=b._Find_next(i))
		if(!set[x].count(i))
			tot+=dfs(i);
	return tot;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)b[i]=1;
	for(int i=1,s,t;i<=m;i++){
		scanf("%d%d",&s,&t);
		set[s].insert(t);
		set[t].insert(s);
	}
	for(int i=1;i<=n;i++)if(b[i])size[++top]=dfs(i);
	printf("%d\n",top);
	std::sort(size+1,size+top+1);
	for(int i=1;i<=top;i++)printf("%d ",size[i]);
}