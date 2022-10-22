#include<bits/stdc++.h>
using namespace std;
int k,n,m,Q,fa[21][510000];
char s[510000],t[510000];
vector<int> que[510000],edge[510000],vec[510000];
struct Node{
	int l,r,pl,pr;
} q[510000];
struct node{
	int v,p;
	bool operator<(const node &a) const{ return v<a.v||v==a.v&&p>a.p;}
} nul,ans[510000];
struct SegmentTree{
	int tsize,ls[11000000],rs[11000000];
	node tree[11000000];
	void pushup(int now){
		tree[now]=max(tree[ls[now]],tree[rs[now]]);
	}
	void change(int &now,int l,int r,int x){
		if (!now) now=++tsize;
		if (l==r){
			tree[now].v++;
			tree[now].p=l;
			return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) change(ls[now],l,mid,x);
		else change(rs[now],mid+1,r,x);
		pushup(now);
	}
	int merge(int x,int y,int l,int r){
		if (!x||!y) return x|y;
		if (l==r){
			tree[x].v+=tree[y].v;
			tree[x].p=l;
			return x;
		}
		int mid=(l+r)>>1;
		ls[x]=merge(ls[x],ls[y],l,mid);
		rs[x]=merge(rs[x],rs[y],mid+1,r);
		pushup(x); return x;
	}
	node query(int now,int l,int r,int x,int y){
		if (!now) return nul;
		if (l==x&&r==y) return tree[now];
		int mid=(l+r)>>1;
		if (y<=mid) return query(ls[now],l,mid,x,y);
		else if (x>mid) return query(rs[now],mid+1,r,x,y);
		else return max(query(ls[now],l,mid,x,mid),query(rs[now],mid+1,r,mid+1,y));
	}
} T;
int rt[510000];
struct SAM{
	int z=1,cnt=1;
	int len[510000],link[510000],trans[510000][27];
	void extend(int c,int now){
		int v=z; z=++cnt; len[z]=len[v]+1;
		for (;v&&!trans[v][c];v=link[v]) trans[v][c]=z;
		if (!v) link[z]=1;
		else{
			int x=trans[v][c];
			if (len[x]==len[v]+1) link[z]=x;
			else{
				int y=++cnt; len[y]=len[v]+1;
				for (int i=0;i<=26;i++) trans[y][i]=trans[x][i];
				link[y]=link[x]; link[x]=link[z]=y;
				for (;v&&trans[v][c]==x;v=link[v]) trans[v][c]=y;
			}
		}
		T.change(rt[z],1,k,now);
	}
	void done(){
		for (int i=2;i<=cnt;i++){
			edge[link[i]].push_back(i);
			fa[0][i]=link[i];
		}
		for (int j=1;j<=20;j++)
			for (int i=2;i<=cnt;i++)
				fa[j][i]=fa[j-1][fa[j-1][i]];
	}
	void work(){
		int x=1,l=0;
		for (int i=1;i<=n;i++){
			int c=s[i]-'a';
			for (;x&&!trans[x][c];x=link[x],l=len[x]);
			if (trans[x][c]){
				x=trans[x][c]; l++;
				for (int v:vec[i]){
					int y=x;
					if (l<q[v].pr-q[v].pl+1) continue;
					for (int k=20;k>=0;k--)
						if (len[fa[k][y]]>=q[v].pr-q[v].pl+1) y=fa[k][y];
					que[y].push_back(v);
				}
			} else x=1,l=0;
		}
	}
} sam;
void dfs(int u){
	for (int v:edge[u]){
		dfs(v);
		rt[u]=T.merge(rt[u],rt[v],1,k);
	}
	for (int v:que[u]){
		ans[v]=T.query(rt[u],1,k,q[v].l,q[v].r);
	}
}
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	scanf("%d",&k);
	for (int i=1;i<=k;i++){
		scanf("%s",t+1); m=strlen(t+1);
		sam.z=1;
		for (int j=1;j<=m;j++) sam.extend(t[j]-'a',i);
	}
	sam.done();
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].pl,&q[i].pr);
		vec[q[i].pr].push_back(i);
	}
	sam.work();
	dfs(1);
	for (int i=1;i<=Q;i++){
		if (!ans[i].v) ans[i].p=q[i].l;
		printf("%d %d\n",ans[i].p,ans[i].v);
	}
	return 0;
}