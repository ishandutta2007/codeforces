#include<iostream>
#include<cstdio>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=501000;
int n;
int rt,ver,son[2][maxn<<1];
int g[maxn<<1];
int cnt;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
void update(int p){
	g[p]=gcd(g[son[0][p]],g[son[1][p]]);
}
void build(int &p,int l,int r){
	p=++ver;
	if(l==r){
		g[p]=read();return;
	}
	build(son[0][p],l,mid);
	build(son[1][p],mid+1,r);
	update(p);
}
void modify(int p,int x,int l,int r){
	if(l==r){
		g[p]=read();return;
	}
	if(x<=mid)modify(son[0][p],x,l,mid);
	else modify(son[1][p],x,mid+1,r);
	update(p);
}
void query(int p,int lr,int rr,int x,int l,int r){
	if(lr>r||l>rr||cnt>1)return;
	if(lr<=l&&r<=rr){
		if(!(g[p]%x))return;
		if(cnt==1){cnt=2;return;}
		if(l==r){cnt=1;return;}
	}
	query(son[0][p],lr,rr,x,l,mid);
	query(son[1][p],lr,rr,x,mid+1,r);
}
int main(){
	n=read();
	build(rt,1,n);
	for(register int q=read(),l,r,x;q;--q){
		if(read()&1){
			//Query
			l=read();r=read();x=read();
			cnt=0;
			query(rt,l,r,x,1,n);
			puts(cnt<=1?"YES":"NO");
		}
		else{
			//Modify
			x=read();
			modify(rt,x,1,n);
		}
	}
	return 0;
}