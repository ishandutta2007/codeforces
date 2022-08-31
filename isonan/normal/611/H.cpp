#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>

int n,w[10][10],cnt,deg[10],d[10],prufer[10],start[10],con[10][2],line[10][10],q[10001],h,t,dis[10001],p[1001],l[10][10][2],num[10],fin,size[10];
int node[10][10],_node[10],S,T,top;
std::set<int>set;
struct graph{
	int head[1001],nxt[40001],b[40001],v[40001],k=1;
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
		h=t=0;
		memset(dis,-1,sizeof dis);
		dis[S]=0;
		q[++t]=S;
		while(h<t){
			++h;
			for(int i=head[q[h]];i;i=nxt[i])
				if(!~dis[b[i]]&&v[i]){
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
			if(dis[b[i]]==dis[x]+1&&v[i]){
				int w=dfs(b[i],std::min(flow-used,v[i]));
				used+=w;
				v[i]-=w;
				v[i^1]+=w;
				if(w)p[x]=i;
				if(flow==used)return used;
			}
		if(!used)dis[x]=0;
		return used;
	}
}G1,G2;
int getque(){
	char ch=getchar();
	while(ch!='?')ch=getchar();
	int cnt=0;
	while(ch=='?')++cnt,ch=getchar();
	return cnt;
}
void dfs(int x){
	if(x>=cnt-1){
		memcpy(d,deg,sizeof d);
		set.clear();
		for(int i=1;i<=cnt;i++)if(!d[i])set.insert(i);
		for(int i=1;i<=cnt-2;i++){
			con[i][0]=prufer[i];
			set.erase(con[i][1]=*set.begin());
			if(!--d[con[i][0]])set.insert(con[i][0]);
			if(con[i][0]>con[i][1])con[i][0]^=con[i][1]^=con[i][0]^=con[i][1];
		}
		con[cnt-1][0]=*set.begin();
		con[cnt-1][1]=*set.rbegin();
		memcpy(&G2,&G1,sizeof G2);
		for(int i=1;i<cnt;i++)
			if(--G2.v[line[con[i][0]][con[i][1]]]<0)return;
//		for(int i=1;i<cnt;i++)printf("%d %d\n",start[con[i][0]],start[con[i][1]]);
//		for(int i=1;i<=cnt;i++)
//			for(int j=i+1;j<=cnt;j++)
//				printf("*%d %d %d %d %d\n",G2.v[line[i][j]],G2.v[l[i][j][0]],G2.v[l[i][j][1]],i,j);
		int ans=0;
		while(G2.bfs()){
			memcpy(p,G2.head,sizeof p);
			ans+=G2.dfs(S,0x7f7f7f7f);
		}
//		printf("!@ %d\n",ans);
		if(ans==fin){
			for(int i=1;i<cnt;i++)printf("%d %d\n",start[con[i][0]],start[con[i][1]]);
			for(int i=1;i<=cnt;i++)
				for(int j=i+1;j<=cnt;j++){
					for(int k=1;k<=0x7f7f7f7f-G2.v[l[i][j][0]];k++)
						printf("%d %d\n",++num[i],start[j]);
					for(int k=1;k<=0x7f7f7f7f-G2.v[l[i][j][1]];k++)
						printf("%d %d\n",++num[j],start[i]);
				}
			for(int i=1;i<cnt;i++)
				while(num[i]+1<start[i+1])printf("%d %d\n",++num[i],start[i]);
			while(num[cnt]<n)printf("%d %d\n",++num[cnt],start[cnt]);
			exit(0);
		}
		return;
	}
	for(int i=1;i<=cnt;i++)
		++deg[i],prufer[x]=i,dfs(x+1),--deg[i];
}

int main(){
	scanf("%d",&n);
	int tem=n;
	while(tem)tem/=10,++cnt;
	start[1]=1;
	for(int i=1;start[i]<n;i++,start[i]=start[i-1]*10)size[i]=start[i]*9-1;
	size[cnt]=n-start[cnt];
	memcpy(num,start,sizeof num);
	fin=n-cnt;
	for(int i=1,s,t;i<n;i++){
		s=getque();
		t=getque();
		if(s>t)s^=t^=s^=t;
		if(s!=t)++w[s][t];
		else fin--,size[s]--;
	}
	for(int i=1;i<=cnt;i++)
		if(size[i]<0){
			puts("-1");
			return 0;
		}
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt;j++)
			node[i][j]=++top,G1.link(S,node[i][j],w[i][j]),line[i][j]=G1.k-1;
	for(int i=1;i<=cnt;i++)
		_node[i]=++top;
	T=++top;
	for(int i=1;i<=cnt;i++)G1.link(_node[i],T,size[i]);
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt;j++)
			G1.link(node[i][j],_node[i],0x7f7f7f7f),l[i][j][0]=G1.k-1,
			G1.link(node[i][j],_node[j],0x7f7f7f7f),l[i][j][1]=G1.k-1;
	dfs(1);
	puts("-1");
}