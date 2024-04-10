#include <cstdio>
#include <vector>
#include <algorithm>

int root[100001],lson[6000001],rson[6000001],cnt,n,m,se[6000001];
int fa[100001],head[100001],nxt[100001],b[100001],k,top[100001],size[100001],son[100001],dfn[100001],ord[100001],now,dep[100001];
int time[100001];
void add(int &pos,int pre,int l,int r,int e){
	pos=++cnt;
	lson[pos]=lson[pre];
	rson[pos]=rson[pre];
	se[pos]=se[pre]+1;
	if(l==r)return;
	if(((l+r)>>1)>=e)add(lson[pos],lson[pre],l,(l+r)>>1,e);
	else add(rson[pos],rson[pre],((l+r)>>1)+1,r,e);
}
int query(int pos,int l,int r,int el,int er){
	if(el>r||er<l||!pos)return 0;
	if(el<=l&&er>=r)return se[pos];
	return query(lson[pos],l,(l+r)>>1,el,er)+query(rson[pos],((l+r)>>1)+1,r,el,er);
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f){
	size[x]=1;
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=nxt[i]){
		dfs1(b[i],x);
		size[x]+=size[b[i]];
		if(size[son[x]]<size[b[i]])son[x]=b[i]; 
	}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++now;
	ord[now]=x;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=son[x])dfs2(b[i],b[i]);
}
int K;
int ans;
void find(int pos,int pre,int l,int r,int el,int er,bool dir){
	if(el>r||er<l)return;
	if(el<=l&&er>=r&&K>r-l+1-(se[pos]-se[pre]))return (void)(K-=r-l+1-(se[pos]-se[pre]));
	if(l==r)return (void)(ans=ord[l]);
	(dir)?find(rson[pos],rson[pre],((l+r)>>1)+1,r,el,er,dir):find(lson[pos],lson[pre],l,(l+r)>>1,el,er,dir);
	if(!~ans)(dir^1)?find(rson[pos],rson[pre],((l+r)>>1)+1,r,el,er,dir):find(lson[pos],lson[pre],l,(l+r)>>1,el,er,dir);
}
int main(){
	scanf("%d",&n);
	int rt=0;
	for(int i=1,tem;i<=n;i++){
		scanf("%d",&tem);
		fa[i]=tem;
		if(tem)push(tem,i);
		else rt=i;
	}
	dfs1(rt,0);
	dfs2(rt,rt);
	int m;
	scanf("%d",&m);
	for(int fd=1,t,a,b,k,y;fd<=m;fd++){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&a);
			time[a]=fd;
			add(root[fd],root[fd-1],1,n,dfn[a]);
		}
		else{
			root[fd]=root[fd-1];
			scanf("%d%d%d%d",&a,&b,&k,&y);
			int last=b;
			k+=(time[a]<=y);
			std::vector<std::pair<int,int> >tem1,tem2;
			while(top[a]!=top[b]){
				if(dep[top[a]]>dep[top[b]]){
					tem1.push_back(std::make_pair(dfn[a],dfn[top[a]]));
					a=fa[top[a]];
				}
				else{
					tem2.push_back(std::make_pair(dfn[top[b]],dfn[b]));
					b=fa[top[b]];
				}
			}
			tem1.push_back(std::make_pair(dfn[a],dfn[b]));
			for(int i=tem2.size()-1;~i;--i)tem1.push_back(tem2[i]);
			ans=-1;
			for(int i=0;i<tem1.size();i++){
				int l=tem1[i].first,r=tem1[i].second;
				bool dir=(l>r);
				if(dir)std::swap(l,r);
				int cnt=r-l+1-query(root[fd],1,n,l,r)+query(root[y],1,n,l,r);
				if(cnt<k)k-=cnt;
				else{
					::K=k;
					ans=-1;
					find(root[fd],root[y],1,n,l,r,dir);
					break;
				}
			}
			if(ans==last)puts("-1");
			else printf("%d\n",ans);
		}
	}
}