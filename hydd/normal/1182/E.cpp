#include<cstdio> 
#include<cstring>
using namespace std;
const int Mod=1e9+7;
const int Mod1=1e9+6;
typedef long long ll;
ll n,f1,f2,f3,c,x,y,z,w;
struct Matrix{
	ll v[5][5];
	Matrix(){ memset(v,0,sizeof(v));}
	void init(){
		v[1][1]=v[1][2]=v[1][3]=v[2][1]=v[3][2]=1;
	}
	Matrix operator*(const Matrix &a) const{
		Matrix res;
		for (int k=1;k<=3;k++)
			for (int i=1;i<=3;i++)
				if (v[i][k])
					for (int j=1;j<=3;j++)
						if (a.v[k][j])
							res.v[i][j]=(res.v[i][j]+v[i][k]*a.v[k][j]%Mod1)%Mod1;
		return res;
	}
} A,B;
Matrix qpow(Matrix &x,ll a){
	Matrix res;
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			res.v[i][j]=(i==j);
	while (a){
		if (a&1) res=res*x;
		x=x*x; a>>=1;
	}
	return res;
}
ll qpow(ll x,ll a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&n,&f1,&f2,&f3,&c);
	A.init();
	B=qpow(A,n-3);
	x=B.v[1][3]; y=B.v[1][2]; z=B.v[1][1];
	w=((B.v[1][3]%Mod1+B.v[1][2]*2%Mod1+B.v[1][1]*3%Mod1)%Mod1+Mod1-n%Mod1)%Mod1;
	printf("%lld\n",qpow(c,w)*qpow(f1,x)%Mod*qpow(f2,y)%Mod*qpow(f3,z)%Mod);
	return 0;
}