#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=998244353;
const int Mod=998244352;
map<int,int> mp;
int K,B,n,m;
struct mat{
	ll v[110][110];
	mat operator*(const mat &a){
		mat res;
		for (int i=1;i<=K;i++)
			for (int j=1;j<=K;j++){
				res.v[i][j]=0;
				for (int k=1;k<=K;k++)
					res.v[i][j]=(res.v[i][j]+v[i][k]*a.v[k][j])%Mod;
			}
		return res;
	}
} a;
ll qpow(ll x,ll a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%p;
		x=x*x%p; a>>=1;
	}
	return res;
}
ll bsgs(int x,int y){
	B=sqrt(p)+1;
	int z=qpow(x,B); int m=1;
	for (int a=1;a<=p/B+1;a++){
		m=1ll*m*z%p;
		mp[m]=a;
	}

	for (int b=0;b<B;b++){
		int a=mp[y];
		if (a) return 1ll*a*B-b;
		y=1ll*y*x%p;
	}
	return -1;
}
mat qpow(mat x,ll a){
	mat res;
	for (int i=1;i<=K;i++)
		for (int j=1;j<=K;j++)
			res.v[i][j]=(i==j);
	while (a){
		if (a&1) res=res*x;
		x=x*x; a>>=1;
	}
	return res;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if (!b){
		x=1; y=0;
		return a;
	}
	ll g=exgcd(b,a%b,y,x);
	y-=(a/b)*x; return g;
}
int main(){
	scanf("%d",&K);
	for (int i=1;i<=K;i++) scanf("%lld",&a.v[1][i]);
	for (int i=2;i<=K;i++) a.v[i][i-1]=1;

	scanf("%d%d",&n,&m);
	a=qpow(a,n-K);
	ll tmp=a.v[1][1],t=bsgs(3,m),x,y;
	ll g=exgcd(tmp,Mod,x,y);
	x=(x%Mod+Mod)%Mod;
	if (t%g) puts("-1");
	else{
		t/=g;
		printf("%lld\n",qpow(3,t*x%Mod));
	}
	return 0;
}