#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int T,n,m,dep[510000],fa[510000],lst[510000];
int ans; pii Ans[510000];
vector<int> vec[510000];
void dfs(int u,int f){
	dep[u]=dep[f]+1; fa[u]=f;
	for (int v:vec[u])
		if (!dep[v]) dfs(v,u);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		int u,v;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		dfs(1,0);
		bool flag=false;
		for (int i=1;i<=n;i++)
			if (dep[i]>=((n+1)>>1)){
				puts("PATH"); flag=true;
				
				int u=i;
				printf("%d\n",dep[u]);
				while (u){
					printf("%d ",u);
					u=fa[u];
				}
				putchar('\n');
				break;
			}
		if (!flag){
			puts("PAIRING");
			ans=0;
			for (int i=1;i<=n;i++)
				if (lst[dep[i]]) Ans[++ans]=pii(lst[dep[i]],i),lst[dep[i]]=0;
				else lst[dep[i]]=i;
			for (int i=1;i<=n;i++) lst[i]=0;

			printf("%d\n",ans);
			assert((ans<<1)>=((n+1)>>1));
			for (int i=1;i<=ans;i++) printf("%d %d\n",Ans[i].first,Ans[i].second);
		}
		for (int i=1;i<=n;i++) vec[i].clear(),dep[i]=0;
	}
	return 0;
}