#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ls(p) (son[0][p])
#define rs(p) (son[1][p])
#define mid ((l+r)>>1)
using namespace std;
const int maxn=201000;
typedef long long ll;
int n,m;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<1)+(res<<3)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
struct Segment_Tree{
	int rt,ver;
	int son[2][maxn],cnt[20][maxn],tag[maxn];
	long long sum[maxn];
	void update(int p){
		for(register int i=0;i<20;++i)
			cnt[i][p]=cnt[i][ls(p)]+cnt[i][rs(p)];
		sum[p]=sum[ls(p)]+sum[rs(p)];
	}
	void pushtag(int p,int x,int t){
		for(register int i=0;i<20;++i)
			if((x>>i)&1){
				sum[p]+=(t-(cnt[i][p]<<1))*(1ll<<i);
				cnt[i][p]=t-cnt[i][p];
			}
		tag[p]^=x;
	}
	void pushdown(int p,int t){
		if(!tag[p])return;
		pushtag(ls(p),tag[p],t-(t>>1));
		pushtag(rs(p),tag[p],t>>1);
		tag[p]=0;
	}
	void build(int &p,int l,int r){
		p=++ver;tag[p]=0;
		if(l==r){
			sum[p]=read();
			for(register int i=0;i<20;++i)
				cnt[i][p]=(sum[p]>>i)&1;
			return;
		}
		build(ls(p),l,mid);build(rs(p),mid+1,r);
		update(p);
	}
	void modify(int p,int lr,int rr,int x,int l,int r){
		if(lr<=l&&r<=rr){
			pushtag(p,x,r-l+1);return;
		}
		if(l>rr||r<lr)return;
		pushdown(p,r-l+1);
		modify(ls(p),lr,rr,x,l,mid);
		modify(rs(p),lr,rr,x,mid+1,r);
		update(p);
	}
	ll query(int p,int lr,int rr,int l,int r){
		if(lr<=l&&r<=rr)
			return sum[p];
		if(l>rr||r<lr)return 0;
		pushdown(p,r-l+1);
		return query(ls(p),lr,rr,l,mid)+query(rs(p),lr,rr,mid+1,r);
	}
}T;
int main(){
	n=read();
	T.build(T.rt,1,n);
	m=read();
	for(register int i=1,l,r,x;i<=m;++i)
		if(read()==1){
			l=read();r=read();
			printf("%I64d\n",T.query(T.rt,l,r,1,n));
		}
		else{
			l=read();r=read();x=read();
			T.modify(T.rt,l,r,x,1,n);
		}
	return 0;
}