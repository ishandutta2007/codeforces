#include <cstdio>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int se[600001],size[150001],head[150001],nxt[300001],b[300001],k,son[150001],top[150001],fa[150001],lazy[600001],q,tem,dfn[150001],now,sum;
int c[2][150001],n,se2[600001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f){
	size[x]=1;
	fa[x]=f;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			if(size[son[x]]<size[b[i]])son[x]=b[i];
			size[x]+=size[b[i]];
		}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++now;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x]&&b[i]!=son[x])
			dfs2(b[i],b[i]);
}
void update(int root,int l,int r,int e,int x){
	se[root]=add(se[root],x);
	if(l==r)return;
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
}
void update2(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		se2[root]=add(se2[root],x);
		return;
	}
	update2(root<<1,l,(l+r)>>1,el,er,x);
	update2(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
int query(int root,int l,int r,int el,int er){
	if(el>er)return 0;
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	return add(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
int query2(int root,int l,int r,int e){
	if(l==r)return se2[root];
	if((l+r)>>1>=e)return add(se2[root],query2(root<<1,l,(l+r)>>1,e));
	else return add(se2[root],query2(root<<1|1,((l+r)>>1)+1,r,e));
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	int inv=qsm(n,P-2);
	for(int i=1,opt,v,d;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&v,&d);
			int orig=size[v];
			sum=add(sum,mul(size[v],d));
			update(1,1,n,dfn[v],mul(P+n-size[son[v]]-size[v],d));
			c[1][v]=add(c[1][v],d);
		}
		else{
			scanf("%d",&v);
			int ans=sum,v1=0;
			ans=add(ans,mul(P+n-size[v],c[1][v]));
			while(v){
				ans=add(ans,query(1,1,n,dfn[top[v]],dfn[v]-1));
				int u=fa[top[v]];
				ans=add(ans,mul(P+n-size[u]-size[top[v]],c[1][u]));
				v=fa[top[v]];
			}
			printf("%d\n",mul(ans,inv));
		}
	}
}