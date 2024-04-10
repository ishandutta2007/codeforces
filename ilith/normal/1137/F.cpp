#include<bits/stdc++.h>
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T& A,Ts&... As){write(A),putchar(' '),write(As...);}
struct node
{
	node*ch[2],*fa;
	int sz,vl;bool rev;
	inline bool rt(){return !fa||(fa->ch[0]!=this&&fa->ch[1]!=this);}
	inline void res()
	{
		rev^=1;swap(ch[0],ch[1]);
	}
	inline void pd()
	{
		if(rev)
		{
			if(ch[0])ch[0]->res();
			if(ch[1])ch[1]->res();
			rev=0;
		}if(ch[0])ch[0]->vl=vl;
		if(ch[1])ch[1]->vl=vl;
	}
	void pda()
	{
		if(!rt())fa->pda();
		pd();
	}
	inline void rotate()
	{
		bool k=fa->ch[1]==this;
		node*x=fa,*y=x->fa;
		fa=x->fa;if(!x->rt())y->ch[y->ch[1]==x]=this;
		sz=x->sz;x->sz-=(ch[k]?ch[k]->sz:0)+1;
		x->ch[k]=ch[!k];if(ch[!k])ch[!k]->fa=x;
		ch[!k]=x;x->fa=this;
	}
	void splay()
	{
		pda();
		while(!rt())
		{
			if(!fa->rt()){(fa->ch[1]==this)==(fa->fa->ch[1]==fa)?fa->rotate():rotate();}
			rotate();
		}
	}
}nd[500100];
int col[1000100],n,q,nm,cnt,no[500100];
void add(int a,int ad){for(;a<=n+q;a+=a&-a)col[a]+=ad;}
int sum(int a){int sm=0;for(;a;a^=a&-a)sm+=col[a];return sm;}
void access(int a){
	node*x=nd+a,*y=0;
	for(;x;y=x,x=x->fa){
		x->splay();
		if(x->ch[1])x->sz-=x->ch[1]->sz;
		add(x->vl,-x->sz);
		x->ch[1]=y;if(y)x->sz+=y->sz,y->fa=x;
	}
}
void makeroot(int a){
	node*x=nd+a;
	access(a);x->splay();x->res();
}
void mdf(int a){
	makeroot(a);nd[a].vl=++nm;add(nm,nd[a].sz);
}
int qus(int a)
{
	node*x=nd+a;
	x->splay();
	return sum(x->vl-1)+(x->ch[1]?x->ch[1]->sz:0)+1;
}
struct edge{int to;edge*nx;}e[1000100],*cct=e,*la[500100];
inline void addE(int a,int b){
	*++cct=(edge){b,la[a]};la[a]=cct;
	*++cct=(edge){a,la[b]};la[b]=cct;
}
void dfs(int a,int ff){
	nd[a].sz=1;nd[a].vl=no[a];add(no[a],1);
	for(edge*i=la[a];i;i=i->nx)if(i->to!=ff)
	{nd[i->to].fa=nd+a;
		dfs(i->to,a);
	}
}
int d[500100],qq[500100],q1;
inline bool cmp(int a,int b){return a>b;}
int x,y;
char c[10];
int main(){
	read(n,q);
	for(int i=1;i<n;i++){
		read(x,y);
		addE(x,y);d[x]++;d[y]++;
	}
	for(int i=1;i<=n;i++)if(d[i]==1)qq[++q1]=i;
	make_heap(qq+1,qq+q1+1,cmp);
	for(int i=1;i<=n;i++){
		x=qq[1];
		pop_heap(qq+1,qq+q1+1,cmp);
		q1--;
		no[x]=i;
		for(edge*ii=la[x];ii;ii=ii->nx){
			d[ii->to]--;
			if(d[ii->to]==1)qq[++q1]=ii->to,push_heap(qq+1,qq+q1+1,cmp);
		}
	}
	dfs(n,0);nm=n;
	for(int i=1;i<=q;i++){scanf("\n%s",c);
		read(x);
		if(c[0]=='u')mdf(x);
		else if(c[0]=='w')printf("%d\n",qus(x));
		else read(y),printf("%d\n",qus(x)>qus(y)?y:x);
	}
}