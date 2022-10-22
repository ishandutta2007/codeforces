#include<bits/stdc++.h>
#define rgi register int
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
const int N=100010,M=1050000,B=300;
int n,m,k;
int hd,tl=-1,a[N],bel[N];
struct node{
	int l,r,id;
}q[N];
bool operator<(node a,node b){
	return bel[a.l]==bel[b.l]?a.r<b.r:a.l<b.l;
}
ll res,s[M],ans[N];
inline void ins(int x){
	res+=s[a[x]^k],++s[a[x]];
}
inline void del(int x){
	--s[a[x]],res-=s[a[x]^k];
}
signed main(){
	read(n,m,k);
	for(rgi i=1;i<=n;++i)read(a[i]),a[i]^=a[i-1],bel[i]=i/B;
	for(rgi i=1;i<=m;++i)read(q[i].l,q[i].r),--q[i].l,q[i].id=i;
	sort(q+1,q+m+1);
	for(rgi i=1;i<=m;++i){
		while(hd<q[i].l)del(hd++);
		while(hd>q[i].l)ins(--hd);
		while(tl<q[i].r)ins(++tl);
		while(tl>q[i].r)del(tl--);
		ans[q[i].id]=res;
	}
	for(rgi i=1;i<=m;++i)write(ans[i],'\n');
    return 0;
}