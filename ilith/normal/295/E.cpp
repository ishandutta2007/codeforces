#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define lc ls[k]
#define rc rs[k]
#define se second
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
const int N=200010,inf=1e9+7;
int n,m,a[N],ls[N],rs[N],pri[N];
ll sum[N],res[N],val[N],siz[N];
int tot,rt,l,r,b;
int newnode(int v){
	siz[++tot]=1,val[tot]=sum[tot]=v,pri[tot]=rand();
    return tot;
}
int pup(int k){
	res[k]=sum[rc]*(siz[lc]+1)-(sum[lc]+val[k])*siz[rc]+res[lc]+res[rc]+val[k]*siz[lc]-sum[lc];
	return sum[k]=sum[lc]+sum[rc]+val[k],siz[k]=siz[lc]+siz[rc]+1,k;
}
void split(int k,int &l,int &r,int v){
    if(!k)return void(l=r=0);
    if(val[k]<=v)l=k,split(rc,rc,r,v);
    else r=k,split(lc,l,lc,v);
    pup(k);
}
int merge(int l,int r){
    if(!l||!r)return l^r;
    if(pri[l]<pri[r])return rs[l]=merge(rs[l],r),pup(l);
    return ls[r]=merge(l,ls[r]),pup(r);
}
void ins(int x){split(rt,l,r,x),rt=merge(merge(l,newnode(x)),r);}
void del(int x){split(rt,l,b,x-1),split(b,b,r,x),rt=merge(l,r);}
signed main(){
	read(n);
	for(rgi i=1;i<=n;++i)read(a[i]),ins(a[i]);
	read(m);
	while(m--){
		int opt,x,y;
		read(opt,x,y);
		if(opt==1)del(a[x]),ins(a[x]+=y);
		else split(rt,l,b,x-1),split(b,b,r,y),write(res[b],'\n'),rt=merge(merge(l,b),r);
	}
	return 0;
}