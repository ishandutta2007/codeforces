#include <cstdio>

int size[400001],n,head[400001],nxt[800001],b[800001],k,dfn[400001],mx[400001],se[4000001],lim,ans[400001],now;
int max(int a,int b){return a>b?a:b;}
void update(int root,int l,int r,int e,int x){
	if(l==r)return (void)(se[root]=x);
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
	se[root]=max(se[root<<1],se[root<<1|1]);
}
int query(int root,int l,int r,int el,int er){
	if(el>er)return 0;
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	return max(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f){
	size[x]=1;
	dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			size[x]+=size[b[i]];
		}
	mx[x]=now;
	if(size[x]<lim)update(1,1,n,dfn[x],size[x]);
}
void dfs2(int x,int f,int Mx){
	bool cando=0;
	ans[x]=1;
	if(n-size[x]>=lim){
		cando=1;
		if(max(max(query(1,1,n,1,dfn[x]-1),query(1,1,n,mx[x]+1,n)),Mx)<=n-size[x]-lim)ans[x]=0;
	}
	else Mx=max(Mx,n-size[x]);
	if(size[x]<lim)update(1,1,n,dfn[x],0);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs2(b[i],x,Mx);
			if(ans[x]&&size[b[i]]>=lim){
				if(cando)ans[x]=0;
				cando=1;
				if(query(1,1,n,dfn[b[i]],mx[b[i]])<=size[b[i]]-lim)ans[x]=0;
			}
		}
	if(size[x]<lim)update(1,1,n,dfn[x],size[x]);
}
int main(){
	scanf("%d",&n);
	lim=(n>>1)+1;
	for(int i=1,s,t;i<n;i++){
		scanf("%d%d",&s,&t);
		push(s,t);
		push(t,s);
	}
	dfs1(1,0);
	dfs2(1,0,0);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}