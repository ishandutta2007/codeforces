#include <cstdio>
#include <algorithm>

int n,K,ans,w[100010],g[100010],stk[100010],top,f[100010];
const long long inf=1000000000000000000ll;
struct point{
	long long mx1,mx2,totmx;
}se[500010];
long long lazy[500010],S1[100010],S2[100010];
void pushdown(int x,long long val){se[x].mx1+=val,se[x].totmx+=val,lazy[x]+=val;}
void spread(int root,int l,int r){
	if(l==r)return;
	if(lazy[root]){
		pushdown(root<<1,lazy[root]);
		pushdown(root<<1|1,lazy[root]);
		lazy[root]=0;
	}
}
long long getval(int root,int l,int r,long long x){
	spread(root,l,r);
	if(l==r)return se[root].mx2+x;
	if(se[root<<1].mx1<=x)return std::min(x+se[root<<1].mx2,getval(root<<1|1,((l+r)>>1)+1,r,x));
	else return std::min(se[root].totmx,getval(root<<1,l,(l+r)>>1,x));
}
void pushup(int root,int l,int r){
	se[root]=(point){
		std::max(se[root<<1].mx1,se[root<<1|1].mx1),
		std::min(se[root<<1].mx2,se[root<<1|1].mx2),
		getval(root<<1|1,((l+r)>>1)+1,r,se[root<<1].mx1)};
}
void build(int root,int l,int r){
	if(l==r){
		se[root]=(point){S2[l],-S2[l],inf};
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root,l,r);
}
void update(int root,int l,int r,int el,int er,long long x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x);
		return;
	}
	spread(root,l,r);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root,l,r);
}
point merge(point a,int root,int l,int r){
	return (point){
		std::max(a.mx1,se[root].mx1),
		std::min(a.mx2,se[root].mx2),
		std::min(a.totmx,getval(root,l,r,a.mx1))
	};
}
void query(int root,int l,int r,int el,int er,point &x){
	spread(root,l,r);
	if(el>r||er<l)return;
	if(el<=l&&er>=r)return (void)(x=merge(x,root,l,r));
	query(root<<1,l,(l+r)>>1,el,er,x);
	query(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
int head[100010],nxt[200010],b[200010],k,fa[100010][21];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int getmn(int root,int l,int r,int e,long long x){
	if(r<e)return n+1;
	spread(root,l,r);
	if(se[root].mx1<=x)return n+1;
	if(l==r)return l;
	int tem=getmn(root<<1,l,(l+r)>>1,e,x);
	if(tem==n+1)return getmn(root<<1|1,((l+r)>>1)+1,r,e,x);
	else return tem;
}
void dfs(int x){
	if(f[x]<=n&&x<=n&&f[x]>2)update(1,1,n,f[x]-1,n,S1[x]-S1[f[x]]);
	long long val=(f[x]==2)?S1[x]-S1[f[x]]:0;
	int tem=x;
	for(int i=20;~i;--i)
		if(S1[x]-S1[fa[tem][i]]<=K)tem=fa[tem][i];
	tem=f[tem]-1;
	for(;;){
		if(x+ans>tem)break;
		point now=(point){-inf,inf,inf},now2=(point){-inf,inf,inf};
		query(1,1,n,x,x+ans-1,now);
		now.totmx=inf;
		query(1,1,n,x+ans,tem,now);
		if(now.totmx+val<=K)++ans;
		else break;
	}
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i]);
	if(f[x]<=n&&x<=n&&f[x]>2)update(1,1,n,f[x]-1,n,S1[f[x]]-S1[x]);
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<n;i++)scanf("%d",w+i);
	for(int i=1;i<=n;i++)scanf("%d",g+i);
	for(int i=2;i<=n;i++)S1[i]=S1[i-1]-w[i-1]+g[i-1];
	for(int i=2;i<=n;i++)S2[i]=S2[i-1]-w[i-1]+g[i];
	stk[0]=n+1;
	S1[n+1]=-inf;
	build(1,1,n);
	for(int i=n;i;i--){
		while(top&&S1[stk[top]]>=S1[i])--top;
		push(stk[top],i);
		f[i]=stk[top];
		stk[++top]=i;
	}
	ans=1;
	for(int i=1;i<=n;i++)fa[i][0]=f[i];
	fa[n+1][0]=n+1;
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n+1;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1]; 
	dfs(n+1);
	printf("%d\n",ans);
}