#include <cstdio>
#include <algorithm>

int n,head[100001],nxt[2000001],b[2000001],v[2000001],c[2000001],k=1,pre[100001],dis[100001],flow[100001],q[1000001],h,t,S,T,m;
int d[51],flo[51][51];
bool inq[100001],ans[51][51];
void push(int s,int t,int val,int cost){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
	c[k]=cost;
}
void link(int s,int t,int val,int cost){
	push(s,t,val,cost);
	push(t,s,0,-cost);
}
bool spfa(){
	h=t=0;
	for(int i=S;i<=T;i++)dis[i]=1000000000;
	dis[S]=0;
	flow[S]=0x7f7f7f7f;
	q[++t]=S;
	while(h<t){
		inq[q[++h]]=0;
		for(int i=head[q[h]];i;i=nxt[i])
			if(v[i]&&dis[b[i]]>dis[q[h]]+c[i]){
				dis[b[i]]=dis[q[h]]+c[i];
				flow[b[i]]=std::min(flow[b[i]],v[i]);
				pre[b[i]]=i;
				if(!inq[b[i]])inq[b[i]]=1,q[++t]=b[i]; 
			}
	}
	return dis[T]!=1000000000;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		++d[u];
		ans[u][v]=1;
	}
	T=n;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!ans[i][j]&&!ans[j][i]){
				++T;
				link(T,i,1,0);
				flo[i][j]=k-1;
				link(T,j,1,0);
				link(S,T,1,0);
			}
	++T;
	for(int i=1;i<=n;i++)
		for(int j=d[i];j<=n;j++)
			link(i,T,1,j);
	while(spfa()){
		int tem=T;
		while(tem!=S){
			--v[pre[tem]];
			++v[pre[tem]^1];
			tem=b[pre[tem]^1];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!ans[i][j]&&!ans[j][i])
				if(v[flo[i][j]])ans[j][i]=1;
				else ans[i][j]=1;
	for(int i=1;i<=n;i++,putchar('\n'))
		for(int j=1;j<=n;j++)
			printf("%d",ans[i][j]);
}