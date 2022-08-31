// something
#include<bits/stdc++.h>
const int MAXN=500000;
int t,n;
int next[MAXN+5];
int tot_node;
struct node{
	int lc,rc;
}a[MAXN<<1];
std::vector<int>e[MAXN<<1];
int tp[MAXN<<1],deg[MAXN<<1],cnt;
int q[MAXN<<1],front,back;
int p[MAXN+5];
int new_node(int l,int r){
	return l==r?l:++tot_node;
}
void link(int u,int v){
	e[u].push_back(v);
	++deg[v];
}
void build(int p,int l,int r){
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(a[p].lc=new_node(l,mid),l,mid);
	build(a[p].rc=new_node(mid+1,r),mid+1,r);
	link(a[p].lc,p);
	link(a[p].rc,p);
}
void link_range(int v,int p,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)
		return link(p,v);
	if(l>qr||r<ql)
		return;
	int mid=(l+r)>>1;
	link_range(v,a[p].lc,l,mid,ql,qr);
	link_range(v,a[p].rc,mid+1,r,ql,qr);
}
int main(){
	scanf("%d",&t);
	for(;t;--t){
		scanf("%d",&n);
		tot_node=n;
		build(new_node(1,n),1,n);
		for(int i=1;i<=n;++i)
			scanf("%d",&next[i]);
		for(int i=1;i<=n;++i)
			if(next[i]!=-1){
				if(next[i]!=i+1)
					link_range(i,n+1,1,n,i+1,next[i]-1);
				if(next[i]!=n+1)
					link(i,next[i]);
			}
		cnt=0;
		front=1;
		back=0;
		for(int i=1;i<=tot_node;++i)
			if(!deg[i])
				q[++back]=i;
		while(front<=back){
			int u=q[front++];
			tp[++cnt]=u;
			for(auto v:e[u])
				if(!--deg[v])
					q[++back]=v;
		}
		if(cnt!=tot_node)
			puts("-1");
		else{
			cnt=0;
			for(int i=1;i<=tot_node;++i)
				if(tp[i]<=n)
					p[tp[i]]=++cnt;
			for(int i=1;i<=n;++i)
				printf("%d ",p[i]);
			puts("");
		}
		for(int i=1;i<=tot_node;++i){
			e[i].clear();
			deg[i]=0;
		}
	}
	return 0;
}