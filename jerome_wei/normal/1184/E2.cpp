#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e6+5;
int n,m;
struct edge{
	int id,u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator < (const edge b)const{return w<b.w;}
}e[N],e2[N];int cur;
bool cmp(const edge a,const edge b){
	return a.id<b.id;
}
int fa[N],itt[N],sz[N];
inline int find(int x){
	return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	int u=find(x),v=find(y);
	if(u==v)return ;
	fa[u]=v;
}
bool ch[N];
inline void setup(){
	for(int i=1;i<=n;i++)fa[i]=i,itt[i]=i;
}
vector<int> node[N];
vector<edge> qry[N];
int ans[N];

inline void merge2(int u,int v,int e_val){
	int d1=find(u),d2=find(v);
	if(sz[d1] > sz[d2])swap(d1,d2);
	for(size_t t=0;t<node[d1].size();t++){
		int nd=node[d1][t];
		for(size_t i=0;i<qry[nd].size();i++){
			edge e=qry[nd][i];
			int X=find(e.u),Y=find(e.v);
			if((X==d2&&Y==d1)||(X==d1&&Y==d2)){
				ans[e.id]=e_val;
			}
		}
		if(qry[nd].size())node[d2].push_back(nd);
	}
	fa[d1]=d2;
	sz[d2]+=sz[d1];
}
 
int main()
{
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].id=i;
	}
	sort(e+1,e+m+1);
	setup();
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans[e[i].id]=-1;
			e2[++cur]=e[i];
			ch[e[i].id]=1;
			merge(e[i].u,e[i].v);
		}
		else{
			qry[e[i].u].push_back(e[i]);
			qry[e[i].v].push_back(e[i]);
			sz[e[i].u]++,sz[e[i].v]++;
		}
	}
	setup();
	for(int i=1;i<=n;i++)node[i].push_back(i);
	for(int i=1;i<n;i++){
		merge2(e2[i].u,e2[i].v,e2[i].w);
	}
	for(int i=1;i<=m;i++){
		if(ans[i]!=-1)printf("%d\n",ans[i]);
	}
}