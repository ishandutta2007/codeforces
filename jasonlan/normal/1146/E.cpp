#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=201000;
int n,m,rt;
int val[maxn];
int son[2][maxn<<1],tnt;
int cov[maxn<<1];
bool tag[maxn<<1],rev[maxn<<1];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void pushdown(int p){
	if(cov[p]){
		cov[son[0][p]]=cov[son[1][p]]=cov[p];
		tag[son[0][p]]=tag[son[1][p]]=0;
		cov[p]=0;
	}
	if(tag[p]){
		if(cov[son[0][p]])cov[son[0][p]]=-cov[son[0][p]];
		else tag[son[0][p]]^=1;
		if(cov[son[1][p]])cov[son[1][p]]=-cov[son[1][p]];
		else tag[son[1][p]]^=1;
		tag[p]=0;
	}
}
void build(int &p,int l,int r){
	p=++tnt;
	if(l==r){
		cov[p]=l<100001?-1:1;
		return;
	}
	build(son[0][p],l,mid);
	build(son[1][p],mid+1,r);
}
void modify(int p,int lr,int rr,int l,int r){
	if(l>r||lr>r||l>rr)return;
	if(lr<=l&&r<=rr){
		if(cov[p])cov[p]=-cov[p];
		else tag[p]^=1;return;
	}
	pushdown(p);
	modify(son[0][p],lr,rr,l,mid);
	modify(son[1][p],lr,rr,mid+1,r);
}
void cover(int p,int lr,int rr,int x,int l,int r){
	if(l>r||lr>r||l>rr)return;
	if(lr<=l&&r<=rr){
		cov[p]=x;tag[p]=0;return;
	}
	pushdown(p);
	cover(son[0][p],lr,rr,x,l,mid);
	cover(son[1][p],lr,rr,x,mid+1,r);
}
int query(int p,int x,int l,int r){
	if(l==r)return cov[p];
	pushdown(p);
	return x<=mid?query(son[0][p],x,l,mid):query(son[1][p],x,mid+1,r);
}
int main(){
	n=read();m=read();
	for(register int i=1;i<=n;++i)
		val[i]=read();
	build(rt,1,200001);
	for(register int i=1,x;i<=m;++i){
		string s;cin>>s;x=read();
		if(s[0]=='>'){
			if(x<0){
				modify(rt,x+1+100001,-x-1+100001,1,200001);
				x=-x-1;
			}
			cover(rt,x+1+100001,200001,-1,1,200001);
			cover(rt,1,-x-1+100001,-1,1,200001);
		}
		else{
			if(x>0){
				modify(rt,-x+1+100001,x-1+100001,1,200001);
				x=-x+1;
			}
			cover(rt,-x+1+100001,200001,1,1,200001);
			cover(rt,1,x-1+100001,1,1,200001);
		}
	}
	for(register int i=1;i<=n;++i)
		printf("%d ",((query(rt,val[i]+100001,1,200001)<0)^(val[i]<0))?-val[i]:val[i]);
	return 0;
}