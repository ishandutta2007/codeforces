#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int n;
ll k,a[110];
struct Matrix{
	ll v[110][110];
	Matrix(){ memset(v,0,sizeof(v));}
	Matrix operator*(const Matrix &a) const{
		Matrix res;
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				if (v[i][k])
					for (int j=1;j<=n;j++)
						if (a.v[k][j])
							res.v[i][j]=(res.v[i][j]+v[i][k]*a.v[k][j]%Mod)%Mod;
		return res;
	}
} A,B;
int bitcount(ll x){
	int res=0;
	while (x){
		if (x&1) res++;
		x>>=1;
	}
	return res;
}
Matrix qpow(Matrix &x,ll a){
	Matrix res;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			res.v[i][j]=(i==j);
	while (a){
		if (a&1) res=res*x;
		x=x*x; a>>=1;
	}
	return res;
}
int main(){
	scanf("%d%lld",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        	if (bitcount(a[i]^a[j])%3==0) A.v[i][j]=1;
    B=qpow(A,k-1);
    ll ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            ans=(ans+B.v[i][j])%Mod;
    printf("%lld\n",ans);    
	return 0;
}