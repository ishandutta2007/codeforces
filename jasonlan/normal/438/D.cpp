#include<iostream>
#include<cstdio>
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int maxn=101000;
int n,m;
int rt,ver,son[2][maxn<<1],maxi[maxn<<1];
ll sum[maxn<<1];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void update(int p){
	sum[p]=sum[son[0][p]]+sum[son[1][p]];
	maxi[p]=max(maxi[son[0][p]],maxi[son[1][p]]);
}
void build(int &p,int l,int r){
	p=++ver;
	if(l==r){
		sum[p]=maxi[p]=read();
		return;
	}
	build(son[0][p],l,mid);
	build(son[1][p],mid+1,r);
	update(p);
}
void modify(int p,int lr,int rr,int l,int r,int x){
	if(x>maxi[p]||lr>r||l>rr)return;
	if(l==r){
		sum[p]=maxi[p]=sum[p]%x;
		return;
	}
	modify(son[0][p],lr,rr,l,mid,x);
	modify(son[1][p],lr,rr,mid+1,r,x);
	update(p);
}
void cover(int p,int pos,int l,int r){
	if(l==r){
		sum[p]=maxi[p]=read();
		return;
	}
	if(pos<=mid)cover(son[0][p],pos,l,mid);
	else cover(son[1][p],pos,mid+1,r);
	update(p);
}
ll query(int p,int lr,int rr,int l,int r){
	if(lr<=l&&r<=rr)return sum[p];
	if(lr>r||l>rr)return 0ll;
	return query(son[0][p],lr,rr,l,mid)+query(son[1][p],lr,rr,mid+1,r); 
}
int main(){
	n=read();m=read();
	build(rt,1,n);
	for(register int i=0,op,l,r,x;i<m;++i){
		op=read();
		if(op==1){
			l=read();r=read();
			printf("%lld\n",query(rt,l,r,1,n));
		}
		else if(op==2){
			l=read();r=read();x=read();
			modify(rt,l,r,1,n,x);
		}
		else
			cover(rt,read(),1,n);
	}
	return 0;
}