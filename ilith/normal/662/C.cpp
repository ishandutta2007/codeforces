#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using ll=long long;
#define d (l+r>>1)
const int N=1.1e6;
void c(ll& x,ll& y,int w){
	x+=y,y=x-y-y;
	if(w)x/=2,y/=2;
}
void fwt(ll *f,int l,int r,int w){
	if(l!=r){
		fwt(f,l,d,w),fwt(f,d+1,r,w);
		FOR(i,l,d)c(f[i],f[i-l+d+1],w);
	}
}
int n,m,a[N],S;
ll s[N],b[N],ans;
char ch;
signed main(){
	scanf("%d%d",&n,&m),S=(1<<n)-1;
	FOR(i,0,n-1){
		while(!isdigit(ch))ch=getchar();
		FOR(j,1,m)a[j]+=(ch&1)<<i,ch=getchar();
	}
	FOR(i,1,m)++i[a][s];
	FOR(i,0,S)m=__builtin_popcount(i),b[i]=std::min(m,n-m);
	fwt(s,0,S,0),fwt(b,0,S,0);
	FOR(i,0,S)s[i]*=b[i];
	fwt(s,0,S,1),ans=s[0];
	FOR(i,1,S)ans=std::min(ans,s[i]);
	printf("%lld",ans);
}