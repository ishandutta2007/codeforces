#include <cstdio>
#define int long long

int tag[8000001],lson[8000001],rson[8000001],cnt,root[50001],n,m,q,C,lazy[8000001];
int head[50001],nxt[50001],b[50001],k,dfn[50001],top[50001],now,fa[50001],size[50001],son[50001],f[50001],c[50001];
struct point{
	long long sqr_sum,sum;
}se[8000001];
void spread(int pos,long long x,long long length){
	if(!pos){
		pos=++cnt;
		se[pos]=(point){0,0};
		tag[pos]=0;
	}
	if(~tag[pos])tag[pos]+=x;
	se[pos]=(point){se[pos].sqr_sum+2ll*se[pos].sum*x+x*x*length,se[pos].sum+x*length};
	lazy[pos]+=x;
}
void update(int &pos,long long tg,int l,int r,int el,int er,long long x){
	if(!pos){
		pos=++cnt;
		se[pos]=(point){tg*tg*(r-l+1),tg*(r-l+1)};
		tag[pos]=tg;
	}
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		spread(pos,x,r-l+1);
		return;
	}
	if(lazy[pos]){
		spread(rson[pos],lazy[pos],r-((l+r)>>1));
		spread(lson[pos],lazy[pos],((l+r)>>1)-l+1);
		lazy[pos]=0;
	}
	update(lson[pos],tag[pos],l,(l+r)>>1,el,er,x);
	update(rson[pos],tag[pos],((l+r)>>1)+1,r,el,er,x);
	tag[pos]=(tag[lson[pos]]==tag[rson[pos]])?tag[lson[pos]]:-1;
	se[pos]=(point){se[lson[pos]].sqr_sum+se[rson[pos]].sqr_sum,se[lson[pos]].sum+se[rson[pos]].sum};
}
void dfs(int pos,int l,int r){
	if(lazy[pos]){
		spread(rson[pos],lazy[pos],r-((l+r)>>1));
		spread(lson[pos],lazy[pos],((l+r)>>1)-l+1);
		lazy[pos]=0;
	}
	if(!pos)return;
	printf("%d %d %d %d\n",l,r,se[pos].sqr_sum,se[pos].sum);
	dfs(lson[pos],l,(l+r)>>1);
	dfs(rson[pos],((l+r)>>1)+1,r);
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		dfs1(b[i]);
		size[x]+=size[b[i]];
		if(size[b[i]]>size[son[x]])son[x]=b[i];
	}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++now;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(son[x]!=b[i])dfs2(b[i],b[i]);
}
void update(int c,int x,int delta){
	while(x){
		update(root[c],0,1,n,dfn[top[x]],dfn[x],delta);
		x=fa[top[x]];
	}
}
signed main(){
//	freopen("CF960H.in","r",stdin);
//	freopen("CF960H.out","w",stdout);
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&q,&C);
	for(int i=1;i<=n;i++)scanf("%I64d",f+i);
	for(int i=2;i<=n;i++)scanf("%I64d",fa+i),push(fa[i],i);
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=m;i++)scanf("%I64d",c+i);
	for(int i=1;i<=n;i++)update(f[i],i,1);
	for(int i=1,opt,t1,t2;i<=q;i++){
		scanf("%I64d",&opt);
		if(opt==1){
			scanf("%I64d%I64d",&t1,&t2);
			update(f[t1],t1,-1);
			update(f[t1]=t2,t1,1);
		}
		else{
			scanf("%I64d",&t1);
			if(!root[t1]){
				printf("%6lf\n",(double)C*(double)C);
				continue;
			}
			double tem=se[root[t1]].sqr_sum*c[t1]*c[t1]-2ll*se[root[t1]].sum*c[t1]*C+C*C*n;
			printf("%.6lf\n",tem/(double)n);
		}
//		for(int i=1;i<=m;i++)printf("color %d:\n",i),dfs(root[i],1,n);
	}
}