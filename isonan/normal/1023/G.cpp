#include <cstdio>
#include <vector>
#include <random>
#include <algorithm>

int n,head[100001],nxt[200001],b[200001],v[200001],k,q;
std::vector<std::pair<int,int> >vec[100001];
int lson[400001],rson[400001],size[400001],cnt,pri[400001],lazy[400001],root[100001];
int stk[400001],top;
long long sum[400001];
struct info{
	int pos,val;
	void change(int x){
		if(val>=0)pos-=x;
		else pos+=x;
	}
}se[400001],l[400001],r[400001],mn[400001];
info min(info a,info b){return a.val<b.val?a:b;}
info merge(info b,info a){
//	printf("merge %d %d %d %d\n",b.pos,a.pos,b.val,a.val);
	if(a.val>=0&&b.val<0)return (info){b.pos,a.pos-b.pos};
	else return (info){0,0x7f7f7f7f};
}
void pushdown(int x,int y){
	if(!x)return;
	se[x].change(y);
	l[x].change(y);
	r[x].change(y);
	if(mn[x].val!=0x7f7f7f7f){
		mn[x].pos+=y;
		mn[x].val-=(y<<1);
	}
	lazy[x]+=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(lson[x],lazy[x]);
		pushdown(rson[x],lazy[x]);
		lazy[x]=0;
	}
}
void pushup(int x){
	l[x]=r[x]=se[x];
	mn[x]=(info){0,0x7f7f7f7f};
	if(lson[x]){
		l[x]=l[lson[x]];
		mn[x]=min(mn[x],min(mn[lson[x]],merge(r[lson[x]],se[x])));
	}
	if(rson[x]){
		r[x]=r[rson[x]];
		mn[x]=min(mn[x],min(mn[rson[x]],merge(se[x],l[rson[x]])));
	}
	size[x]=1+size[lson[x]]+size[rson[x]];
	sum[x]=1ll*se[x].val+sum[lson[x]]+sum[rson[x]];
}
void split(int now,int &x,int &y,int v){
	spread(now);
	if(!now)x=y=0;
	else{
		if(se[now].pos<=v)x=now,split(rson[now],rson[now],y,v);
		else y=now,split(lson[now],x,lson[now],v);
		pushup(now);
	}
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	spread(a),spread(b);
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
int Newnode(info x){
	int u=top?stk[top--]:++cnt;
	lson[u]=rson[u]=0;
	size[u]=1;
	lazy[u]=0;
	l[u]=r[u]=se[u]=x;
	mn[u]=(info){0,0x7f7f7f7f};
	sum[u]=x.val;
//	printf("Newnode %d %d %d\n",x.pos,x.val,u);
	return u;
}
void addr(int t1,int v){
	if(rson[t1])spread(t1),addr(rson[t1],v);
	else se[t1].val+=v;
	pushup(t1);
}
void addl(int t1,int v){
	if(lson[t1])spread(t1),addl(lson[t1],v);
	else se[t1].val+=v;
	pushup(t1);
}
void add(int &rt,info x){
	int t1,t2;
	split(rt,t1,t2,x.pos);
	if(t1&&r[t1].pos==x.pos)addr(t1,x.val);
	else t1=merge(t1,Newnode(x));
	rt=merge(t1,t2);
}
void Merge(int a,int &rt){
	if(!a)return;
	spread(a);
	add(rt,se[a]);
	Merge(lson[a],rt);
	Merge(rson[a],rt);
	stk[++top]=a;
}
void debug(int x){
	if(!x)return;
	spread(x);
	debug(lson[x]);
	printf("(%d %d %d)",se[x].pos,se[x].val,mn[x].val);
	debug(rson[x]);
}
void move(int &rt,int v){
	if(!rt)return;
//	printf("move %d\n",v);
//	debug(rt);putchar('\n');
	while(mn[rt].val<=(v<<1)){
		int t1,t2,t3;
//		printf("%d\n",mn[rt].val);
		split(rt,t1,t2,mn[rt].pos);
		if(r[t1].val+l[t2].val<0){
			addr(t1,l[t2].val);
			split(t2,t3,t2,l[t2].pos);
			stk[++top]=t3;
		}
		else{
			addl(t2,r[t1].val);
			split(t1,t1,t3,r[t1].pos-1);
			stk[++top]=t3;
		}
		rt=merge(t1,t2);
	}
	pushdown(rt,v);
//	debug(rt);putchar('\n');
}
long long f(int rt,long long v){
	if(!rt)return 0;
	spread(rt);
	if(se[rt].pos<=v)return sum[lson[rt]]+se[rt].val+f(rson[rt],v);
	else return f(lson[rt],v);
}
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void dfs(int x,int f,int v=0){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x,::v[i]);
			if(size[root[x]]<size[root[b[i]]])std::swap(root[x],root[b[i]]);
			Merge(root[b[i]],root[x]);
		}
	if(x==1){
		for(int i=0;i<vec[x].size();i++){
			add(root[x],(info){vec[x][i].first<<1,vec[x][i].second});
			add(root[x],(info){vec[x][i].first<<1|1,-vec[x][i].second});
		}
	}
	else{
		for(int i=0;i<vec[x].size();i++)vec[x][i].second+=::f(root[x],vec[x][i].first<<1ll);
		move(root[x],1);
		for(int i=0;i<vec[x].size();i++){
			long long tem=::f(root[x],vec[x][i].first<<1ll);
			if(tem<vec[x][i].second){
				add(root[x],(info){vec[x][i].first<<1,vec[x][i].second-tem});
				add(root[x],(info){vec[x][i].first<<1|1,-(vec[x][i].second-tem)});
			}
		}
		move(root[x],(v<<1)-1);
	}
//	printf("dfs %d\n",x);
//	debug(root[x]);putchar('\n');
}
long long now,ans;
void getans(int x){
	if(!x)return;
	spread(x);
	getans(lson[x]);
	ans=std::max(ans,now+=se[x].val);
	getans(rson[x]);
}
int main(){
	scanf("%d",&n);
	std::mt19937 rand(19260817);
	for(int i=1;i<=400000;i++)pri[i]=rand();
	for(int i=1,u,v,val;i<n;i++)scanf("%d%d%d",&u,&v,&val),push(u,v,val),push(v,u,val);
	scanf("%d",&q);
	for(int i=1,d,f,p;i<=q;i++){
		scanf("%d%d%d",&d,&f,&p);
		vec[p].push_back(std::make_pair(d,f));
	}
	dfs(1,0);
	getans(root[1]);
	printf("%lld\n",ans);
}