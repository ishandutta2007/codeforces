#include <cstdio>
#include <cstring>

int head[2000001],nxt[4000001],b[4000001],k,T,n,d[2000001],dep[2000001],o,e;
bool vis[2000001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
char str[500001];
void dfs(int x,int f){
	dep[x]=dep[f]^1;
	if(dep[x])o+=vis[x];
	else e+=vis[x];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x);
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d",&n);
		for(int i=1,s,t;i<n;i++){
			scanf("%d%d",&s,&t);
			push(s,t);
			push(t,s);
			++d[s];
			++d[t];
		}
		scanf("%s",str+1);
		int tem=n;
		for(int i=1;i<=tem;i++)
			if(str[i]=='W'){
				n+=3;
				push(i,n-2);
				push(n-2,n-1);
				push(n-2,n);
				++d[i];
				d[n-2]+=3;
				++d[n-1];
				++d[n];
			}
		bool cando=0;
		for(int i=1;i<=n;i++)
			if(d[i]>=4)cando=1;
			else if(d[i]==3){
				int cnt=0;
				for(int j=head[i];j;j=nxt[j])
					cnt+=(d[b[j]]==1);
				if(cnt<=1)cando=1;
				else vis[i]=1;
			}
		dfs(1,0);
		puts(cando||(e>1||o>1)?"White":"Draw");
		memset(head,0,(n+1)<<2);
		memset(d,0,(n+1)<<2);
		memset(vis,0,(n+1)<<2);
		k=e=o=0;
	}
}