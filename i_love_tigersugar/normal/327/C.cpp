#include<cstdio>
#include<cstring>
#define MAX   100100
typedef long long ll;
const ll mod=1e9+7;
ll pw[MAX];
char s[MAX];
int n,k;
void finit(void) {
	int i;
	pw[0]=1;
	for (i=1;i<=100007;i=i+1) pw[i]=(pw[i-1]*2)%mod;	
}
struct matrix {
	int m,n;
	ll d[5][5];
	matrix(){}
	matrix operator * (const matrix &a) {
		int x=m;
		int y=n;
		int z=a.n;
		matrix res;
		res.m=x;
		res.n=z;
		int i,j,k;
		for (i=0;i<x;i=i+1)
			for (j=0;j<z;j=j+1) {
				res.d[i][j]=0;
				for (k=0;k<y;k=k+1)
					res.d[i][j]=(res.d[i][j]+d[i][k]*a.d[k][j])%mod;
			}				
		return (res);		
	}
	matrix operator ^ (const int &k) {
		if (k==1) return (*this);
		matrix r=(*this)^(k/2);
		r=r*r;
		if (k%2==1) r=r*(*this);
		return (r);
	}
};
ll sum(const ll &a,const int &k) {
	matrix fst,mul;
	fst.m=1;
	fst.n=2;
	fst.d[0][0]=1;
	fst.d[0][1]=1;
	mul.m=2;
	mul.n=2;
	mul.d[0][0]=a%mod;
	mul.d[0][1]=a%mod;
	mul.d[1][0]=0;
	mul.d[1][1]=1;
	if (k>0) fst=fst*(mul^k);
	return (fst.d[0][1]%mod);
}
void process(void) {
	scanf("%s",s);
	n=strlen(s);
	scanf("%d",&k);
	ll mul=sum(pw[n],k-1);
	ll res=0;
	int i;
	for (i=0;i<n;i=i+1)
		if (s[i]=='0' || s[i]=='5') res=(res+pw[i]*mul)%mod;
	printf("%I64d",res%mod);
}
int main(void) {
	finit();
	process();
	return 0;
}