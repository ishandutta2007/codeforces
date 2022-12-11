#include<iostream>
#include<cstdio>
#include<algorithm>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=400100;
typedef long long ll;
int n; 
struct note{
	int op,x;
}q[maxn];
int rk[maxn],rr;
int rt,ver,son[2][maxn];
int tag[maxn],cnt[maxn];
ll sum[maxn][5];
void update(int p){
	cnt[p]=cnt[son[0][p]]+cnt[son[1][p]];
	for(register int i=0;i<5;++i)
		sum[p][i]=sum[son[0][p]][i]+sum[son[1][p]][(i+cnt[son[0][p]])%5];
}
void build(int &p,int l,int r){
	p=++ver;
	if(l==r)return;
	build(son[0][p],l,mid);
	build(son[1][p],mid+1,r);
}
void modify(int p,int x,bool op,int l,int r){
	if(l==r){
		if(!op){
			sum[p][(8-cnt[p]%5)%5]-=rk[l];
			--cnt[p];
		}
		else{
			++cnt[p];
			sum[p][(8-cnt[p]%5)%5]+=rk[l];
		}
		return;
	}
	if(x<=mid)modify(son[0][p],x,op,l,mid);
	else modify(son[1][p],x,op,mid+1,r);
	update(p);
}
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i){
		string op;
		cin>>op;
		if(op[0]=='a')q[i].op=1,rk[++rr]=q[i].x=read();
		else if(op[0]=='d')q[i].op=2,q[i].x=read();
		else q[i].op=3;
	}
	sort(rk+1,rk+1+rr);
	rr=unique(rk+1,rk+1+rr)-rk-1;
	if(rr)build(rt,1,rr);
	for(register int i=1;i<=n;++i){
		if(q[i].op<=2){
			q[i].x=lower_bound(rk+1,rk+1+rr,q[i].x)-rk;
			if(rr)modify(rt,q[i].x,q[i].op&1,1,rr);
		}
		else printf("%I64d\n",sum[rt][0]);
	}
	return 0;
}