#include<bits/stdc++.h>
int T,n,m,a[75][75]; bool ok;
std::bitset<525> c1,c2;
struct Num3{
	std::bitset<525> b; int v;
	void clr(){ b.reset();}
	void set(int x,int y){
		b.set(x<<1,y&1);
		b.set(x<<1|1,(y>>1)&1);
	}
	int get(int x){ return b.test(x<<1)+(b.test(x<<1|1)<<1);}
	void add(const Num3 &x){
		std::bitset<525> t=(b&x.b); v=(v+x.v)%3;
		std::bitset<525> u=(t&c1),v=(t&c2);
		b=((u<<1)|(v>>1)|(b^x.b));
		u=((b&(b>>1))&c1); b=(b^(u|(u<<1)));
//		b=(((u<<1)|u)^((v>>1)|v)^(b|x.b));
	}
} r;
void to0(Num3 &a,Num3 &b,int i){
	if (a.get(i)==b.get(i)) a.add(a);
	a.add(b);
}
int Ans[525];
struct Basis{
	Num3 b[525]; bool v[525];
	void init(){
		for (int i=0;i<=m-1;i++){
			b[i].clr();
			v[i]=false; Ans[i]=0;
		}
	}
	void ins(Num3 r){
		for (int i=m-1;i>=0;i--)
			if (r.get(i)){
				if (!v[i]){
					b[i]=r; v[i]=true;
					return;
				}
				to0(r,b[i],i);
			}
		if (r.v) ok=false;
	}
	void work(){
		for (int i=0;i<=m-1;i++)
			if (v[i])
				for (int j=i+1;j<=m-1;j++)
					if (v[j]&&b[j].get(i)) to0(b[j],b[i],i);
		for (int i=0;i<=m-1;i++)
			if (v[i]){
				if (b[i].get(i)==2) b[i].add(b[i]);
				Ans[i]=b[i].v;
			} else Ans[i]=0;
	}
} B;
void upd(int i,int c){
	if (c==-1) return;
	r.clr(); r.set(i,1); r.v=c%3; B.ins(r);
}
void upd(int x,int y,int z){
	if (x==-1||y==-1||z==-1) return;
	r.clr(); r.set(x,1); r.set(y,1); r.set(z,1); r.v=0; B.ins(r);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
//		n=64; m=256;
		c1.reset(); c2.reset();
		for (int i=0;i<m;i++) c1.set(2*i),c2.set(2*i+1);
		ok=true; B.init();
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				a[i][j]=-1;
		int u,v,c;
		for (int i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&c);
//			u=rand()%n+1; v=rand()%(n-1)+1;
//			v+=(v>=u); c=((rand()&1)?-1:rand()%3+1);
			if (u>v) std::swap(u,v);
			a[u][v]=i; upd(i,c);
		}
		for (int u=1;u<=n;u++)
			for (int v=u+1;v<=n;v++)
				for (int w=v+1;w<=n;w++)
					upd(a[u][v],a[v][w],a[u][w]);
		if (!ok){ puts("-1"); continue;}
		B.work();
		for (int i=0;i<m;i++) printf("%d ",(!Ans[i]?3:Ans[i]));
		putchar('\n');
	}
	return 0;
}