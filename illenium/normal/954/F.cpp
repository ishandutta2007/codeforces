#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 100010
using namespace std;

struct matrix
{
	int a[4][4];
	matrix(){memset(a,0,sizeof(a));}
	matrix operator*(const matrix& ma)const
	{
		matrix ret;
		for(int i=1;i<=3;++i)
			for(int j=1;j<=3;++j)
				for(int k=1;k<=3;++k)
					ret.a[i][j]=(ret.a[i][j]+1ll*a[i][k]*ma.a[k][j])%mod;
		return ret;
	}
}A;

typedef long long ll;
long long n,m,a[maxn],l[maxn],r[maxn],lsh[maxn],tp;
int tg[maxn][4];

int main()
{
	//freopen("CF954F.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%lld%lld",&a[i],&l[i],&r[i]);
		lsh[++tp]=l[i],lsh[++tp]=r[i]+1;
	}
	lsh[++tp]=2,lsh[++tp]=m+1;
	sort(lsh+1,lsh+tp+1);
	tp=unique(lsh+1,lsh+tp+1)-lsh-1;
	for(int i=1;i<=n;++i)
	{
		l[i]=lower_bound(lsh+1,lsh+tp+1,l[i])-lsh;
		r[i]=lower_bound(lsh+1,lsh+tp+1,r[i]+1)-lsh;
		tg[l[i]][a[i]]++,tg[r[i]][a[i]]--;
	}
	for(int i=1;i<=3;++i) A.a[i][i]=1;
	for(int i=1;i<tp;++i)
	{
		for(int j=1;j<=3;++j) tg[0][j]+=tg[i][j];
		matrix I;
		for(int j=1;j<=3;++j)
			for(int k=max(1,j-1);k<=min(3,j+1);++k)if(!tg[0][k])
				I.a[j][k]=1;
		ll len=lsh[i+1]-lsh[i];
		for(;len;len>>=1,I=I*I) if(len&1)A=A*I;
	}
	printf("%d",A.a[2][2]);
}