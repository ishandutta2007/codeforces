#include <bits/stdc++.h>

int n,m,A,B,con[201][3];
int head[71],nxt[401],b[401],v[401],k;
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
int dis[131072][71];
std::queue<std::pair<int,int> >q[2];
int siz[71],ind[71],cnt,ans[71];
int f[71];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
void add(int st,int p,int d,int i){
	if(dis[st][p]>d){
		dis[st][p]=d;
		ans[p]=std::min(ans[p],d);
		q[i].push(std::make_pair(st,p));
	}
}
int Dis(std::pair<int,int>x){return dis[x.first][x.second];}
int main(){
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=0x3fffffff;
	for(int i=1;i<=n;i++)ans[i]=0x3fffffff;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1,u,v,val;i<=m;i++){
		scanf("%d%d%d",&u,&v,&val);
		push(u,v,val);
		push(v,u,val);
		if(val==A){
			u=find(u),v=find(v);
			if(u!=v)f[u]=v;
		}
	}
	for(int i=1;i<=n;i++)++siz[find(i)];
	for(int i=1;i<=n;i++)
		if(!f[i]&&siz[i]>3)ind[i]=++cnt;
	memset(dis,0x7f7f7f7f,sizeof dis);
	add(ind[find(1)]?1<<(ind[find(1)]-1):0,1,0,0);
	while(!q[0].empty()||!q[1].empty()){
		std::pair<int,int>now=std::make_pair(0,0);
		if(!q[0].empty()&&Dis(now)>Dis(q[0].front()))now=q[0].front();
		if(!q[1].empty()&&Dis(now)>Dis(q[1].front()))now=q[1].front();
		if(!q[0].empty()&&now==q[0].front())q[0].pop();
		else q[1].pop();
		int v=Dis(now);
		for(int j=head[now.second];j;j=nxt[j]){
			int u=ind[find(b[j])];
			if(find(now.second)==find(b[j])&&::v[j]==B)continue;
			if(!u)add(now.first,b[j],v+::v[j],(::v[j]==B));
			else if(::v[j]==A||!(now.first&(1<<(u-1))))
				add(now.first|(1<<(u-1)),b[j],v+::v[j],(::v[j]==B));
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}