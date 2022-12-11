#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=201000,maxm=601000;
const ll INF=1ll<<50;
int n,m,s;
//
int head[maxn],nxt[maxm],rdc[maxm],tnt; 
ll dis[maxn],len[maxm];
bool vis[maxn];
priority_queue <pair<ll,int> > pq;
// 
int in[maxn];
vector <int> v[maxn],pv[maxn];
int q[maxn],qt,qe;
int dep[maxn],f[19][maxn],cnt[maxn],ans;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int up,int vp,int w){
	nxt[++tnt]=head[up];
	head[up]=tnt;
	rdc[tnt]=vp;
	len[tnt]=w;
}
void dijkstra(){
	for(register int i=1;i<=n;++i)
		dis[i]=INF;
	dis[s]=0;
	pq.push(make_pair(0,s));
	while(pq.size()){
		int p=pq.top().second;
		pq.pop();
		if(vis[p])continue;
		vis[p]=true;
		for(register int i=head[p];i;i=nxt[i])
			if(dis[rdc[i]]>dis[p]+len[i]){
				dis[rdc[i]]=dis[p]+len[i];
				pq.push(make_pair(-dis[rdc[i]],rdc[i]));
			}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(register int i=18;~i;--i)
		if((dep[x]-dep[y])>>i)
			x=f[i][x];
	if(x==y)return x;
	for(register int i=18;~i;--i)
		if(f[i][x]!=f[i][y])
			x=f[i][x],y=f[i][y];
	return f[0][x];
}
void toposort(){
	q[qe=0]=s;
	while(qt<=qe){
		int p=q[qt];
		++qt;
		dep[p]=dep[f[0][p]]+1;
		for(register int i=1;f[i-1][p];++i)
			f[i][p]=f[i-1][f[i-1][p]];
		for(register int i=0;i<v[p].size();++i){
			if(f[0][v[p][i]])
				f[0][v[p][i]]=lca(f[0][v[p][i]],p);
			else
				f[0][v[p][i]]=p;
			if(!(--in[v[p][i]]))
				q[++qe]=v[p][i];
		}
	}
}
void getans(){
	for(register int i=qe;i;--i){
		ans=max(ans,cnt[q[i]]+1);
		cnt[f[0][q[i]]]+=cnt[q[i]]+1;
	}
	printf("%d\n",ans);
}
int main(){
	n=read();m=read();s=read();
	for(register int i=0,up,vp,w;i<m;++i){
		up=read();vp=read();w=read();
		add(up,vp,w);add(vp,up,w);
	}
	dijkstra();
	for(register int i=1;i<=n;++i){
		if(dis[i]==INF||i==s)continue;
		for(register int j=head[i];j;j=nxt[j])
			if(dis[i]==dis[rdc[j]]+len[j]){
				v[rdc[j]].push_back(i);
				++in[i];
			}
	}
	toposort();
	getans();
	return 0;
}