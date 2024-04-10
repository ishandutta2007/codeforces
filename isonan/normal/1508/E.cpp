#include <cstdio>
#include <vector>
#include <algorithm>

int a[300001];
int head[300001],nxt[600001],b[600001],k;
int pri[300001],size[300001],lson[300001],rson[300001],val[300001];
void pushup(int x){
	size[x]=size[lson[x]]+size[rson[x]]+1;
}
void split(int now,int &x,int &y,int v){
	if(!now)x=y=0;
	else{
		if(size[lson[now]]+1<=v)x=now,split(rson[now],rson[now],y,v-size[lson[now]]-1);
		else y=now,split(lson[now],x,lson[now],v);
		pushup(now);
	}
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	if(pri[a]<pri[b]){
		rson[a]=merge(rson[a],b);
		pushup(a);
		return a;
	}
	else{
		lson[b]=merge(a,lson[b]);
		pushup(b);
		return b;
	}
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int n;
int dfn[300001],son[300001],Size[300001],top[300001],ord[300001],now;
int fa[300001],dep[300001];
bool nice[300001];
int mx[300001];
void dfs1(int x){
	Size[x]=1;
	mx[x]=a[x];
	for(int i=head[x];i;i=nxt[i]){
		fa[b[i]]=x;
		dep[b[i]]=dep[x]+1;
		dfs1(b[i]);
		Size[x]+=Size[b[i]];
		mx[x]=std::max(mx[x],mx[b[i]]);
		if(Size[son[x]]<Size[b[i]])son[x]=b[i];
	}
	if(mx[x]==a[x])nice[a[x]]=1;
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++now;
	ord[now]=x;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=son[x])dfs2(b[i],b[i]);
}
int d[300001];
int pos[300001];
int Out(int &rt,int x){
	int t1,t2,t3;
	split(rt,t1,t2,x-1);
	split(t2,t2,t3,1);
	rt=merge(t1,t3);
	return t2;
} 
void In(int &rt,int x,int s){
	int t1,t2;
	split(rt,t1,t2,s);
	rt=merge(t1,merge(x,t2));
}
int fin[300001],Top;
void debug(int x){
	if(!x)return;
	debug(lson[x]);
	fin[++Top]=val[x];
	debug(rson[x]);
}
bool ok;
std::vector<std::pair<int,int> >vec[300001];
void check(int x){
	++now;
	if(fin[dfn[x]]!=now)ok=0;
std::vector<std::pair<int,int> >vec;
	for(int i=head[x];i;i=nxt[i])
		vec.push_back(std::make_pair(fin[dfn[b[i]]],b[i]));
	std::sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();++i)
		check(vec[i].second);
	std::reverse(vec.begin(),vec.end());
	::vec[x]=vec;
		
}
int c[300001];
void update(int ind,int num){
	for(;ind<=n;ind+=ind&-ind)c[ind]+=num;
}
int query(int ind){
	int tot=0;
	for(;ind;ind-=ind&-ind)tot+=c[ind];
	return tot;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i),pos[a[i]]=i;
	if(n==2){
		if(a[1]==1){
			puts("YES\n0\n1 2");
		}
		else puts("YES\n1\n1 2");
		return 0;
	}
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		push(u,v);
		++d[u],++d[v];
	}
	#include <random>
	std::mt19937 rnd(19260817);
	for(int i=1;i<=n;++i)pri[i]=rnd();
	dfs1(1);
	dfs2(1,1);
	int p=n;
	for(int i=1;i<=n;++i){
		if(!nice[i]){
			p=i;
			break;
		}
	}
//	printf("%d\n",p);
	long long ans=0;
	int root=0;
	for(int i=1;i<=n;++i){
		val[dfn[i]]=a[i];
		pushup(dfn[i]);
	}
	for(int i=1;i<=n;++i)root=merge(root,i);
	for(int i=p;i;--i){
		int tem=pos[i];
//		printf("%d\n",pos[i]);
		ans+=dep[tem];
		int last=0,Pos=dfn[tem];
		while(tem){
			int x=top[tem];
			int node=Out(root,dfn[tem]);
			if(last)In(root,node,Pos-2);
			else last=node;
			Pos=dfn[x];
			tem=fa[x];
		}
		In(root,last,0);
	}
		Top=0;
	debug(root);
//	for(int i=1;i<=n;++i)printf("%d ",fin[dfn[i]]);putchar('\n');
	now=0;
	ok=1;
	check(1);
	for(int i=1;i<=n;++i){
		if(vec[i].size()){
			update(dfn[vec[i].back().second],1);
			vec[i].pop_back();
		}
	}
	update(dfn[1],1);
	for(int i=1;i<=p;++i){
		int tem=pos[i];
		int val=0;
		while(tem){
			int x=top[tem];
			if(query(dfn[tem])-query(dfn[x]-1)!=dfn[tem]-(dfn[x]-1)){
				ok=0;
			}
			tem=fa[x];
		}
		update(dfn[pos[i]],-1);
		int x=fa[pos[i]];
		if(vec[x].size()){
			update(dfn[vec[x].back().second],1);
			vec[x].pop_back();
		}
	}
	if(ok){
		puts("YES");
		printf("%lld\n",ans);
		for(int i=1;i<=n;++i)printf("%d ",fin[dfn[i]]);putchar('\n');
	}
	else puts("NO");
}