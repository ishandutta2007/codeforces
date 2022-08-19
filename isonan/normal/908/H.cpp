#include <cstdlib>
#include <cstring>
#include <cstdio>

int f[10000001],n,lim,P=998244353,cnt,num[100],stat[100],size[100],g[10000001];
int head[100],nxt[20001],b[20001],k;
char map[100][100];
bool vis[100][100];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int find(int x){return f[x]?f[x]=find(f[x]):x;}
void FWT(int *a,bool b){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++)
				if(b)(a[i+j+k]+=a[j+k])%=P;
				else (a[i+j+k]+=P-a[j+k])%=P;
}
void dfs(int x,int orig){
	if(stat[orig]&(1<<(x-1)))return;
	stat[orig]|=(1<<(x-1));
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i],orig);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",map[i]+1);
	for(int i=1;i<=n;i++)size[i]=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(map[i][j]=='A'&&find(i)!=find(j))size[find(j)]+=size[find(i)],f[find(i)]=find(j);
	for(int i=1;i<=n;i++)if(!f[i]&&size[i]>1)num[i]=++cnt;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j]=='X'){
				if(find(i)==find(j)){
					puts("-1");
					return 0;
				}
				vis[num[find(i)]][num[find(j)]]=vis[num[find(j)]][num[find(i)]]=1;
			}
	for(int i=1;i<=cnt;i++)
		for(int j=i;j<=cnt;j++)
			if(!vis[i][j])stat[i]|=(1<<(j-1)),stat[j]|=(1<<(i-1));
	lim=1<<cnt;
	memset(f,0,lim<<2);
	f[0]=1;
	for(int i=0;i<lim;i++)
		if(f[i]){
			for(int j=1;j<=cnt;j++)
				if(!(i&(1<<(j-1)))&&((stat[j]&i)==i))f[i|(1<<(j-1))]=1;
		}
	FWT(f,1);
	memcpy(g,f,sizeof g);
	int ans=0,tem;
	for(int i=1;i<=cnt;i++){
		tem=0;
		for(int j=0;j<lim;j++)
			(tem+=(__builtin_popcount(j)%2)?(P-f[j]):f[j])%=P,f[j]=1ll*f[j]*g[j]%P;
		if(tem){
			ans=i;
			break;
		}
	}
	printf("%d\n",n-1+ans);
}