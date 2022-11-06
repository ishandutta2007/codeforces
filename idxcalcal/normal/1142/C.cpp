#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef long long ll;
const int N=1e5+5;
struct pot{
	ll x,y;
	pot(ll x=0,ll y=0):x(x),y(y){}
	friend inline pot operator+(const pot&a,const pot&b){return pot(a.x+b.x,a.y+b.y);}
	friend inline pot operator-(const pot&a,const pot&b){return pot(a.x-b.x,a.y-b.y);}
	friend inline ll operator^(const pot&a,const pot&b){return a.x*b.y-a.y*b.x;}
	friend inline bool operator<(const pot&a,const pot&b){return a.x^b.x?a.x<b.x:a.y<b.y;}
}a[N];
inline int graham(pot*a,int n){
	static int top=0,q[N];
	sort(a+1,a+n+1);
	for(ri i=1;i<=n;++i){
		if(a[i].x==a[q[top]].x)--top;
		while(top>1&&((a[i]-a[q[top]])^(a[q[top]]-a[q[top-1]]))<=0)--top;
		q[++top]=i;
	}
	n=0;
	for(ri i=1;i<=top;++i)a[++n]=a[q[i]];
	return n;
}
int n;
int main(){
	n=read();
	for(ri i=1,x,y;i<=n;++i){
		x=read(),y=read();
		a[i]=pot(x,(ll)y-(ll)x*x);
	}
	cout<<graham(a,n)-1;
	return 0;
}