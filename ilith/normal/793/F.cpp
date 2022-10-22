#include<bits/stdc++.h>
#define rgi register int
#define pii pair<int,int>
#define fi first
#define se second
#define lc k<<1
#define rc k<<1|1
#define lson lc,l,mid
#define rson rc,mid+1,r
#define mid (l+r>>1)
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=100010;
int n,m,Q,x,y;
int rp[N],ans[N];
vector<pii>q[N];
int ma[N<<2],se[N<<2],tag[N<<2];
inline void pdown(int k){
	if(!tag[k])return;
	if(ma[lc]>se[k])ma[lc]=tag[lc]=tag[k];
	if(ma[rc]>se[k])ma[rc]=tag[rc]=tag[k];
	tag[k]=0;
}
inline void pup(int k){
	ma[k]=max(ma[lc],ma[rc]),se[k]=max(se[lc],se[rc]);
	if(ma[lc]!=ma[rc])se[k]=max(se[k],min(ma[lc],ma[rc]));
}
void upd(int x,int y,int vx,int vy,int k=1,int l=1,int r=n){
	if(vx>ma[k]||l>y||r<x)return;
	if(l>=x&&r<=y&&vx>se[k])return void(ma[k]=tag[k]=vy);
	pdown(k),upd(x,y,vx,vy,lson),upd(x,y,vx,vy,rson),pup(k);
}
int qry(int x,int k=1,int l=1,int r=n){
	if(l>x||r<x)return 0;
	if(l==r)return ma[k];
	return pdown(k),qry(x,lson)+qry(x,rson);
}
signed main(){
	read(n,m),memset(se,-1,sizeof se);
	for(rgi i=1;i<=m;++i)read(x,y),rp[y]=x;
	read(Q);
	for(rgi i=1;i<=Q;++i)read(x,y),q[y].push_back(pii(x,i));
	for(rgi i=1;i<=n;++i){
		upd(i,i,0,i);
		if(rp[i])upd(1,rp[i],rp[i],i);
		for(pii k:q[i])ans[k.se]=qry(k.fi);
	}
	for(rgi i=1;i<=Q;++i)write(ans[i],'\n');
	return 0;
}