#include<cstdio>
#include<cstring>
using namespace std;
int T,n,cnt,sum[210];
bool vis[210],a[210][210];
char s[210],ans[210];
void dfs(int u,int fa){
	vis[u]=true; ans[++cnt]=(u+'a');
	for (int i=0;i<26;i++)
		if (a[u][i]&&i!=fa) dfs(i,u);
}
void work(){
	for (int i=0;i<26;i++){
		sum[i]=0;
		for (int j=0;j<26;j++) sum[i]+=a[i][j];
		if (sum[i]>2){
			puts("NO");
			return;
		}
	}
	cnt=0;
	for (int i=0;i<26;i++)
		if (!vis[i]&&sum[i]==1) dfs(i,-1);
	for (int i=0;i<26;i++)
		if (!vis[i]&&sum[i]){
			puts("NO");
			return;
		}
	for (int i=0;i<26;i++)
		if (!vis[i]) ans[++cnt]=(i+'a');
	puts("YES");
	for (int i=1;i<=26;i++) putchar(ans[i]);
	putchar('\n');
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1); n=strlen(s+1);
		memset(vis,false,sizeof(vis));
		memset(a,false,sizeof(a));
		for (int i=1;i<n;i++){
			a[s[i]-'a'][s[i+1]-'a']=true;
			a[s[i+1]-'a'][s[i]-'a']=true;
		}
		work();
	}
	return 0;
}