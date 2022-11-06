#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline int Read(bool*a){
	int top=0;
	char ch=gc();
	while(ch!='X'&&ch!='.')ch=gc();
	while(ch=='X'||ch=='.')a[++top]=ch=='X',ch=gc();
	return top;
}
typedef pair<int,int> pii;
const int N=2005;
int n,m,k;
bool s[N][N];
int L[N<<2][N],R[N<<2][N],mx[N<<2];
#define lc (p<<1)
#define rc (p<<1|1)
#define mid (l+r>>1)
inline int calc(int*L,int*R){
	static int q1[N],q2[N],hd1,hd2,tl1,tl2;
	int res=0,l=1,r=1;
	q1[hd1=tl1=1]=1;
	q2[hd2=tl2=1]=1;
	res=max(res,min(1,L[1]+R[1]));
	for(ri l=1,r=2;r<=n;++r){
		while(hd1<=tl1&&L[q1[tl1]]>=L[r])--tl1;
		q1[++tl1]=r;
		while(hd2<=tl2&&R[q2[tl2]]>=R[r])--tl2;
		q2[++tl2]=r;
		while(l<=r&&r-l+1>(L[q1[hd1]]+R[q2[hd2]])){
			res=max(res,L[q1[hd1]]+R[q2[hd2]]);
			++l;
			if(l>q1[hd1])++hd1;
			if(l>q2[hd2])++hd2;
		}
		res=max(res,r-l+1);
	}
	return res;
}
inline void build(int p,int l,int r){
	if(l==r){
		for(ri i=1;i<=n;++i)if(!s[i][l]){mx[p]=1;return;}
		return;
	}
	for(ri t,x,i=1;i<=n;++i){
		x=0,t=mid;
		while(l<=t&&!s[i][t])++x,--t;
		L[p][i]=x;
		x=0,t=mid+1;
		while(t<=r&&!s[i][t])++x,++t;
		R[p][i]=x;
	}
	build(lc,l,mid),build(rc,mid+1,r);
	mx[p]=max(mx[lc],mx[rc]);
	mx[p]=max(mx[p],calc(L[p],R[p]));
}
inline void update(int p,int l,int r,int a,int b){
	if(l==r){
		mx[p]=0;
		for(ri i=1;i<=n;++i)if(!s[i][l]){mx[p]=1;return;}
		return;		
	}
	int t,x;
	if(b<=mid){
		x=0,t=mid;
		while(l<=t&&!s[a][t])++x,--t;
		L[p][a]=x;
	}
	else{
		x=0,t=mid+1;
		while(t<=r&&!s[a][t])++x,++t;
		R[p][a]=x;
	}
	b<=mid?update(lc,l,mid,a,b):update(rc,mid+1,r,a,b);
	mx[p]=max(mx[lc],mx[rc]);
	mx[p]=max(mx[p],calc(L[p],R[p]));
}
#undef lc
#undef rc
#undef mid
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read(),k=read();
	for(ri i=1;i<=n;++i)Read(s[i]);
	build(1,1,m);
	for(ri a,b,i=1;i<=k;++i){
		a=read(),b=read();
		s[a][b]=1;
		update(1,1,m,a,b);
		cout<<mx[1]<<'\n';
	}
	return 0;
}