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
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef pair<int,int> pii;
typedef long long ll;
const int N=500005;
int n,a[N];
vector<ll>sum[705];
inline void update(int x,int y){
	a[x]+=y;
	for(ri i=1;i<=500;++i)sum[i][x%i]+=y;
}
inline ll query(int x,int y){
	ll ret=0;
	for(ri i=y;i<=500000;i+=x)ret+=a[i];
	return ret;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri i=1;i<=700;++i)sum[i].resize(i);
	for(ri tt=read(),op,x,y;tt;--tt){
		op=read(),x=read(),y=read();
		if(op==1)update(x,y);
		else{
			if(x>500)cout<<query(x,y);
			else cout<<sum[x][y];
			puts("");
		}
	}
	return 0;
}