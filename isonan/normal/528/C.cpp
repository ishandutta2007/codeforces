#include <cstdio>
#include <vector>
#include <algorithm>

int head[100001],nxt[500010],b[500010],k=1,n,m,d[100001],stk[500010],top;
std::vector<std::pair<int,int> >ans;
bool vis[500010];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x){
	#define i head[x]
	for(;i;i=nxt[i]){
		if(!vis[i>>1]){
			stk[++top]=i^1;
			vis[i>>1]=1;
			dfs(b[i]);
		}
	}
	#undef i
	if(top){
		ans.push_back(std::make_pair(x,b[stk[top]]));
		if(ans.size()%2)std::swap(ans.back().first,ans.back().second);
		--top;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		push(u,v),push(v,u),++d[u],++d[v];
	}
	for(int i=1,last=-1;i<=n;i++)
		if(d[i]%2){
			if(~last)push(last,i),push(i,last),last=-1;
			else last=i;
		}
	if((k>>1)%2)push(1,1),push(1,1);
	dfs(1);
	printf("%d\n",k>>1);
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
}