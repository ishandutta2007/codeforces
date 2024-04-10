#include <cstdio>
#include <cassert>
#include <algorithm>

int n,q;
int rt,cnt;
int ch[2][8000001],size[8000001],diff[8000001],val[8000001],lazy[8000001];
bool vis[8000001];
void pushup(int x){
	if(vis[x])return;
	if(!size[ch[0][x]]){
		size[x]=size[ch[1][x]];
		diff[x]=diff[ch[1][x]];
		val[x]=val[ch[1][x]];
	}
	else if(!size[ch[1][x]]){
		size[x]=size[ch[0][x]];
		diff[x]=diff[ch[0][x]];
		val[x]=val[ch[0][x]];
	}
	else{
		size[x]=size[ch[0][x]]+size[ch[1][x]];
		diff[x]=diff[ch[0][x]]|diff[ch[1][x]]|(val[ch[0][x]]^val[ch[1][x]]);
		val[x]=val[ch[0][x]]&val[ch[1][x]];
	}
}
void pushdown(int x,int y,int dep){
	if(~dep&&(y&(1<<dep)))std::swap(ch[0][x],ch[1][x]);
	val[x]=val[x]^y^(diff[x]&y);
	lazy[x]^=y;
}
void spread(int x,int dep){
	if(lazy[x]){
		pushdown(ch[0][x],lazy[x],dep-1);
		pushdown(ch[1][x],lazy[x],dep-1);
		lazy[x]=0;
	}
}
void add(int &pos,int dep,int v){
	if(!pos)pos=++cnt;
	if(!~dep){
		diff[pos]=0;
		val[pos]=v;
		size[pos]=1;
		vis[pos]=1;
		return;
	}
	add(ch[((v&(1<<dep))!=0)][pos],dep-1,v);
	pushup(pos);
}
void split(int now,int &x,int &y,int v,int dep){
	if(v<0){
		x=0,y=now;
		return;
	}
	spread(now,dep);
	if(!now)x=y=0;
	else if(!~dep)x=now,y=0;
	else{
		if(!(v&(1<<dep))){
			y=now;
			x=++cnt;
			split(ch[0][now],ch[0][x],ch[0][y],v,dep-1);
			pushup(x);
			pushup(y);
		}
		else{
			x=now;
			y=++cnt;
			split(ch[1][now],ch[1][x],ch[1][y],v,dep-1);
			pushup(x);
			pushup(y);
		}
	}
}
int merge(int a,int b,int dep){
	spread(a,dep),spread(b,dep);
	if(!a||!b)return a|b;
	if(!~dep)return a;
	ch[0][a]=merge(ch[0][a],ch[0][b],dep-1);
	ch[1][a]=merge(ch[1][a],ch[1][b],dep-1);
	pushup(a);
	return a;
}
int solve(int a,int dep,int val){
	spread(a,dep);
	if(!a)return a;
	if(!~dep)return a;
	int x=diff[a]&val;
	if(!x){
		pushdown(a,val^(val&::val[a]),dep);
		return a;
	}
	if(val&(1<<dep)){
		pushdown(ch[0][a],(1<<dep),dep-1);
		ch[1][a]=merge(ch[0][a],ch[1][a],dep-1);
		ch[0][a]=0;
	}
	solve(ch[0][a],dep-1,val);
	solve(ch[1][a],dep-1,val);
	pushup(a);
	return a;
}
void debug(int x,int dep){
	if(!x||!size[x])return;
	spread(x,dep);
	if(!~dep){
		printf("%d ",val[x]);
		return;
	}
	debug(ch[0][x],dep-1);
	debug(ch[1][x],dep-1);
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1,tem;i<=n;++i){
		scanf("%d",&tem);
		add(rt,19,tem);
	}
	for(int i=1,t,l,r,x;i<=q;++i){
		scanf("%d%d%d",&t,&l,&r);
		int t1,t2,t3;
//		debug(rt,19);putchar('\n');
		split(rt,t1,t2,l-1,19);
		split(t2,t2,t3,r,19);
		rt=merge(t1,t3,19);
//		debug(t2,19);putchar('\n');
		if(t<=3)scanf("%d",&x);
		if(t==1){
			x^=1048575;
			pushdown(t2,1048575,19);
			solve(t2,19,x);
			for(int i=0;i<20;++i)
				if(x&(1<<i)&&!(val[t2]&(1<<i)))
					pushdown(t2,1<<i,19);
			pushdown(t2,1048575,19);
		}
		else if(t==2){
			solve(t2,19,x);
//		debug(t2,19);putchar('\n');
		}
		else if(t==3){
			pushdown(t2,x,19);
		}
		else{
			printf("%d\n",size[t2]);
		}
		rt=merge(rt,t2,19);
//		debug(rt,19);putchar('\n');
//		putchar('\n');
	}
}