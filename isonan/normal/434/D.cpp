#include <bits/stdc++.h>

int head[20001],nxt[2000001],b[2000001],v[2000001],k=1,p[20001];
int n,m,S,T,a[51],B[51],c[51],l[51],r[51],cnt,start[51];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void link(int s,int t,int val){
	push(s,t,val);
	push(t,s,0);
}
int q[20001],h,t,dis[20001];
bool bfs(){
	h=t=0;
	for(int i=S;i<=T;i++)dis[i]=-1;
	dis[S]=0;
	q[++t]=S;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if(v[i]&&!~dis[b[i]]){
				dis[b[i]]=dis[q[h]]+1;
				q[++t]=b[i];
				if(b[i]==T)return 1; 
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if(x==T||!flow)return flow;
	int used=0;
	for(int i=p[x];i;i=nxt[i])
		if(v[i]&&dis[b[i]]==dis[x]+1){
			int w=dfs(b[i],std::min(flow-used,v[i]));
			v[i]-=w;
			v[i^1]+=w;
			if(w)p[x]=i;
			used+=w;
			if(used==flow)return used;
		}
	if(!used)dis[x]=-1;
	return used;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d%d",a+i,B+i,c+i);
	T=n*210+1;
	for(int i=1;i<=n;i++){
		scanf("%d%d",l+i,r+i);
		link(S,++cnt,0x7f7f7f7f);
		start[i]=cnt;
		for(int j=l[i];j<=r[i];j++){
			link(cnt,cnt+1,2000000-(a[i]*j*j+B[i]*j+c[i]));
			++cnt;
		}
		link(cnt,T,0x7f7f7f7f);
	}
	for(int i=1,u,v,d;i<=m;i++){
		scanf("%d%d%d",&u,&v,&d);
		for(int j=l[v];j<=r[v];j++)
			if(j+d>=l[u]&&j+d<=r[u])link(start[u]+j+d+1-l[u],start[v]+j+1-l[v],0x7f7f7f7f);
			else if(j+d<l[u])link(S,start[v]+j+1-l[v],0x7f7f7f7f);
	}
	int ans=0;
	while(bfs()){
		memcpy(p,head,sizeof p);
		ans+=dfs(S,0x7f7f7f7f);
	}
	printf("%d\n",n*2000000-ans);
}