#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const LL inv2=P-P/2;
const int N=3e5+10;
const int INF=1e9;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
void init(){
	return;
}
int n,K,mx=0;
struct Node{
	int sz,lm,rm,mn;
	int ls,rs;
	int len;
}d[(1<<20)+10];
void upd(int id){
	int ls=d[id].ls,rs=d[id].rs;
	if(ls==0) return;
	d[id].sz=d[ls].sz+d[rs].sz;
	d[id].lm=INF;d[id].rm=-INF;d[id].mn=INF;
	if(d[ls].sz>0){
		if(d[id].lm>d[ls].lm)d[id].lm=d[ls].lm;
		if(d[id].rm<d[ls].rm)d[id].rm=d[ls].rm;
		if(d[ls].sz>1&&d[id].mn>d[ls].mn)d[id].mn=d[ls].mn;
	}
	if(d[rs].sz>0){
		if(d[id].lm>d[rs].lm+d[id].len)d[id].lm=d[rs].lm+d[id].len;
		if(d[id].rm<d[rs].rm+d[id].len)d[id].rm=d[rs].rm+d[id].len;
		if(d[rs].sz>1&&d[id].mn>d[rs].mn)d[id].mn=d[rs].mn;
	}
	if(d[ls].sz>0&&d[rs].sz>0){
		d[id].mn=min(d[id].mn,d[rs].lm+d[id].len-d[ls].rm);
	}
	return;
}
void build(int k,int id){
	d[id].sz=0;
	if(k==0){
		d[id].ls=d[id].rs=0;
		return;
	}
	d[id].len=(1<<(k-1));
	d[id].ls=id<<1;
	d[id].rs=id<<1|1;
	build(k-1,d[id].ls);
	build(k-1,d[id].rs);
	return;
}
void ins(int id,int k,int x){
	if(k==0){
		d[id].sz=1;
		d[id].lm=d[id].rm=0;
		d[id].mn=INF;
		return;
	}
	if(x&(1<<(k-1))){
		ins(d[id].rs,k-1,x);
	}
	else{
		ins(d[id].ls,k-1,x);
	}
	//upd(id);
	//cout<<id<<" "<<d[id].sz<<" "<<d[id].lm<<" "<<d[id].rm<<" "<<d[id].mn<<endl;
	return;
}
void change(int id,int k,int x){
	if((1<<(k-1))==x){
		swap(d[id].ls,d[id].rs);
		upd(id);
		return;
	}
	change(d[id].ls,k-1,x);
	change(d[id].rs,k-1,x);
	upd(id);
	return;
}
int q[(1<<20)+10];
int ans[(1<<20)+10];
void MAIN(){
	int x;
	n=read();K=read();
	build(K,1);
	for(int i=1;i<=n;++i){
		x=read();
		ins(1,K,x);
	}
	for(int i=(1<<K)-1;i>=1;--i) upd(i);
	//cout<<d[1].mn<<" "<<d[1].sz<<" "<<d[1].lm<<" "<<d[1].rm<<endl;
	int lim=0;
	q[0]=0;
	for(int j=K-1;j>=0;--j){
		for(int i=lim,k=lim+1;i>=0;--i,++k){
			q[k]=q[i]^(1<<j);
		}
		lim=(lim<<1)|1;
	}
	for(int i=0;i<lim;++i){
		ans[q[i]]=d[1].mn;
		change(1,K,q[i]^q[i+1]);
	}
	ans[q[lim]]=d[1].mn;
	for(int i=0;i<=lim;++i){
		printf("%d ",ans[i]);
	}
	puts("");
	return;
}
int main(){
	init();
	int ttt=1;//ttt=read();
	while(ttt--) MAIN();
	return 0;	
}