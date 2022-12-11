#include<iostream>
#include<cstdio>
#include<vector>
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int maxn=401000;
int n,m;
int no[maxn],id[maxn],col[maxn],siz[maxn],tnt;
vector <int> v[maxn];
int rt,ver,son[2][maxn<<1];
ll cnt[maxn<<1],tag[maxn<<1];
inline int read(){
	int res=0;
	char ch=getchar(),ch2=ch;
	while(!isdigit(ch))ch2=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch2=='-'?-res:res;
}
void dfs(int p,int f){
	no[p]=++tnt;
	id[tnt]=p;
	siz[p]=1;
	for(register int i=0;i<v[p].size();++i)
		if(f!=v[p][i]){
			dfs(v[p][i],p);
			siz[p]+=siz[v[p][i]];
		}
}
void update(int p){
	cnt[p]=cnt[son[0][p]]|cnt[son[1][p]];
}
void pushtag(int p,ll c){
	cnt[p]=tag[p]=c;
}
void pushdown(int p){
	if(tag[p]){
		pushtag(son[0][p],tag[p]);
		pushtag(son[1][p],tag[p]);
		tag[p]=0;
	}
}
void build(int &p,int l,int r){
	p=++ver;
	if(l==r){
		cnt[p]=1ll<<(col[id[l]]-1);
		return;
	}
	build(son[0][p],l,mid);
	build(son[1][p],mid+1,r);
	update(p);
}
void modify(int p,int lr,int rr,int c,int l,int r){
	if(lr<=l&&r<=rr){
		pushtag(p,1ll<<(c-1)); 
		return;
	}
	if(lr>r||l>rr)return;
	pushdown(p);
	modify(son[0][p],lr,rr,c,l,mid);
	modify(son[1][p],lr,rr,c,mid+1,r);
	update(p);
}
ll query(int p,int lr,int rr,int l,int r){
	if(lr<=l&&r<=rr)return cnt[p];
	if(lr>r||l>rr)return 0;
	pushdown(p);
	return query(son[0][p],lr,rr,l,mid)|query(son[1][p],lr,rr,mid+1,r);
}
int countcol(ll x){
	int res=0;
	while(x)++res,x-=x&-x;
	return res;
}
int main(){
	n=read();m=read();
	for(register int i=1;i<=n;++i)
		col[i]=read();
	for(register int i=1,x,y;i<n;++i){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);build(rt,1,n);
	for(register int i=0,x,y;i<m;++i){
		if(read()&1){
			x=read();y=read();
			modify(rt,no[x],no[x]+siz[x]-1,y,1,n);
		}
		else{
			x=read();
			printf("%d\n",countcol(query(rt,no[x],no[x]+siz[x]-1,1,n)));
		}
	}
	return 0;
}