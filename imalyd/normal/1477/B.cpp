#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=(a);i<=(b);++i)
#define per(i,a,b) for(i=(a);i>=(b);--i)
#define REP(i,a,b) for(i=(a);i< (b);++i)
#define PER(i,a,b) for(i=(a);i> (b);--i)
typedef long long ll;
#define ERR(...) fprintf(stderr,__VA_ARGS__);

inline void ac();
int main(){
#ifdef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
#endif
	int t;scanf("%d",&t);while(t--)ac();
	return 0;
}
const int MAXN=200005;
char S[MAXN],F[MAXN];
struct seg{int l,r;}A[MAXN];
struct node{
	int l,s,t;
	inline void pt(const int &x){
		if(t=x)s=l;else s=0;
	}
}T[1<<19];
#define ls o<<1  ,l  ,m
#define rs o<<1|1,m+1,r
inline void build(const int &o,const int &l,const int &r){
	T[o].t=-1;T[o].l=r-l+1;
	if(l==r){T[o].s=(F[l]^'0');return;}
	int m=(l+r)>>1;
	build(ls);
	build(rs);
	T[o].s=T[o<<1].s+T[o<<1|1].s;
}
inline void pd(const int &o){
	if(~T[o].t){
		T[o<<1  ].pt(T[o].t);
		T[o<<1|1].pt(T[o].t);
		T[o].t=-1;
	}
}
int L,R,x;
inline void upd(const int &o,const int &l,const int &r){
	if(L<=l&&r<=R){T[o].pt(x);return;}
	pd(o);
	int m=(l+r)>>1;
	if(L<=m)upd(ls);
	if(R> m)upd(rs);
	T[o].s=T[o<<1].s+T[o<<1|1].s;
}
inline void que(const int &o,const int &l,const int &r){
	if(L<=l&&r<=R){x+=T[o].s;return;}
	pd(o);
	int m=(l+r)>>1;
	if(L<=m)que(ls);
	if(R> m)que(rs);
}
inline void chk(const int &o,const int &l,const int &r){
	if(l==r){if(T[o].s!=(S[l]^'0'))x=1;return;}
	pd(o);
	int m=(l+r)>>1;
	chk(ls);
	chk(rs);
}
inline void ac(){
	int n,q,i,e;
	scanf("%d%d%s%s",&n,&q,S+1,F+1);
	rep(i,1,q)scanf("%d%d",&A[i].l,&A[i].r);
	build(1,1,n);
	per(i,q,1){
		L=A[i].l;R=A[i].r;x=0;
		que(1,1,n);
		e=R-L+1;
		//ERR("Q #%d [%d,%d] e=%d x=%d\n",i,L,R,e,x);
		if((x<<1)==e){puts("NO");return;}
		x=((x<<1)> e);
		upd(1,1,n);
		//dbg(1,1,n);
	}
	x=0;
	chk(1,1,n);
	if(x)puts("NO");else puts("YES");
}