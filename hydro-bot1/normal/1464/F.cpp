// Hydro submission #6331c8f75741ce022117406a@1664207095688
#include<bits/stdc++.h>
using namespace std;
int n,m,dfn,inf=0x3f3f3f3f,dep[200001],st[200001][21],ls[200001],rs[200001],cnt[200001];
vector <int> G[200001];
multiset <pair<int,int> > s;
struct spot{
	int x,y,val;
};
void get(int rt,int fa){
	ls[rt]=++dfn;
	dep[rt]=dep[fa]+1;
	st[rt][0]=fa;
	for(int i=1;i<=20;i++) st[rt][i]=st[st[rt][i-1]][i-1];
	for(int i=0;i<G[rt].size();i++){
		int to=G[rt][i];
		if(fa!=to) get(to,rt);
	}
	rs[rt]=dfn;
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--){
		if(dep[st[u][i]]>=dep[v]) u=st[u][i];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(st[u][i]!=st[v][i]){
			u=st[u][i];
			v=st[v][i];
		}
	}
	return st[u][0];
}
int dist(int u,int v){
	if(u==-1||v==-1) return -inf;
	int fa=lca(u,v);
	return dep[u]+dep[v]-2*dep[fa];
}
int find(int x,int k){
	for(int i=20;i>=0;i--){
		if((1<<i)<=k&&st[x][i]){
			k-=(1<<i);
			x=st[x][i];
		}
		else if((1<<i)<=k&&!st[x][i]) return 1;
	}
	return x;
}
spot merge(spot p,spot q){
	if(p.x==-1) return q;
	if(q.x==-1) return p;
	spot res=q;
	if(p.val>q.val) res=p;
	int a=dist(p.x,q.x),b=dist(p.x,q.y),c=dist(p.y,q.x),d=dist(p.y,q.y);
	if(res.val<a) res=spot{p.x,q.x,a};
	if(res.val<b) res=spot{p.x,q.y,b};
	if(res.val<c) res=spot{p.y,q.x,c};
	if(res.val<d) res=spot{p.y,q.y,d};
	return res;
}
struct SegmentTree{
	spot node[800001];
	void build(int rt,int l,int r){
		node[rt]=spot{-1,-1,-inf};
		if(l==r) return;
		int mid=(l+r)/2;
		build(rt*2,l,mid);
		build(rt*2+1,mid+1,r);
	}
	spot query(int rt,int l,int r,int L,int R){
		if(L<=l&&r<=R) return node[rt];
		int mid=(l+r)/2;
		if(R<=mid) return query(rt*2,l,mid,L,R);
		if(L>=mid+1) return query(rt*2+1,mid+1,r,L,R);
		return merge(query(rt*2,l,mid,L,R),query(rt*2+1,mid+1,r,L,R));
	}
	void updata(int rt,int l,int r,int id,int x,int pos){
		if(l==r&&l==id){
			if(pos==1) node[rt]=spot{x,x,0};
			else node[rt]=spot{-1,-1,-inf};
			return;
		}
		int mid=(l+r)/2;
		if(id<=mid) updata(rt*2,l,mid,id,x,pos);
		else updata(rt*2+1,mid+1,r,id,x,pos);
		node[rt]=merge(node[rt*2],node[rt*2+1]); 
	}
}t1;
struct TreeArray{
	int tree[800001];
	void add(int x,int n,int y){
		for(int i=x;i<=n;i+=i&-i) tree[i]+=y;
	}
	int ask(int x){
		int res=0;
		for(int i=x;i>=1;i-=i&-i) res+=tree[i];
		return res;
	}
}t2;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	get(1,0);
	t1.build(1,1,n);
	while(m--){
		int pos;
		scanf("%d",&pos);
		if(pos==1){
			int x,y;
			scanf("%d%d",&x,&y);
			int z=lca(x,y);
			t2.add(ls[x],n,1);
			t2.add(ls[y],n,1);
			t2.add(ls[z],n,-1);
			s.insert(make_pair(-dep[z],z));
			cnt[z]++;
			if(cnt[z]==1) t1.updata(1,1,n,ls[z],z,1);
		}
		else if(pos==2){
			int x,y;
			scanf("%d%d",&x,&y);
			int z=lca(x,y);
			t2.add(ls[x],n,-1);
			t2.add(ls[y],n,-1);
			t2.add(ls[z],n,1);
			s.erase(s.lower_bound(make_pair(-dep[z],z)));
			cnt[z]--;
			if(cnt[z]==0) t1.updata(1,1,n,ls[z],z,0);
		}
		else{
			int d;
			scanf("%d",&d);
			int x=find((*s.begin()).second,d),y=find(x,d);
			if(t2.ask(rs[y])-t2.ask(ls[y]-1)!=s.size()){
				printf("No\n");
				continue;
			}
			spot res=t1.query(1,1,n,ls[y],rs[y]);
			if(dist(res.x,x)<=d&&dist(res.y,x)<=d) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}