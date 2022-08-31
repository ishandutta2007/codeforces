#include <cstdio>
#include <algorithm>

int K,n,head[200001],nxt[400001],b[400001],k,dis[200001],pre[200001],dep[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void getdis(int x,int f,int dist){
	if(dis[x])return;
	dis[x]=dist;
	pre[x]=f;
	for(int i=head[x];i;i=nxt[i])
		getdis(b[i],x,dist+1);
}
bool vis[200001];
int s[200001],top,col[200001];
void getans(int x,int f,int c=0){
	col[x]=c+1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getans(b[i],x,c^1);
}
void check(int x,int f,int l,int r,int cl,int cr){
	if(l>r)col[x]=cl;
	else col[x]=cr;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)
			check(b[i],x,l+1,r+1,cl==K?1:cl+1,cr==1?K:cr-1);
}
int mx[200001],pos[200001],smx[200001],mx3[200001];
void dfs1(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			if(mx[x]<mx[b[i]]+1)mx3[x]=smx[x],smx[x]=mx[x],mx[x]=mx[b[i]]+1,pos[x]=b[i];
			else if(smx[x]<mx[b[i]]+1)mx3[x]=smx[x],smx[x]=mx[b[i]]+1;
			else if(mx3[x]<mx[b[i]]+1)mx3[x]=mx[b[i]]+1;
		}
}
bool dfs2(int x,int f,int len){
	int a=mx[x],b=smx[x],c=mx3[x];
	if(c<len)c=len;
	if((a+b+1>=K&&b+c+1>=K&&a+c+1>=K)&&((a!=0)+(b!=0)+(c!=0))==3)return 0;
	for(int i=head[x];i;i=nxt[i])
		if(::b[i]!=f){
			int tem=std::max(len+1,(pos[x]==::b[i]?smx[x]:mx[x])+1);
			if(!dfs2(::b[i],x,tem))return 0;
		}
	return 1;
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1,s,t;i<n;i++){
		scanf("%d%d",&s,&t);
		push(s,t);
		push(t,s);
	}
	if(K==2){
		getans(1,0);
		puts("Yes");
		for(int i=1;i<=n;i++)printf("%d ",col[i]);
		return 0;
	}
	getdis(1,0,1);
	int mx=0,mx2=0;
	for(int i=1;i<=n;i++)if(dis[mx]<dis[i])mx=i;
	for(int i=1;i<=n;i++)dis[i]=0;
	getdis(mx,0,1);
	for(int i=1;i<=n;i++)if(dis[mx2]<dis[i])mx2=i;
	while(mx2)s[++top]=mx2,mx2=pre[mx2];
	for(int i=1;i<=top;i++)col[s[i]]=(i%K)+1,vis[s[i]]=1;
	for(int i=1;i<=top;i++)
		for(int j=head[s[i]];j;j=nxt[j])
			if(!vis[b[j]]){
				check(b[j],s[i],i+1,top-i+2,((i+1)%K)+1,((i-1)%K)+1);
			}
	dfs1(1,0);
	if(!dfs2(1,0,0)){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=n;i++)printf("%d ",col[i]);
}