#include<iostream>
#include<cstdio>
#include<vector>
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int maxn=201000;
int n;
int no[maxn],id[maxn],col[maxn],siz[maxn],tnt;
vector <int> v[maxn];
int rt,ver,son[2][maxn<<1];
int cnt[maxn<<1],tag[maxn<<1];
inline int read(){
	int res=0;
	char ch=getchar(),ch2=ch;
	while(!isdigit(ch))ch2=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch2=='-'?-res:res;
}
void dfs(int p){
	no[p]=++tnt;
	id[tnt]=p;
	siz[p]=1;
	for(register int i=0;i<v[p].size();++i){
		dfs(v[p][i]);
		siz[p]+=siz[v[p][i]];
	}
}
void update(int p){
	cnt[p]=cnt[son[0][p]]+cnt[son[1][p]];
}
void pushtag(int p,int sz){
	cnt[p]=sz-cnt[p];
	tag[p]^=1;
}
void pushdown(int p,int l,int r){
	if(tag[p]){
		pushtag(son[0][p],mid-l+1);
		pushtag(son[1][p],r-mid);
		tag[p]=0;
	}
}
void build(int &p,int l,int r){
	p=++ver;
	if(l==r){
		cnt[p]=col[id[l]];
		return;
	}
	build(son[0][p],l,mid);
	build(son[1][p],mid+1,r);
	update(p);
}
void modify(int p,int lr,int rr,int l,int r){
	if(lr<=l&&r<=rr){
		pushtag(p,r-l+1); 
		return;
	}
	if(lr>r||l>rr)return;
	pushdown(p,l,r);
	modify(son[0][p],lr,rr,l,mid);
	modify(son[1][p],lr,rr,mid+1,r);
	update(p);
}
ll query(int p,int lr,int rr,int l,int r){
	if(lr<=l&&r<=rr)return cnt[p];
	if(lr>r||l>rr)return 0;
	pushdown(p,l,r);
	return query(son[0][p],lr,rr,l,mid)+query(son[1][p],lr,rr,mid+1,r);
}
int main(){
	n=read();
	for(register int i=2;i<=n;++i)
		v[read()].push_back(i);
	for(register int i=1;i<=n;++i)
		col[i]=read();
	dfs(1);build(rt,1,n);
	for(register int i=read(),x;i;--i){
		string op;cin>>op;
		x=read();
		if(op[0]=='p')
			modify(rt,no[x],no[x]+siz[x]-1,1,n);
		else
			printf("%d\n",query(rt,no[x],no[x]+siz[x]-1,1,n));
	}
	return 0;
}