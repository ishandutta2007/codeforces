#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5,maxm=1e6+5,mod=998244353,base=233;
int n;
char s[maxn],t[maxm];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int last=1,tot=1;
int len[2*maxn],nxt[2*maxn];
int to[2*maxn][27];
int siz[2*maxn];
void extend(int c){
	int p=last,u=++tot;
	len[u]=len[p]+1;siz[u]=1;
	while(p&&!to[p][c])to[p][c]=u,p=nxt[p];
	if(!p)nxt[u]=1;
	else{
		int d=to[p][c];
		if(len[d]==len[p]+1)nxt[u]=d;
		else{
			int v=++tot;
			len[v]=len[p]+1;
			for(int i=0;i<26;i++)to[v][i]=to[d][i];
			nxt[v]=nxt[d];nxt[d]=v;nxt[u]=v;
			while(p&&to[p][c]==d)to[p][c]=v,p=nxt[p];
		}
	}
	last=u;
	return ;
}
struct Edge{
	int to,nxt;
}e[2*maxn];
int cnt;
int head[2*maxn];
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
void dfs(int x){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		dfs(tmp);
		siz[x]+=siz[tmp];
	}
	return ;
}
map<int,bool>mp;
inline int add(int x){
	if(x>=mod)x-=mod;
	return x;
}
inline int sub(int x){
	if(x<0)x+=mod;
	return x;
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)extend(s[i]-'a');
	memset(head,-1,sizeof(head));
	for(int i=2;i<=tot;i++)add(nxt[i],i);
	dfs(1);
	int T,m;
	T=read();
	while(T--){
		scanf("%s",t+1);m=strlen(t+1);
		int p=1,h=0,pw=1,l=0;
		for(int i=1;i<=m;i++){
			int c=t[i]-'a';
			while(p&&!to[p][c])p=nxt[p],l=len[p];
			if(!p)break;
			p=to[p][c];l++;
			h=add(1ll*h*base%mod+c);
			if(i<m)pw=1ll*pw*base%mod;
		}
		if(!p){puts("0");continue;}
		ll ans=0;
		if(l>=m)ans+=siz[p];
		mp.clear();
		mp[h]=1;
		for(int i=1;i<m;i++){
			int c=t[i]-'a';
			while(p&&!to[p][c])p=nxt[p],l=len[p];
			p=to[p][c];l++;
			while(p&&len[nxt[p]]+1>m)p=nxt[p],l=len[p];
			h=add(1ll*sub(h-1ll*pw*c%mod)*base%mod+c);
			if(l>=m)if(!mp[h]){mp[h]=1;ans+=siz[p];}
		}
		printf("%d\n",ans);
	}
	return 0;
}