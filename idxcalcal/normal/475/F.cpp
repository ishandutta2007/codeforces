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
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef pair<int,int> pii;
set<pii>X,Y;
typedef set<pii>::iterator It;
typedef set<pii>::reverse_iterator IT;
int n;
inline pii rev(pii x){return pii(x.se,x.fi);}
inline void split(set<pii>&a,set<pii>&b,set<pii>&_a,set<pii>&_b,pii vl){
	a.erase(vl),_a.insert(vl);
	vl=rev(vl);
	b.erase(vl),_b.insert(vl);
}
int solve(set<pii>&vlx,set<pii>&vly){
	if(vlx.size()==1)return 1;
	It fx=vlx.begin();
	IT bx=vlx.rbegin();
	It fy=vly.begin();
	IT by=vly.rbegin();
	int t;
	set<pii>_vlx,_vly;
	do{
		t=fx->fi,++fx;
		if(fx->fi>t+1){
			while(vlx.begin()->fi<=t)split(vlx,vly,_vlx,_vly,*vlx.begin());
			return solve(_vlx,_vly)+solve(vlx,vly);
		}
		t=bx->fi,++bx;
		if(bx->fi<t-1){
			while(t<=vlx.rbegin()->fi)split(vlx,vly,_vlx,_vly,*vlx.rbegin());
			return solve(vlx,vly)+solve(_vlx,_vly);
		}
		t=fy->fi,++fy;
		if(fy->fi>t+1){
			while(vly.begin()->fi<=t)split(vly,vlx,_vly,_vlx,*vly.begin());
			return solve(_vlx,_vly)+solve(vlx,vly);
		}
		t=by->fi,++by;
		if(by->fi<t-1){
			while(t<=vly.rbegin()->fi)split(vly,vlx,_vly,_vlx,*vly.rbegin());
			return solve(vlx,vly)+solve(_vlx,_vly);
		}
	}while(*fx<*bx);
	return 1;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri x,y,i=1;i<=n;++i){
		x=read(),y=read();
		X.insert(pii(x,y));
		Y.insert(pii(y,x));
	}
	cout<<solve(X,Y);
	return 0;
}