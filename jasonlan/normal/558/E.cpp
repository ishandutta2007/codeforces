#include<iostream>
#include<cstdio>
#include<algorithm>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=101000,maxz=221000;
int n,m;
int rt,ver;
int son[2][maxz],cnt[26][maxz],tag[maxz];
int quecnt[26];
char op[maxn];
void update(int p){
	for(register int i=0;i<26;++i)
		cnt[i][p]=cnt[i][son[0][p]]+cnt[i][son[1][p]];
}
void pushtag(int p,int x,int l,int r){
	for(register int i=0;i<26;++i)
		cnt[i][p]=x!=i?0:r-l+1;
	tag[p]=x;
}
void pushdown(int p,int l,int r){
	if(~tag[p]){
		pushtag(son[0][p],tag[p],l,mid);
		pushtag(son[1][p],tag[p],mid+1,r);
		tag[p]=-1;
	}
}
void build(int &p,int l,int r){
	p=++ver;
	tag[p]=-1;
	if(l==r){
		cnt[op[l]-'a'][p]=1;tag[p]=op[l]-'a';return;
	}
	build(son[0][p],l,mid);
	build(son[1][p],mid+1,r);
	update(p);
}
void modify(int p,int lr,int rr,int x,int l,int r){
	if(lr<=l&&r<=rr){
		pushtag(p,x,l,r);return;
	}
	if(lr>r||l>rr)return;
	pushdown(p,l,r);
	modify(son[0][p],lr,rr,x,l,mid);
	modify(son[1][p],lr,rr,x,mid+1,r);
	update(p);
}
void query(int p,int lr,int rr,int l,int r){
	if(lr<=l&&r<=rr){
		for(register int i=0;i<26;++i)
			quecnt[i]+=cnt[i][p];
		return;
	}
	if(lr>r||l>rr)return;
	pushdown(p,l,r);
	query(son[0][p],lr,rr,l,mid);
	query(son[1][p],lr,rr,mid+1,r);
}
void output(int p,int l,int r){
	if(~tag[p]){
		for(register int i=l;i<=r;++i)
			putchar(tag[p]+'a');
		return;
	}
	output(son[0][p],l,mid);
	output(son[1][p],mid+1,r);
}
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int main(){
	n=read();m=read();
	scanf("%s",op+1);
	build(rt,1,n);
	for(register int i=0,l,r,k;i<m;++i){
		l=read();r=read();k=read();
		for(register int j=0;j<26;++j)
			quecnt[j]=0;
		query(rt,l,r,1,n);
		if(k){
			for(register int j=0;j<26;++j){
				if(quecnt[j])
					modify(rt,l,l+quecnt[j]-1,j,1,n);
				l+=quecnt[j];
			}
		}
		else{
			for(register int j=25;~j;--j){
				if(quecnt[j])
					modify(rt,l,l+quecnt[j]-1,j,1,n);
				l+=quecnt[j];
			}
		}
	}
	output(rt,1,n);
	return 0;
}