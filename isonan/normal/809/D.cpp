#include <cstdio>
#include <random>

int n,lson[300010],rson[300010],key[300010],lazy[300010],pri[300010],root,size[300010];
void pushdown(int x,int y){
	if(!x)return;
	key[x]+=y;
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
	size[x]=size[lson[x]]+size[rson[x]]+1;
}
void split(int now,int &x,int &y,int v){
	if(!now)x=y=0;
	else{
		spread(now);
		if(key[now]<v)x=now,split(rson[now],rson[now],y,v);
		else y=now,split(lson[now],x,lson[now],v);
		pushup(now);
	}
}
void splits(int now,int &x,int &y,int s){
	if(!now)x=y=0;
	else{
		spread(now);
		if(size[lson[now]]+1<=s)x=now,splits(rson[now],rson[now],y,s-size[lson[now]]-1);
		else y=now,splits(lson[now],x,lson[now],s);
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
void dfs(int x){
	if(!x)return;
	spread(x);
	dfs(lson[x]);
	printf("%d ",key[x]);
	dfs(rson[x]);
}
int main(){
	scanf("%d",&n);
	std::mt19937 rnd(19260817);
	for(int i=1;i<=n+1;i++)pri[i]=rnd();
	root=n+1;
	key[root]=0;
	size[root]=1;
	for(int i=1,l,r;i<=n;i++){
		scanf("%d%d",&l,&r);
		int t1,t2,t3,t4;
		split(root,t1,t2,l);
		split(t2,t2,t3,r);
		if(t3)splits(t3,t4,t3,1);
		key[i]=l;
		size[i]=1;
		pushdown(t2,1);
		root=merge(merge(t1,i),merge(t2,t3));
	}
	printf("%d\n",size[root]-1);
}