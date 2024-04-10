#include <cstdio>
#include <algorithm>

int n,head[100001],nxt[200001],b[200001],k;
int f[100001][2],ans;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int F){
	int ch=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			dfs(b[i],x);
			++ch;
		}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			f[x][0]=std::max(f[x][0],std::max(f[b[i]][0],f[b[i]][1])+ch-1);
			f[x][1]=std::max(f[x][1],f[b[i]][0]);
		}
	++f[x][1];
	int mx=0,skdmx=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			int v=std::max(f[b[i]][0],f[b[i]][1]);
			if(mx<v)skdmx=mx,mx=v;
			else if(skdmx<v)skdmx=v;
		}
	ans=std::max(ans,mx+skdmx+ch-2+(F!=0));
	mx=skdmx=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			if(mx<f[b[i]][0])skdmx=mx,mx=f[b[i]][0];
			else if(skdmx<f[b[i]][0])skdmx=f[b[i]][0];
		}
	ans=std::max(ans,mx+skdmx+1);
	ans=std::max(ans,std::max(f[x][0]+(F!=0),f[x][1]));
//	printf("%d %d %d\n",x,f[x][0],f[x][1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	dfs(1,0);
	printf("%d\n",ans);
}