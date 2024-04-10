#include <bits/stdc++.h>

int n,m,map[210][210];
int head[100001],nxt[2000001],b[2000001],v[2000001],p[100001],k=1;
int q[100001],h,t,dis[100001],S,T;
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
bool bfs(){
	for(int i=S;i<=T;i++)dis[i]=-1;
	dis[S]=0;
	h=t=0;
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
int read(){
	char ch=getchar();
	while(ch!='.'&&ch!='#')ch=getchar();
	return(ch=='#');
}
int hash(int i,int j){
	return (i-1)*m+j;
}
int main(){
	scanf("%d%d",&n,&m);
	T=n*m*2+1;
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=map[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(map[i][j]&&map[i+1][j])
				--ans,link(S,hash(i,j)+n*m,1);
			if(map[i][j]&&map[i][j+1]){
				--ans,link(hash(i,j),T,1);
				if(i>1)link(hash(i-1,j)+n*m,hash(i,j),0x7f7f7f7f);
				link(hash(i,j)+n*m,hash(i,j),0x7f7f7f7f);
				if(i>1&&j<m)link(hash(i-1,j+1)+n*m,hash(i,j),0x7f7f7f7f);
				if(j<m)link(hash(i,j+1)+n*m,hash(i,j),0x7f7f7f7f);
			}
		}
	while(bfs()){
		memcpy(p,head,sizeof p);
		ans+=dfs(S,0x7f7f7f7f);
	}
	printf("%d\n",ans);
}