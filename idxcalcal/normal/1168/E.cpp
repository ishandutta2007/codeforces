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
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=5005;
int k,a[N],n,p[N],q[N],idx[N],vl[N];
inline void fix(int x,int y){
	int k=idx[vl[x]^q[x]];
	if(k==x)return;
	if(k==y){
		swap(idx[p[x]],idx[p[y]]);
		swap(p[x],p[y]);
		return;
	}
	swap(idx[p[x]],idx[p[k]]);
	swap(p[x],p[k]),swap(q[y],q[k]);
	fix(k,y);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=1<<(k=read());
	int ss=0;
	for(ri i=0;i<n;++i)ss^=(a[i]=read()),p[i]=q[i]=idx[i]=i;
	if(ss)return puts("Fou"),0;
	puts("Shi");
	for(ri i=0,dt;i<n-1;++i){
		if(a[i]^vl[i]){
			vl[i+1]^=vl[i]^a[i];
			vl[i]=a[i];
			fix(i,i+1);
		}
	}
	for(ri i=0;i<n;++i)cout<<p[i]<<' ';
	puts("");
	for(ri i=0;i<n;++i)cout<<q[i]<<' ';
	return 0;
}