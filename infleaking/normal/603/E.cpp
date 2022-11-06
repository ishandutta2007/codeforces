#include<bits/stdc++.h>
using namespace std; 
const int N=5e5+10;
int fa[N],c[N][2],tr[N],a[N],rev[N],px[N],py[N],sz[N],sum[N];
int cnt,n,m;
#define x1 c[x][0]
#define x2 c[x][1]
int lr(int x){return c[fa[x]][1]==x;}
int isroot(int x){return c[fa[x]][lr(x)]!=x;}
void rever(int x){
	swap(x1,x2);
	rev[x]^=1;
}
void down(int x){
	if (rev[x]){
		rev[x]=0;
		rever(x1);
		rever(x2);
	}
}
int cmax(int x,int y){return a[x]>a[y]?x:y;}
void update(int x){
	tr[x]=cmax(x,cmax(tr[x1],tr[x2]));
	sz[x]=sz[x1]^sz[x2]^sum[x]^(1<=x&&x<=n);
}
void rotate(int x){
	down(fa[x]),down(x);
	int y=fa[x],z=lr(x);
	c[y][z]=c[x][z^1];if (c[y][z])fa[c[y][z]]=y;
	fa[x]=fa[y];if (!isroot(y))c[fa[y]][lr(y)]=x;
	fa[y]=x,c[x][z^1]=y;
	update(y);update(x);
}
void splay(int x){
	while (!isroot(x)){
		if (!isroot(fa[x])){
			if (lr(x)==lr(fa[x]))rotate(fa[x]);
			else rotate(x);
		}rotate(x);
	}
}
void access(int x){
	int x0=x;
	for (int la=0;x;la=x,x=fa[x]){
		splay(x);
		down(x);
		sum[x]^=sz[x2]^sz[la];
		x2=la;
		update(x);
	}splay(x0);
}
void makeroot(int x){
	access(x);
	rever(x);
}
void link(int x,int y){
	makeroot(x);
	makeroot(y);
	assert(!fa[x]);
	sum[x]^=sz[y];
	fa[y]=x;
}
void cut(int x,int y){
	makeroot(x);
	access(x);
	splay(y);
	assert(fa[y]==x);
	sum[x]^=sz[y];
	fa[y]=0;
}
set<pair<int,int> > s;
void del(int i){
	s.erase(make_pair(a[i],i));
	cut(i,px[i]);
	cut(i,py[i]);
}
void ins(int i){
	s.insert(make_pair(a[i],i));
	link(i,px[i]);
	link(i,py[i]);
}
int ina(int x,int y){
	makeroot(x);
	makeroot(y);
	return (bool)fa[x];
}
void go(int x){
	if (!x)return;
	down(x);
	go(x1);
	printf("%d ",x);
	go(x2);
}
void write(){
	for (int i=1;i<=n+m;i++){
		if (isroot(i)){
			printf("%d|",fa[i]);
			go(i);
			cout<<endl;
		}
	}
	cout<<endl;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)update(i);
	cnt=n;
	for (int i=1+n;i<=m+n;i++){
		scanf("%d%d%d",&px[i],&py[i],&a[i]);
		int x=px[i],y=py[i];
		makeroot(x);
		makeroot(y);
		if (fa[x]){
//			makeroot(y);
			access(x);
			if (a[tr[x]]>a[i]){
				del(tr[x]);
				ins(i);
			}
		}
		else {
			if (sz[x]&&sz[y])cnt-=2;
			ins(i);
		}
		while (s.size()&&!cnt){
			int z=s.rbegin()->second;
			makeroot(z);
			access(z);
			splay(px[z]);
			splay(py[z]);
			if (sz[px[z]]||sz[py[z]])break;
			else del(z);
		}
		printf("%d\n",cnt?-1:s.rbegin()->first);
	}
}