#include <bits/stdc++.h>

int n,m,e[1001][4];
int head[1010],nxt[1000001],b[1000001],v[1000001],c[1000001],k=1,S,T;
int flow[1010],q[1000001],h,t,pre[1010],SS,TT;
int edg[201][2],con[201][2],V[401];
char ans[201],get[401];
bool inq[1010];
long long dis[1010];
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
	for(int i=S;i<=TT;i++)dis[i]=1e18,flow[i]=0x7f7f7f7f,inq[i]=0;
	h=t=0;
	q[++t]=SS;
	dis[SS]=0;
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
	return dis[TT]!=1e18;
}
int Flow[100001],n1,n2,R,B;
int main(){
	scanf("%d%d%d%d%d",&n1,&n2,&m,&R,&B);
	T=n1+n2+1;
	for(int i=1;i<=n1;i++){
		char ch=getchar();
		while(ch<'A'||ch>'Z')ch=getchar();
		get[i]=ch;
		if(ch=='U')link(S,i,0x7f7f7f7f,0),link(i,T,0x7f7f7f7f,0);
		else if(ch=='R'){
			link(S,i,0x7f7f7f7f,0);
			--Flow[S];
			++Flow[i];
		}
		else{
			link(i,T,0x7f7f7f7f,0);
			++Flow[T];
			--Flow[i];
		}
	}
	for(int i=1;i<=n2;i++){
		char ch=getchar();
		while(ch<'A'||ch>'Z')ch=getchar();
		get[i+n1]=ch;
		if(ch=='U')link(S,i+n1,0x7f7f7f7f,0),link(i+n1,T,0x7f7f7f7f,0);
		else if(ch=='B'){
			link(S,i+n1,0x7f7f7f7f,0);
			--Flow[S];
			++Flow[i+n1];
		}
		else{
			link(i+n1,T,0x7f7f7f7f,0);
			++Flow[T];
			--Flow[i+n1];
		}
	}
	SS=T+1;
	TT=T+2;
	for(int i=S;i<=T;i++)
		if(Flow[i]>0)link(SS,i,Flow[i],0);
		else link(i,TT,-Flow[i],0);
	link(T,S,0x7f7f7f7f,0);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		con[i][0]=u;
		con[i][1]=v+n1;
		link(u,v+n1,1,R);
		edg[i][0]=k-1;
		link(v+n1,u,1,B);
		edg[i][1]=k-1;
	}
	long long ans=0;
	while(spfa()){
		int tem=TT;
		ans+=1ll*dis[TT]*flow[TT];
		while(tem!=SS){
			v[pre[tem]]-=flow[TT];
			v[pre[tem]^1]+=flow[TT];
			tem=b[pre[tem]^1];
		}
	}
	for(int i=1;i<=m;i++){
		if(!v[edg[i][0]])::ans[i]='R',++V[con[i][0]],++V[con[i][1]];
		else if(!v[edg[i][1]])::ans[i]='B',--V[con[i][0]],--V[con[i][1]];
		else ::ans[i]='U';
	} 
	for(int i=1;i<=n1+n2;i++)
		if(get[i]=='R'&&V[i]<=0||get[i]=='B'&&V[i]>=0){
			puts("-1");
			return 0;
		}
	printf("%lld\n",ans);
	for(int i=1;i<=m;i++)putchar(::ans[i]);
}