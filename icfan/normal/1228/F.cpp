#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Maxn (1<<17)
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int x[Maxn+5];
int sz[Maxn+5],deg[Maxn+5];
int mx_sz[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int ans[Maxn+5];
int ans_len;
int now_ans;
bool find_ans;
void init_dfs(int u,int fa){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		if(arrive[i]==fa){
			continue;
		}
		init_dfs(arrive[i],u);
		sz[u]+=sz[arrive[i]];
		mx_sz[u]=mx(mx_sz[u],sz[arrive[i]]);
	}
	mx_sz[u]=mx(mx_sz[u],n-sz[u]);
}
void work_dfs(int u,int fa){
	for(int i=head[u];i;i=nxt[i]){
		if(arrive[i]==fa){
			continue;
		}
		deg[u]++;
		work_dfs(arrive[i],u);
	}
	if(deg[u]==0){
		sz[u]=1;
		return;
	}
	int len=0;
	for(int i=head[u];i;i=nxt[i]){
		if(arrive[i]==fa){
			continue;
		}
		x[++len]=sz[arrive[i]];
	}
	sort(x+1,x+1+len);
	if(len==1){
		if(x[1]==1){
			now_ans=u;
		}
		else{
			find_ans=0;
		}
		sz[u]=3;
	}
	if(len==2){
		if(x[1]!=x[2]){
			find_ans=0;
		}
		sz[u]=x[1]+x[2]+1;
	}
	if(len==3){
		if(x[1]+x[2]+1==x[3]){
			now_ans=u;
		}
		else{
			find_ans=0;
		}
		sz[u]=(x[3]<<1|1);
	}
}
void work(int root){
	memset(deg,0,sizeof deg);
	memset(sz,0,sizeof sz);
	find_ans=1;
	now_ans=-1;
	work_dfs(root,0);
	if(sz[root]!=n+1){
		find_ans=0;
	}
	if(now_ans!=-1&&find_ans){
		ans[++ans_len]=now_ans;
	}
}
int main(){
	scanf("%d",&n);
	n=(1<<n);
	n-=2;
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs(1,0);
	int minn=(1<<30);
	for(int i=1;i<=n;i++){
		minn=mn(minn,mx_sz[i]);
	}
	for(int i=1;i<=n;i++){
		if(minn==mx_sz[i]){
			work(i);
		}
	}
	sort(ans+1,ans+1+ans_len);
	int num=0;
	for(int i=1;i<=ans_len;i++){
		if(ans[i]!=ans[i-1]){
			num++;
		}
	}
	printf("%d\n",num);
	for(int i=1;i<=ans_len;i++){
		if(ans[i]!=ans[i-1]){
			printf("%d ",ans[i]);
		}
	}
	puts("");
	return 0;
}