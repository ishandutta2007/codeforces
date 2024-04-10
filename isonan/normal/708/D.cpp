#include <bits/stdc++.h>

int n,m,e[101][4];
int head[110],nxt[1000001],b[1000001],v[1000001],c[1000001],k=1,S,T;
int flow[110],q[1000001],h,t,pre[110];
bool inq[110];
long long dis[110];
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
	for(int i=S;i<=T;i++)dis[i]=1e18,flow[i]=0x7f7f7f7f,inq[i]=0;
	h=t=0;
	q[++t]=S;
	dis[S]=0;
	while(h<t){
		inq[q[++h]]=0;
		for(int i=head[q[h]];i;i=nxt[i])
			if(v[i]&&dis[b[i]]>dis[q[h]]+c[i]){
				dis[b[i]]=dis[q[h]]+c[i];
				flow[b[i]]=std::min(flow[q[h]],v[i]);
				pre[b[i]]=i;
				if(!inq[b[i]])inq[b[i]]=1,q[++t]=b[i];
			}
	}
	return dis[T]!=1e18;
}
int main(){
	scanf("%d%d",&n,&m);
	long long ans=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<4;j++)scanf("%d",&e[i][j]);
		flow[e[i][0]]-=e[i][3];
		flow[e[i][1]]+=e[i][3];
		if(e[i][3]<=e[i][2]){
			link(e[i][1],e[i][0],e[i][3],1);
			link(e[i][0],e[i][1],e[i][2]-e[i][3],1);
			link(e[i][0],e[i][1],0x7f7f7f7f,2);
		}
		else{
			ans+=e[i][3]-e[i][2];
			link(e[i][1],e[i][0],e[i][3]-e[i][2],0);
			link(e[i][1],e[i][0],e[i][2],1);
			link(e[i][0],e[i][1],0x7f7f7f7f,2);
		}
	}
	link(1,n,0x7f7f7f7f,0);
	link(n,1,0x7f7f7f7f,0);
	S=0,T=n+1;
	for(int i=1;i<=n;i++){
		if(flow[i]>0)link(S,i,flow[i],0);
		else link(i,T,-flow[i],0);
	}
	while(spfa()){
		int tem=T;
		ans+=1ll*dis[T]*flow[T];
		while(tem!=S){
			v[pre[tem]]-=flow[T];
			v[pre[tem]^1]+=flow[T];
			tem=b[pre[tem]^1];
		}
	}
	printf("%lld\n",ans);
}