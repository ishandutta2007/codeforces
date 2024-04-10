#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,m,s,t,u,v,ans;
bool vis[510000],Ans[510000];
struct node{
    int v,t,id;
};
vector<node> vec[510000];
void dfs1(int u){
	vis[u]=true; ans++;
	for (int i=0;i<(int)vec[u].size();i++){
		int v=vec[u][i].v,t=vec[u][i].t,id=vec[u][i].id;
		if (vis[v]) continue;
        if (t==1) dfs1(v);
        else if (t==2) Ans[id]=true,dfs1(v);
        else if (t==3) Ans[id]=false,dfs1(v);
	}
}
void dfs2(int u){
	vis[u]=true; ans++;
	for (int i=0;i<(int)vec[u].size();i++){
		int v=vec[u][i].v,t=vec[u][i].t,id=vec[u][i].id;
		if (vis[v]) continue;
        if (t==1) dfs2(v);
        else if (t==2) Ans[id]=false;
        else if (t==3) Ans[id]=true;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	int cnt=0;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&t,&u,&v);
		if (t==1) vec[u].push_back((node){v,1,0});
		else{
			cnt++;
			vec[u].push_back((node){v,2,cnt});
			vec[v].push_back((node){u,3,cnt});
		}
	}
	dfs1(s); printf("%d\n",ans);
    for (int i=1;i<=cnt;i++) putchar(Ans[i]?'+':'-' );
    printf("\n");
    ans=0; memset(vis,false,sizeof(vis));
	dfs2(s); printf("%d\n",ans);
    for (int i=1;i<=cnt;i++) putchar(Ans[i]?'+':'-' );
    printf("\n");
	return 0;
}