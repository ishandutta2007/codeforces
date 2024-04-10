//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=755,maxs=1e7+5;
string t[maxn];
char s[maxs];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int tot,to[maxs][2],tag[maxs];
void ins(int len,int id){
	int k=0;
	for(int i=1;i<=len;i++){
		int c=s[i]-'a';
		if(!to[k][c])to[k][c]=++tot;
		k=to[k][c];
	}
	tag[k]=id;
	return ;
}
queue<int> q;
int fail[maxs];
void init(){
	if(to[0][0])q.push(to[0][0]);
	if(to[0][1])q.push(to[0][1]);
	while(q.size()){
		int k=q.front();
		q.pop();
		for(int i=0;i<2;i++){
			int tmp=to[k][i];
			if(tmp)fail[tmp]=to[fail[k]][i],q.push(tmp);
			else to[k][i]=to[fail[k]][i];
		}
	}
	return ;
}
int f[maxs];
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
int g[maxn][maxn];
vec e[2*maxn];
int p[2*maxn];
bool vis[2*maxn];
bool dfs(int x){
	for(auto y:e[x]){
		if(vis[y])continue;
		vis[y]=1;
		if(!p[y]||dfs(p[y])){
			p[x]=y,p[y]=x;
			return 1;
		}
	}
	return 0;
}
void dfs1(int x){
	vis[x]=1;
	for(auto y:e[x]){
		if(vis[y])continue;
		vis[y]=1;
		dfs1(p[y]);
	}
	return ;
}
int main(){
    int n;
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		ins(len,i);
		t[i]=s+1;
	}
	init();
	for(int i=1;i<=tot;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		int len=t[i].size(),k=0;
		for(int j=0;j<len;j++){
			k=to[k][t[i][j]-'a'];
			int x=k;if(j==len-1)x=fail[k];
			while(x&&!tag[find(x)])x=f[find(x)]=fail[find(x)];
			g[i][tag[find(x)]]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(j==i||j==k)continue;
				g[i][j]|=(g[i][k]&g[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(g[i][j])e[i].eb(j+n);
	int match=0;
	for(int i=1;i<=n;i++)if(!p[i]){memset(vis,0,sizeof(vis)),match+=dfs(i);}
	printf("%d\n",n-match);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)if(!p[i])dfs1(i);
	for(int i=1;i<=n;i++)if(vis[i]&&!vis[i+n])printf("%d ",i);
	puts("");
    return 0;
}