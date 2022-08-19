#include <cstdio>

int n,m,k,t;
int d[70001],now[401],cnt,E[5001];
int match[70001][201],ans[5001];
void change(int x,int c1,int c2){
	if(!match[x][c1])return;
	int w=match[x][c1],y=E[w]^x;
	match[x][c1]=match[y][c1]=0;
	change(y,c2,c1);
	match[x][c2]=match[y][c2]=w;
	ans[w]=c2;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=1;i<=n+m;++i)now[i]=i;
	cnt=n+m;
	for(int i=1,u,v;i<=k;++i){
		scanf("%d%d",&u,&v);
		v+=n;
		E[i]=now[u]^now[v];
		++d[now[u]],++d[now[v]];
		int c1=0,c2=0;
		for(int i=1;i<=t;++i)
			if(!match[now[u]][i]){
				c1=i;
				break;
			}
		for(int i=1;i<=t;++i)
			if(!match[now[v]][i]){
				c2=i;
				break;
			}
		if(c1==c2){
			match[now[u]][c1]=match[now[v]][c1]=i;
			ans[i]=c1;
		}
		else{
			change(now[u],c2,c1);
			match[now[u]][c2]=match[now[v]][c2]=i;
			ans[i]=c2;
		}
		if(d[now[u]]==t)now[u]=++cnt;
		if(d[now[v]]==t)now[v]=++cnt;
	}
	int cnt=n+m;
	for(int i=1;i<=n+m;++i)if(!d[now[i]])--cnt;
	printf("%d\n",cnt);
	for(int i=1;i<=k;++i)printf("%d ",ans[i]);
}