#include <cstdio>
#include <algorithm>

int head[100001],nxt[200001],b[200001],dis[200001],q[200001],v[200001],c[200001],h,t,n,m,S,T,k=1,Q,que[100001],pre[100001];
double ans[100001];
bool inq[100001];
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
	for(int i=S;i<=T;i++)dis[i]=0x7f7f7f7f,inq[i]=0;
	dis[S]=0;
	q[++t]=S;
	while(h<t){
		inq[q[++h]]=0;
		for(int i=head[q[h]];i;i=nxt[i])
			if(v[i]&&dis[b[i]]>dis[q[h]]+c[i]){
				dis[b[i]]=dis[q[h]]+c[i];
				pre[b[i]]=i;
				if(!inq[b[i]])inq[b[i]]=1,q[++t]=b[i];
			}
	}
	return dis[T]!=0x7f7f7f7f;
}
int main(){
	scanf("%d%d",&n,&m);
	S=1,T=n;
	for(int i=1,u,v,w;i<=m;i++)scanf("%d%d%d",&u,&v,&w),link(u,v,1,w);
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)scanf("%d",que+i),ans[i]=1e18;
	int f=0,c=0;
	while(spfa()){
		c+=dis[T];
		++f;
		int tem=T;
		while(tem!=S){
			v[pre[tem]]=0;
			v[pre[tem]^1]=1;
			tem=b[pre[tem]^1];
		}
		for(int i=1;i<=Q;i++)ans[i]=std::min(ans[i],(double)(c+que[i])/(double)f);
	}
	for(int i=1;i<=Q;i++)printf("%lf\n",ans[i]);
}