#include <bits/stdc++.h>

int n,m,head[201],nxt[4010],b[4010],v[4010],k=1,p[201];
int S,T,dis[210],q[210],h,t;
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
	for(int i=1;i<=n;i++)dis[i]=-1;
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
int cut(int S,int T){
	::S=S,::T=T;
	for(int i=2;i<=k;i+=2)v[i]+=v[i+1],v[i+1]=0;
	int ans=0;
	while(bfs()){
		memcpy(p,head,sizeof p);
		ans+=dfs(S,0x7f7f7f7f);
	}
	return ans;
}
struct point{
	int u,v,val;
}num[201];
int f[201],end[201],top;
int tot;
int find(int x){return f[x]?f[x]=find(f[x]):x;}
void build(std::vector<int>vec){
	if(vec.size()==1)return;
	int v=cut(vec[0],vec[1]);
	tot+=v;
	num[++top]=(point){vec[0],vec[1],v};
	std::vector<int>t1,t2;
	for(int i=0;i<vec.size();i++)
		if(!~dis[vec[i]])t1.push_back(vec[i]);
		else t2.push_back(vec[i]);
	build(t1);
	build(t2);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,val;i<=m;i++)scanf("%d%d%d",&u,&v,&val),link(u,v,val),link(v,u,val);
	std::vector<int>vec;
	for(int i=1;i<=n;i++)vec.push_back(i);
	build(vec);
	std::sort(num+1,num+top+1,[&](point a,point b){return a.val>b.val;});
	for(int i=1;i<=n;i++)end[i]=i;
	for(int i=1;i<=top;i++){
		int u=find(num[i].u),v=find(num[i].v);
		if(u>v)std::swap(u,v);
		nxt[end[u]]=v;
		end[u]=end[v];
		f[v]=u;
	}
	int tem=1;
	printf("%d\n",tot);
	for(int i=1;i<=n;i++)printf("%d ",tem),tem=nxt[tem];
}