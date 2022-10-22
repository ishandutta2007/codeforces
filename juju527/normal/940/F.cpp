#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,maxm=100005,maxw=200005;
int base;
struct query{
	int id;
	int x,y,t;
	bool operator <(query i)const{
		return x/base==i.x/base?(y/base==i.y/base?t<i.t:y<i.y):x<i.x;
	}
}q[maxm];
struct node{
	int id,s;
	bool operator <(node i)const{
		return s<i.s;
	}
}b[maxn+maxm];
int c[maxn];
int a[maxm][2];
int l,r,p;
int ans=0;
int ANS[maxm];
int cnt[maxw];
int st[maxn];
bool vis[maxm];
inline int read(){
	register int x=0,y=1;
	register char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
inline void write(register int x){
	if(!x)return ;
	write(x/10);
	putchar(x%10+'0');
	return ;
}
inline void ins(register int x){
	st[cnt[c[x]]]--;
	cnt[c[x]]++;
	st[cnt[c[x]]]++;
	return ;
}
inline void del(register int x){
	st[cnt[c[x]]]--;
	cnt[c[x]]--;
	st[cnt[c[x]]]++;
	return ;
}
inline void change(register int x){
	if(a[x][0]>=l&&a[x][0]<=r)del(a[x][0]);
	swap(c[a[x][0]],a[x][1]);
	if(a[x][0]>=l&&a[x][0]<=r)ins(a[x][0]);
	return ;
}
int main(){
	register int n,m;
	n=read();m=read();
	base=pow(n,0.66666);
	for(register int i=1;i<=n;i++){
		b[i].id=i;
		b[i].s=read();
	}
	register int tot=0,tim=0;
	for(register int i=1;i<=m;i++){
		register int opt,x,y;
		opt=read();x=read();y=read();
		if(opt==1){
			tot++;
			vis[i]=1;
			q[tot].id=i;
			q[tot].x=x;
			q[tot].y=y;
			q[tot].t=tim;
		}
		else{
			tim++;
			a[tim][0]=x;
			b[tim+n].id=tim+n;
			b[tim+n].s=y;
		}
	}
	sort(b+1,b+n+tim+1);
	int w=0;
	for(int i=1;i<=n+tim;i++){
		if(b[i].s>b[i-1].s)w++;
		if(b[i].id<=n)c[b[i].id]=w;
		else a[b[i].id-n][1]=w;
	}
	sort(q+1,q+tot+1);
	l=1;r=0;p=0;
	for(register int i=1;i<=tot;i++){
		int x=q[i].x,y=q[i].y,t=q[i].t;
		while(l>x)ins(--l);
		while(r<y)ins(++r);
		while(l<x)del(l++);
        while(r>y)del(r--);
		while(p<t)change(++p);
		while(p>t)change(p--);
		ans=0;
		while(st[ans+1])ans++;//
		ANS[q[i].id]=ans+1;
	}
	for(register int i=1;i<=m;i++){
		if(!vis[i])continue;
		write(ANS[i]);
		if(!ANS[i])putchar('0');
		putchar('\n');
	}
	return 0;
}