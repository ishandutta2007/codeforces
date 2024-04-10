#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<(x))
#define M 998244353

int i,j,k,n,m,t;
ll f[21][2][2][1050],g[21][2][2][1050],a[21],l,r,p[21][21],sb;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

ll dp2(int dep,int up,int f0,int x){
	if(!dep){return (!x);}
	if(~g[dep][up][f0][x]){return g[dep][up][f0][x];}
	ll res=0;
	for(int i=0;i<=9;i++){
		if(up){
			if(i>a[dep]){continue;}
			if(f0&&!i){res=su(res,dp2(dep-1,i==a[dep],f0,x));}
			else{
				if(!(x&b(i))){continue;}
				res=su(res,dp2(dep-1,i==a[dep],0,x));
				res=su(res,dp2(dep-1,i==a[dep],0,x^b(i)));
			}
		}
		else{
			if(f0&&!i){res=su(res,dp2(dep-1,0,f0,x));}
			else{
				if(!(x&b(i))){continue;}
				res=su(res,dp2(dep-1,0,0,x));
				res=su(res,dp2(dep-1,0,0,x^b(i)));
			}
		}
	}
	return g[dep][up][f0][x]=res;
}

ll dp(int dep,int up,int f0,int x){
	if(!dep){return 0;}
	if(~f[dep][up][f0][x]){return f[dep][up][f0][x];}
	ll res=0;
	for(int i=0;i<=9;i++){
		if(up){
			if(i>a[dep]){continue;}
			if(f0&&!i){res=su(res,(dp(dep-1,i==a[dep],f0,x)+dp2(dep-1,i==a[dep],f0,x)*p[dep-1][i])%M);}
			else{
				if(!(x&b(i))){continue;}
				res=su(res,su(dp(dep-1,i==a[dep],0,x),dp2(dep-1,i==a[dep],0,x)*p[dep-1][i])%M);
				res=su(res,su(dp(dep-1,i==a[dep],0,x^b(i)),dp2(dep-1,i==a[dep],0,x^b(i))*p[dep-1][i]%M));
			}
		}
		else{
			if(f0&&!i){res=su(res,(dp(dep-1,0,f0,x)+dp2(dep-1,0,f0,x)*p[dep-1][i])%M);}
			else{
				if(!(x&b(i))){continue;}
				res=su(res,su(dp(dep-1,0,0,x),dp2(dep-1,0,0,x)*p[dep-1][i])%M);
				res=su(res,su(dp(dep-1,0,0,x^b(i)),dp2(dep-1,0,0,x^b(i))*p[dep-1][i]%M));
			}
		}
	}
	return f[dep][up][f0][x]=res;
}

ll get(ll x){
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	ll res=0;
	for(i=1;i<=18;i++){a[i]=x%10;x/=10;}
	for(i=0;i<1024;i++){
		if(__builtin_popcount(i)>k){continue;}
		res=su(res,dp(18,1,1,i));
	}
	return res;
}

int main(){
	sb=1;for(i=0;i<=20;i++){for(j=1;j<=9;j++){p[i][j]=sb*j%M;}sb=sb*10%M;}
	scanf("%lld%lld%d",&l,&r,&k);
	printf("%lld",su(get(r),M-get(l-1)));
}