#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
char s[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int tot=1,last=1;
int to[maxn<<1][26],len[maxn<<1],nxt[maxn<<1];
int sum[maxn<<1];
void extend(int c){
	int u=++tot,p=last;
	len[u]=len[p]+1;sum[u]=1;
	while(p&&to[p][c]==0){to[p][c]=u;p=nxt[p];}
	if(!p)nxt[u]=1;
	else{
		int d=to[p][c];
		if(len[d]==len[p]+1)nxt[u]=d;
		else{
			int v=++tot;
			for(int i=0;i<26;i++)to[v][i]=to[d][i];
			len[v]=len[p]+1;
			nxt[v]=nxt[d];nxt[d]=v;nxt[u]=v;
			while(p&&to[p][c]==d){to[p][c]=v;p=nxt[p];}
		}
	}
	last=u;
	return ;
}
struct Edge{
	int to,nxt;
}e[maxn<<1];
int cnt;
int head[maxn<<1];
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
long long ans;
void dfs(int x){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		dfs(tmp);
		sum[x]+=sum[tmp];
	}
	ans+=1ll*sum[x]*sum[x]*(len[x]-len[nxt[x]]);
	return ;
}
int main(){
	int tim;
	tim=read();
	while(tim--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=0;i<=tot;i++){
			len[i]=nxt[i]=sum[i]=0;
			for(int j=0;j<26;j++)to[i][j]=0;
		}
		tot=last=1;
		for(int i=1;i<=n;i++)extend(s[i]-'a');
		cnt=0;
		for(int i=1;i<=tot;i++)head[i]=-1;
		for(int i=2;i<=tot;i++)add(nxt[i],i);
		ans=0;
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}