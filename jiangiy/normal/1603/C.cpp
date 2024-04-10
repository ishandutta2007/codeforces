#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100010,M=320,P=998244353;
int n,s[N],u[M*2+10];
PI a[M*2+10],b[M*2+10];
PI f[M*2+10],g[M*2+10];
int gen(int x,PI*f){
	int c=0;
	int v=sqrtl(x);
	if(v*v<x)v++;
	for(int i=1;i<=v;i++){
		f[++c]=MP(i,(x+i-1)/i-1);
		u[c]=x%i==0?i:i-1;
	}
	v--;
	for(int i=v;i;i--){
		int t=(x+i-1)/i;
		f[++c]=MP(t,i-1);
		u[c]=x%i==0?t:t-1;
	}
	return c;
}
PI add(PI a,PI b){
	return MP((a.fi+b.fi)%P,(a.se+b.se)%P);
}
PI addv(PI a,int x){
	return MP(int((a.fi+(LL)a.se*x)%P),a.se);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		int ac=gen(s[n],a);
		for(int i=1;i<=ac;i++)a[i].fi=u[i];
		for(int i=1;i<=ac;i++)f[i]=MP(0,0);
		f[ac]=MP(0,1);
		LL ans=0;
		for(int i=n-1;i;i--){
			int bc=gen(s[i],b),k=1;
			for(int j=1;j<=bc;j++)g[j]=MP(0,0);
			for(int j=1;j<=ac;j++){
				for(;k<bc&&b[k+1].fi<=a[j].fi;k++);
				g[k]=add(g[k],f[j]);
			}
			for(int j=1;j<=bc;j++){
				a[j]=MP(u[j],b[j].se);
				f[j]=addv(g[j],b[j].se);
				ans+=f[j].fi;
			}
			ans%=P;
			ac=bc;
			f[ac].se++;
		}
		printf("%lld\n",ans%P);
	}
}