#include <cstdio>
#include <algorithm>

int t,n;
char a[100001],b[100001];
int st[20];
bool cando[1048576],vis[20];
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	for(int i=0;i<20;i++)
		if((st[i]&(1<<x))||(st[x]&(1<<i)))dfs(i);
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%s%s",&n,a+1,b+1);
		for(int i=0;i<20;i++)st[i]=vis[i]=0;
		for(int i=1;i<=n;i++)if(a[i]!=b[i])st[a[i]-'a']|=1<<(b[i]-'a');
		cando[0]=1;
		int ans=0;
		for(int i=1;i<(1<<20);i++){
			cando[i]=0;
			for(int j=0;j<20;j++)
				if(i&(1<<j))
					cando[i]|=cando[i^(1<<j)]&&((i&st[j])==0);
			if(cando[i])ans=std::max(ans,__builtin_popcount(i));
		}
		ans=40-ans;
		for(int i=0;i<20;i++)
			if(!vis[i]){
				--ans;
				dfs(i);
			}
		printf("%d\n",ans);
	}
}