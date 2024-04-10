#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

int n;
long long K;
int size[100001],head[100001],nxt[200001],b[200001],k,mx[100001],root;
int d[100001],dfn[100001],dep[100001],now,Mx[100001],ord[100001];
int se[1000001];
int max(int a,int b){return dep[a]>dep[b]?a:b;}
void build(int root,int l,int r){
	if(l==r){
		se[root]=ord[l];
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=max(se[root<<1],se[root<<1|1]);
}
int query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	return max(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
void update(int root,int l,int r,int e){
	if(l==r){
		se[root]=0;
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e);
	else update(root<<1|1,((l+r)>>1)+1,r,e);
	se[root]=max(se[root<<1],se[root<<1|1]);
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void getroot(int x,int f){
	mx[x]=0,size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			getroot(b[i],x);
			size[x]+=size[b[i]];
			mx[x]=std::max(mx[x],size[b[i]]);
		}
	mx[x]=std::max(mx[x],n-size[x]);
	if(mx[x]<mx[root])root=x;
}
void dfs(int x,int f){
	size[x]=1;
	dfn[x]=++now;
	ord[now]=x;
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			size[x]+=size[b[i]];
		}
	Mx[x]=now;
}
std::priority_queue<std::pair<int,int> >heap;
std::vector<int>nleaf[100001],vec[100001];
bool vis[100001];
int con[100001][2],top;
void add(int u,int v){
	++top;
	con[top][0]=u;
	con[top][1]=v;
}
void del(int x){
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])--d[b[i]];
	d[x]=-1;
	update(1,1,n,dfn[x]);
}
bool cmp(int a,int b){return dep[a]<dep[b];}
int main(){
	scanf("%d%lld",&n,&K);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u),++d[u],++d[v];
	mx[0]=n;
	getroot(1,0);
	dep[0]=-1;
	dfs(root,0);
//	for(int i=1;i<=n;i++)printf("%d %d\n",i,dep[i]);
	long long sum=0;
	for(int i=1;i<=n;i++)sum+=dep[i];
	for(int i=head[root];i;i=nxt[i]){
		heap.push(std::make_pair(size[b[i]],b[i]));
		for(int j=dfn[b[i]];j<=Mx[b[i]];j++)nleaf[b[i]].push_back(ord[j]);
		vec[b[i]]=nleaf[b[i]];
		std::sort(nleaf[b[i]].begin(),nleaf[b[i]].end(),cmp);
	}
	build(1,1,n);
	for(;sum>K;){
		int now=heap.top().second,s=heap.top().first;
		heap.pop();
		while(!nleaf[now].empty()&&(d[nleaf[now].back()]<=1||2ll*dep[nleaf[now].back()]+K>sum)){
//			printf("%d ",nleaf[now].back());
			nleaf[now].pop_back();
		}
//	printf("*%lld %d\n",now,nleaf[now].size());
//		printf("%d\n",sum);
		if(nleaf[now].empty())break;
		int x=nleaf[now].back();
		sum-=2ll*dep[x];
		int p1=0,p2=0;
		while(head[x]&&vis[b[head[x]]])head[x]=nxt[head[x]];
		for(int i=head[x];i;i=nxt[i]){
			if(dep[b[i]]>=dep[x])(p1?p2:p1)=b[i];
			if(p2)break;
			while(nxt[i]&&vis[b[nxt[i]]])nxt[i]=nxt[nxt[i]];
		}
//		printf("%d %d %d\n",x,p1,p2);
//		assert(p1);
		if(p2){
//			assert(p1&&p2);
			int u=query(1,1,n,dfn[p2],Mx[p2]),v=query(1,1,n,dfn[p1],Mx[p1]);
			if(!u){
				for(int i=dfn[p2];i<=Mx[p2];i++)printf("%d ",vis[ord[i]]);putchar('\n');
				return 0;
			}
//			assert(u);
			del(u),del(v);
			add(u,v);
		}
		else{
			int u=query(1,1,n,dfn[p1],Mx[p1]);
//			assert(u);
			del(u),del(x);
			add(u,x);
		}
		if(s-2)heap.push(std::make_pair(s-2,now));
	}
	if(sum!=K){
		puts("NO");
		return 0;
	}
	while(!heap.empty())heap.pop();
	for(int i=1;i<=n;i++){
		nleaf[i]=vec[i];
		vec[i].clear();
		for(int j=0;j<(int)nleaf[i].size();j++)
			if(!vis[nleaf[i][j]])vec[i].push_back(nleaf[i][j]);
		if(vec[i].size())heap.push(std::make_pair(vec[i].size(),i));
	}
	vec[root].push_back(root);
	heap.push(std::make_pair(1,root));
	puts("YES");
//	return 0;
	for(int i=1;i<=top;i++)
		printf("%d %d\n",con[i][0],con[i][1]);
	while(!heap.empty()){
		auto now1=heap.top().second;
		heap.pop();
		auto now2=heap.top().second;
		heap.pop();
		printf("%d %d\n",vec[now1].back(),vec[now2].back());
		vec[now1].pop_back(),vec[now2].pop_back();
		if(vec[now1].size())heap.push(std::make_pair(vec[now1].size(),now1));
		if(vec[now2].size())heap.push(std::make_pair(vec[now2].size(),now2));
	}
}